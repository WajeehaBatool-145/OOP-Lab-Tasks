#include <iostream>
using namespace std;

class Employee {
private:
    int empID;
    string empName;

public:
    // Static variable (shared among all objects)
    static string companyName;

    // Constructor
    Employee(int id, string name) {
        empID = id;
        empName = name;
    }

    // Static member function
    static void displayCompanyInfo() {
        cout << "Company Name: " << companyName << endl;
    }

    // Function to display employee info
    void displayEmployee() {
        cout << "Employee ID: " << empID << endl;
        cout << "Employee Name: " << empName << endl;
        cout << "Company: " << companyName << endl;
        cout << "-------------------------" << endl;
    }
};

// Static variable initialization (IMPORTANT)
string Employee::companyName = "Systems Research Pvt Ltd";

int main() {

    // Objects create
    Employee e1(101, "Ali");
    Employee e2(102, "Sara");

    // Individual employee display
    e1.displayEmployee();
    e2.displayEmployee();

    // Static function call using class name
    Employee::displayCompanyInfo();

    return 0;
}
