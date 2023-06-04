#include <iostream>
#include <fstream>
#include <iomanip>

using namespace std;

struct Employee {
    int id;
    char name[50];
    char designation[50];
    double salary;
};

const char* filename = "employee_data.dat";
const int indexSize = 100;

void addEmployee() {
    ofstream file(filename, ios::binary | ios::app);
    Employee emp;

    cout << "Enter Employee ID: ";
    cin >> emp.id;

    cout << "Enter Employee Name: ";
    cin.ignore();
    cin.getline(emp.name, 50);

    cout << "Enter Employee Designation: ";
    cin.getline(emp.designation, 50);

    cout << "Enter Employee Salary: ";
    cin >> emp.salary;

    file.write(reinterpret_cast<const char*>(&emp), sizeof(Employee));
    file.close();

    cout << "Employee added successfully!" << endl;
}

void deleteEmployee() {
    int empID;
    bool found = false;

    cout << "Enter Employee ID to delete: ";
    cin >> empID;

    ifstream file(filename, ios::binary);
    ofstream temp("temp.dat", ios::binary);

    Employee emp;
    while (file.read(reinterpret_cast<char*>(&emp), sizeof(Employee))) {
        if (emp.id != empID) {
            temp.write(reinterpret_cast<const char*>(&emp), sizeof(Employee));
        } else {
            found = true;
        }
    }

    file.close();
    temp.close();

    remove(filename);
    rename("temp.dat", filename);

    if (found) {
        cout << "Employee deleted successfully!" << endl;
    } else {
        cout << "Employee not found!" << endl;
    }
}

void displayEmployee() {
    int empID;
    bool found = false;

    cout << "Enter Employee ID to display: ";
    cin >> empID;

    ifstream file(filename, ios::binary);

    Employee emp;
    while (file.read(reinterpret_cast<char*>(&emp), sizeof(Employee))) {
        if (emp.id == empID) {
            found = true;
            cout << "Employee ID: " << emp.id << endl;
            cout << "Name: " << emp.name << endl;
            cout << "Designation: " << emp.designation << endl;
            cout << "Salary: " << emp.salary << endl;
            break;
        }
    }

    file.close();

    if (!found) {
        cout << "Employee not found!" << endl;
    }
}

int main() {
    int choice;

    while (true) {
        cout << "\n***** Employee Management System *****" << endl;
        cout << "1. Add Employee" << endl;
        cout << "2. Delete Employee" << endl;
        cout << "3. Display Employee" << endl;
        cout << "4. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                addEmployee();
                break;
            case 2:
                deleteEmployee();
                break;
            case 3:
                displayEmployee();
                break;
            case 4:
                return 0;
            default:
                cout << "Invalid choice! Please try again." << endl;
        }
    }
}
