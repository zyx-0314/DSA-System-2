#include "employee_management.h"

void EmployeeManagement::updateEmployee() {
    int id;
    cout << "Enter Employee ID to update: ";
    cin >> id;

    ifstream inFile("employees.txt");
    if (!inFile) {
        cout << "Unable to open file for reading." << endl;
        return;
    }

    vector<Employee> employees;
    Employee emp;
    while (inFile >> emp.id >> ws) {
        getline(inFile, emp.name, '\t');
        getline(inFile, emp.position, '\t');
        employees.push_back(emp);
    }
    inFile.close();

    bool found = false;
    for (auto &e : employees) {
        if (e.id == id) {
            found = true;
            cout << "Enter new Employee Name: ";
            cin.ignore();
            getline(cin, e.name);
            cout << "Enter new Employee Position: ";
            getline(cin, e.position);
            break;
        }
    }

    if (!found) {
        cout << "Employee ID not found." << endl;
        return;
    }

    ofstream outFile("employees.txt");
    if (!outFile) {
        cout << "Unable to open file for writing." << endl;
        return;
    }

    for (const auto &e : employees) {
        outFile << e.id << "\t" << e.name << "\t" << e.position << endl;
    }
    outFile.close();
    cout << "Employee record updated successfully." << endl;
}

void EmployeeManagement::deleteEmployee() {
    int id;
    cout << "Enter Employee ID to delete: ";
    cin >> id;

    ifstream inFile("employees.txt");
    if (!inFile) {
        cout << "Unable to open file for reading." << endl;
        return;
    }

    vector<Employee> employees;
    Employee emp;
    while (inFile >> emp.id >> ws) {
        getline(inFile, emp.name, '\t');
        getline(inFile, emp.position, '\t');
        employees.push_back(emp);
    }
    inFile.close();

    bool found = false;
    vector<Employee>::iterator it;
    for (it = employees.begin(); it != employees.end(); ++it) {
        if (it->id == id) {
            found = true;
            employees.erase(it);
            break;
        }
    }

    if (!found) {
        cout << "Employee ID not found." << endl;
        return;
    }

    ofstream outFile("employees.txt");
    if (!outFile) {
        cout << "Unable to open file for writing." << endl;
        return;
    }

    for (const auto &e : employees) {
        outFile << e.id << "\t" << e.name << "\t" << e.position << endl;
    }
    outFile.close();
    cout << "Employee record deleted successfully." << endl;
}

void EmployeeManagement::displayAllEmployees() {
    ifstream inFile("employees.txt");
    if (!inFile) {
        cout << "Unable to open file for reading." << endl;
        return;
    }

    Employee emp;
    cout << "Employee Records:" << endl;
    while (inFile >> emp.id >> ws) {
        getline(inFile, emp.name, '\t');
        getline(inFile, emp.position, '\t');
        cout << "ID: " << emp.id << ", Name: " << emp.name << ", Position: " << emp.position << endl;
    }
    inFile.close();
}

void EmployeeManagement::addAttendance() {
    ofstream outFile("attendance.txt", ios::app);
    if (!outFile) {
        cout << "Unable to open file for writing." << endl;
        return;
    }

    Attendance att;
    cout << "Enter Employee ID: ";
    cin >> att.empId;
    cin.ignore();
    cout << "Enter Date (YYYY-MM-DD): ";
    getline(cin, att.date);
    cout << "Enter Time In (HH:MM): ";
    getline(cin, att.timeIn);
    cout << "Enter Time Out (HH:MM): ";
    getline(cin, att.timeOut);

    outFile << att.empId << "\t" << att.date << "\t" << att.timeIn << "\t" << att.timeOut << endl;
    outFile.close();
    cout << "Attendance record added successfully." << endl;
}

void EmployeeManagement::updateAttendance() {
    int empId;
    string date;
    cout << "Enter Employee ID and Date (YYYY-MM-DD) to update: ";
    cin >> empId >> ws;
    getline(cin, date);

    ifstream inFile("attendance.txt");
    if (!inFile) {
        cout << "Unable to open file for reading." << endl;
        return;
    }

    vector<Attendance> attendances;
    Attendance att;
    while (inFile >> att.empId >> ws) {
        getline(inFile, att.date, '\t');
        getline(inFile, att.timeIn, '\t');
        getline(inFile, att.timeOut, '\t');
        attendances.push_back(att);
    }
    inFile.close();

    bool found = false;
    for (auto &a : attendances) {
        if (a.empId == empId && a.date == date) {
            found = true;
            cout << "Enter new Time In (HH:MM): ";
            getline(cin, a.timeIn);
            cout << "Enter new Time Out (HH:MM): ";
            getline(cin, a.timeOut);
            break;
        }
    }

    if (!found) {
        cout << "Attendance record not found." << endl;
        return;
    }

    ofstream outFile("attendance.txt");
    if (!outFile) {
        cout << "Unable to open file for writing." << endl;
        return;
    }

    for (const auto &a : attendances) {
        outFile << a.empId << "\t" << a.date << "\t" << a.timeIn << "\t" << a.timeOut << endl;
    }
    outFile.close();
    cout << "Attendance record updated successfully." << endl;
}

void EmployeeManagement::displayAttendance() {
    ifstream inFile("attendance.txt");
    if (!inFile) {
        cout << "Unable to open file for reading." << endl;
        return;
    }

    Attendance att;
    cout << "Attendance Records:" << endl;
    while (inFile >> att.empId >> ws) {
        getline(inFile, att.date, '\t');
        getline(inFile, att.timeIn, '\t');
        getline(inFile, att.timeOut, '\t');
        cout << "Employee ID: " << att.empId << ", Date: " << att.date << ", Time In: " << att.timeIn << ", Time Out: " << att.timeOut << endl;
    }
    inFile.close();
}

void EmployeeManagement::deleteAttendance() {
    int empId;
    string date;
    cout << "Enter Employee ID and Date (YYYY-MM-DD) to delete: ";
    cin >> empId >> ws;
    getline(cin, date);

    ifstream inFile("attendance.txt");
    if (!inFile) {
        cout << "Unable to open file for reading." << endl;
        return;
    }

    vector<Attendance> attendances;
    Attendance att;
    while (inFile >> att.empId >> ws) {
        getline(inFile, att.date, '\t');
        getline(inFile, att.timeIn, '\t');
        getline(inFile, att.timeOut, '\t');
        attendances.push_back(att);
    }
    inFile.close();

    bool found = false;
    vector<Attendance>::iterator it;
    for (it = attendances.begin(); it != attendances.end(); ++it) {
        if (it->empId == empId && it->date == date) {
            found = true;
            attendances.erase(it);
            break;
        }
    }

    if (!found) {
        cout << "Attendance record not found." << endl;
        return;
    }

    ofstream outFile("attendance.txt");
    if (!outFile) {
        cout << "Unable to open file for writing." << endl;
        return;
    }

    for (const auto &a : attendances) {
        outFile << a.empId << "\t" << a.date << "\t" << a.timeIn << "\t" << a.timeOut << endl;
    }
    outFile.close();
    cout << "Attendance record deleted successfully." << endl;
}

void EmployeeManagement::employeeManagementMenu() {
    int choice;
    do {
        cout << "Manage Employee Record\n";
        cout << "1. Update Employee Record\n";
        cout << "2. Delete Employee Record\n";
        cout << "3. Search Employee\n";
        cout << "4. Display All Record\n";
        cout << "5. Back\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                updateEmployee();
                break;
            case 2:
                deleteEmployee();
                break;
            case 3:
                displayAllEmployees();
                break;
            default:
                cout << "Invalid choice. Please try again.\n";
        }
    } while (choice != 6);
}

void EmployeeManagement::attendanceMenu() {
    int choice;
    do {
        cout << "Employee Attendance\n";
        cout << "1. Add Employee Attendance\n";
        cout << "2. Update Employee Attendance\n";
        cout << "3. Display Employee Attendance\n";
        cout << "4. Delete Employee Attendance\n";
        cout << "5. Back\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                addAttendance();
                break;
            case 2:
                updateAttendance();
                break;
            case 3:
                displayAttendance();
                break;
            case 4:
                deleteAttendance();
                break;
            case 5:
                return;
            default:
                cout << "Invalid choice. Please try again.\n";
        }
    } while (choice != 5);
}
