#ifndef EMPLOYEE_MANAGEMENT_H
#define EMPLOYEE_MANAGEMENT_H

#include <iostream>
#include <fstream>
#include <vector>
#include <string>

using namespace std;

class EmployeeManagement {
public:
    void employeeManagementMenu();
    void attendanceMenu();
    void recruitmentsMenu();
    void ticketReportMenu();
    void rewardMenu();

private:
    struct Employee;
    struct Attendance;
    struct Applicant;
    struct Ticket;
    struct Reward;

    void addApplicant();
    void updateApplicant();
    void deleteApplicant();

    void updateEmployee();
    void deleteEmployee();
    void displayAllEmployees();

    void addAttendance();
    void updateAttendance();
    void displayAttendance();
    void deleteAttendance();

    void addTicket();
    void listTickets();
    void deleteTicket();
    void editTicket();

    void addReward();
    void listRewards();
    void deleteReward();
    void updateReward();

protected:

};


struct EmployeeManagement::Employee {
    int id;
    string name;
    string position;
};

struct EmployeeManagement::Attendance {
    int empId;
    string date;
    string timeIn;
    string timeOut;
};

struct EmployeeManagement::Applicant {
    int id;
    string name;
    string position;
};

struct EmployeeManagement::Ticket {
    int id;
    string description;
    string status;
};

struct EmployeeManagement::Reward {
    int empId;
    string rewardType;
    double bonus;
};

#endif 
