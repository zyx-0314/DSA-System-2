#include "employee_management.h"

int main() {
	int choice;
	EmployeeManagement employeeManagement;

	do {
		cout << "HR Management System\n";
		cout << "1. Manage Employee Record\n";
		cout << "2. Employee Attendance\n";
		cout << "3. Manage Recruitments\n";
		cout << "4. Ticket Report\n";
		cout << "5. Reward Employee\n";
		cout << "6. Exit\n";
		cout << "Enter your choice: ";
		cin >> choice;

		switch (choice) {
		case 1:
			employeeManagement.employeeManagementMenu();
			break;
		case 2:
			employeeManagement.attendanceMenu();
			break;
		case 3:
			employeeManagement.recruitmentsMenu();
			break;
		case 4:
			employeeManagement.ticketReportMenu();
			break;
		case 5:
			employeeManagement.rewardMenu();
			break;
		case 6:
			cout << "Exiting the program...\n";
			break;
		default:
			cout << "Invalid choice. Please try again.\n";
		}
	} while (choice != 6);

	return 0;
}
