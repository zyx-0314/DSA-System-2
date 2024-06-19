#include "employee_management.h"

void EmployeeManagement::addApplicant() {
    ofstream outFile("applicants.txt", ios::app);
    if (!outFile) {
        cout << "Unable to open file for writing." << endl;
        return;
    }

    Applicant applicant;
    cout << "Enter Applicant ID: ";
    cin >> applicant.id;
    cin.ignore();
    cout << "Enter Applicant Name: ";
    getline(cin, applicant.name);
    cout << "Enter Position Applied For: ";
    getline(cin, applicant.position);

    outFile << applicant.id << "\t" << applicant.name << "\t" << applicant.position << endl;
    outFile.close();
    cout << "Applicant record added successfully." << endl;
}

void EmployeeManagement::updateApplicant() {
    int id;
    cout << "Enter Applicant ID to update: ";
    cin >> id;

    ifstream inFile("applicants.txt");
    if (!inFile) {
        cout << "Unable to open file for reading." << endl;
        return;
    }

    vector<Applicant> applicants;
    Applicant applicant;
    while (inFile >> applicant.id >> ws) {
        getline(inFile, applicant.name, '\t');
        getline(inFile, applicant.position, '\t');
        applicants.push_back(applicant);
    }
    inFile.close();

    bool found = false;
    for (auto &a : applicants) {
        if (a.id == id) {
            found = true;
            cout << "Enter new Applicant Name: ";
            cin.ignore();
            getline(cin, a.name);
            cout << "Enter new Position Applied For: ";
            getline(cin, a.position);
            break;
        }
    }

    if (!found) {
        cout << "Applicant ID not found." << endl;
        return;
    }

    ofstream outFile("applicants.txt");
    if (!outFile) {
        cout << "Unable to open file for writing." << endl;
        return;
    }

    for (const auto &a : applicants) {
        outFile << a.id << "\t" << a.name << "\t" << a.position << endl;
    }
    outFile.close();
    cout << "Applicant record updated successfully." << endl;
}

void EmployeeManagement::deleteApplicant() {
    int id;
    cout << "Enter Applicant ID to delete: ";
    cin >> id;

    ifstream inFile("applicants.txt");
    if (!inFile) {
        cout << "Unable to open file for reading." << endl;
        return;
    }

    vector<Applicant> applicants;
    Applicant applicant;
    while (inFile >> applicant.id >> ws) {
        getline(inFile, applicant.name, '\t');
        getline(inFile, applicant.position, '\t');
        applicants.push_back(applicant);
    }
    inFile.close();

    bool found = false;
    vector<Applicant>::iterator it;
    for (it = applicants.begin(); it != applicants.end(); ++it) {
        if (it->id == id) {
            found = true;
            applicants.erase(it);
            break;
        }
    }

    if (!found) {
        cout << "Applicant ID not found." << endl;
        return;
    }

    ofstream outFile("applicants.txt");
    if (!outFile) {
        cout << "Unable to open file for writing." << endl;
        return;
    }

    for (const auto &a : applicants) {
        outFile << a.id << "\t" << a.name << "\t" << a.position << endl;
    }
    outFile.close();
    cout << "Applicant record deleted successfully." << endl;
}



void EmployeeManagement::addTicket() {
    ofstream outFile("tickets.txt", ios::app);
    if (!outFile) {
        cout << "Unable to open file for writing." << endl;
        return;
    }

    Ticket ticket;
    cout << "Enter Ticket ID: ";
    cin >> ticket.id;
    cin.ignore();
    cout << "Enter Description: ";
    getline(cin, ticket.description);
    cout << "Enter Status: ";
    getline(cin, ticket.status);

    outFile << ticket.id << "\t" << ticket.description << "\t" << ticket.status << endl;
    outFile.close();
    cout << "Ticket added successfully." << endl;
}

void EmployeeManagement::listTickets() {
    ifstream inFile("tickets.txt");
    if (!inFile) {
        cout << "Unable to open file for reading." << endl;
        return;
    }

    Ticket ticket;
    cout << "Ticket Records:" << endl;
    while (inFile >> ticket.id >> ws) {
        getline(inFile, ticket.description, '\t');
        getline(inFile, ticket.status, '\t');
        cout << "ID: " << ticket.id << ", Description: " << ticket.description << ", Status: " << ticket.status << endl;
    }
    inFile.close();
}

void EmployeeManagement::deleteTicket() {
    int id;
    cout << "Enter Ticket ID to delete: ";
    cin >> id;

    ifstream inFile("tickets.txt");
    if (!inFile) {
        cout << "Unable to open file for reading." << endl;
        return;
    }

    vector<Ticket> tickets;
    Ticket ticket;
    while (inFile >> ticket.id >> ws) {
        getline(inFile, ticket.description, '\t');
        getline(inFile, ticket.status, '\t');
        tickets.push_back(ticket);
    }
    inFile.close();

    bool found = false;
    vector<Ticket>::iterator it;
    for (it = tickets.begin(); it != tickets.end(); ++it) {
        if (it->id == id) {
            found = true;
            tickets.erase(it);
            break;
        }
    }

    if (!found) {
        cout << "Ticket ID not found." << endl;
        return;
    }

    ofstream outFile("tickets.txt");
    if (!outFile) {
        cout << "Unable to open file for writing." << endl;
        return;
    }

    for (const auto &t : tickets) {
        outFile << t.id << "\t" << t.description << "\t" << t.status << endl;
    }
    outFile.close();
    cout << "Ticket deleted successfully." << endl;
}

void EmployeeManagement::editTicket() {
    int id, choice;
    Ticket ticket;
    bool found = false;
    vector<Ticket> tickets;
    ifstream inFile("tickets.txt");
    ofstream outFile("tickets.txt");

    cout << "Enter Ticket ID to edit: ";
    cin >> id;

    if (!inFile) {
        cout << "Unable to open file for reading." << endl;
        return;
    }

    while (inFile >> ticket.id >> ws) {
        getline(inFile, ticket.description, '\t');
        getline(inFile, ticket.status, '\t');
        tickets.push_back(ticket);
    }
    inFile.close();

    for (auto &t : tickets) {
        if (t.id == id) {
            // Colins
            cout
                << "Enter Choice to Update:\n"
                << "1. Description\n"
                << "2. Status\n"
                << ":: ";
            cin >> choice;

            found = true;
            // Mamuri
            if (choice == 1) {
                cout << "Enter new Description: ";
                cin.ignore();
                getline(cin, t.description);
            }
            else if (choice == 2) {
                cout << "Enter new Status: ";
                getline(cin, t.status);
            }

            break;
        }
    }

    if (!found) {
        cout << "Ticket ID not found." << endl;
        return;
    }

    if (!outFile) {
        cout << "Unable to open file for writing." << endl;
        return;
    }

    for (const auto &t : tickets) {
        outFile << t.id << "\t" << t.description << "\t" << t.status << endl;
    }
    outFile.close();
    cout << "Ticket edited successfully." << endl;
}

void EmployeeManagement::addReward() {
    ofstream outFile("rewards.txt", ios::app);
    if (!outFile) {
        cout << "Unable to open file for writing." << endl;
        return;
    }

    // colins
    displayAllEmployees();

    Reward reward;
    cout << "Enter Employee ID: ";
    cin >> reward.empId;
    cin.ignore();
    cout << "Enter Reward Type: ";
    getline(cin, reward.rewardType);
    cout << "Enter Bonus Amount: ";
    cin >> reward.bonus;

    outFile << reward.empId << "\t" << reward.rewardType << "\t" << reward.bonus << endl;
    outFile.close();
    cout << "Reward added successfully." << endl;
}

void EmployeeManagement::listRewards() {
    ifstream inFile("rewards.txt");
    if (!inFile) {
        cout << "Unable to open file for reading." << endl;
        return;
    }

    Reward reward;
    cout << "Reward Records:" << endl;
    while (inFile >> reward.empId >> ws) {
        getline(inFile, reward.rewardType, '\t');
        inFile >> reward.bonus;
        cout << "Employee ID: " << reward.empId << ", Reward Type: " << reward.rewardType << ", Bonus: " << reward.bonus << endl;
    }
    inFile.close();
}

void EmployeeManagement::deleteReward() {
    int empId;
    string rewardType;
    cout << "Enter Employee ID and Reward Type to delete: ";
    cin >> empId >> ws;
    getline(cin, rewardType);

    ifstream inFile("rewards.txt");
    if (!inFile) {
        cout << "Unable to open file for reading." << endl;
        return;
    }

    vector<Reward> rewards;
    Reward reward;
    while (inFile >> reward.empId >> ws) {
        getline(inFile, reward.rewardType, '\t');
        inFile >> reward.bonus;
        rewards.push_back(reward);
    }
    inFile.close();

    bool found = false;
    vector<Reward>::iterator it;
    for (it = rewards.begin(); it != rewards.end(); ++it) {
        if (it->empId == empId && it->rewardType == rewardType) {
            found = true;
            rewards.erase(it);
            break;
        }
    }

    if (!found) {
        cout << "Reward record not found." << endl;
        return;
    }

    ofstream outFile("rewards.txt");
    if (!outFile) {
        cout << "Unable to open file for writing." << endl;
        return;
    }

    for (const auto &r : rewards) {
        outFile << r.empId << "\t" << r.rewardType << "\t" << r.bonus << endl;
    }
    outFile.close();
    cout << "Reward record deleted successfully." << endl;
}

void EmployeeManagement::updateReward() {
    int empId;
    string rewardType;
    cout << "Enter Employee ID and Reward Type to update: ";
    cin >> empId >> ws;
    getline(cin, rewardType);

    ifstream inFile("rewards.txt");
    if (!inFile) {
        cout << "Unable to open file for reading." << endl;
        return;
    }

    vector<Reward> rewards;
    Reward reward;
    while (inFile >> reward.empId >> ws) {
        getline(inFile, reward.rewardType, '\t');
        inFile >> reward.bonus;
        rewards.push_back(reward);
    }
    inFile.close();

    bool found = false;
    for (auto &r : rewards) {
        if (r.empId == empId && r.rewardType == rewardType) {
            found = true;
            cout << "Enter new Reward Type: ";
            getline(cin, r.rewardType);
            cout << "Enter new Bonus Amount: ";
            cin >> r.bonus;
            break;
        }
    }

    if (!found) {
        cout << "Reward record not found." << endl;
        return;
    }

    ofstream outFile("rewards.txt");
    if (!outFile) {
        cout << "Unable to open file for writing." << endl;
        return;
    }

    for (const auto &r : rewards) {
        outFile << r.empId << "\t" << r.rewardType << "\t" << r.bonus << endl;
    }
    outFile.close();
    cout << "Reward record updated successfully." << endl;
}

void EmployeeManagement::recruitmentsMenu() {
    int choice;
    do {
        cout << "Manage Recruitments\n";
        cout << "1. Add Applicant\n";
        cout << "2. Update Applicant\n";
        cout << "3. Search Applicant\n";
        cout << "4. Delete Applicant\n";
        cout << "5. Back\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                addApplicant();
                break;
            case 2:
                updateApplicant();
                break;
            case 4:
                deleteApplicant();
                break;
            case 5:
                return;
            default:
                cout << "Invalid choice. Please try again.\n";
        }
    } while (choice != 5);
}

void EmployeeManagement::ticketReportMenu() {
    int choice;
    do {
        cout << "Ticket Report\n";
        cout << "1. Add Ticket\n";
        cout << "2. List of Tickets\n";
        cout << "3. Remove Ticket\n";
        cout << "4. Edit Ticket\n";
        cout << "5. Back\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                addTicket();
                break;
            case 2:
                listTickets();
                break;
            case 3:
                deleteTicket();
                break;
            case 4:
                editTicket();
                break;
            case 5:
                return;
            default:
                cout << "Invalid choice. Please try again.\n";
        }
    } while (choice != 5);
}

void EmployeeManagement::rewardMenu() {
    int choice;
    do {
        cout << "Reward Employee\n";
        cout << "1. Add Employee Reward\n";
        cout << "2. List Employee Reward\n";
        cout << "3. Remove Employee Reward\n";
        cout << "4. Update Employee Reward\n";
        cout << "5. Back\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                addReward();
                break;
            case 2:
                listRewards();
                break;
            case 3:
                deleteReward();
                break;
            case 4:
                updateReward();
                break;
            case 5:
                return;
            default:
                cout << "Invalid choice. Please try again.\n";
        }
    } while (choice != 5);
}
