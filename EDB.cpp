 //SIMPLE EMPLOYEE DATABASE USING QUEUE, SORTING AND SEARCHING
/*
GROUP AB
MEMBERES:
ANGELES, DENMARC FRANCIS HARRY P. (Lead Programmer, Sub-Programmer 1)
BALBAROSA, JOHN ANDREW (Programmer 2, Sub-Programmer 1)



*/
#include <iostream>
#include <string>
#include <iomanip>
#include <sstream>
using namespace std;

// Custom to_string function for int by BALBAROSA
string to_string(int value) {
    stringstream ss;
    ss << value;
    return ss.str();
}

// Custom to_string function for double by BALBAROSA
string to_string(double value) {
    stringstream ss;
    ss << value;
    return ss.str();
}

// Class to represent an Employee by BALBAROSA
class Employee {
public:
    string firstName;
    string lastName;
    int birthYear;
    int birthMonth;
    string jobTitle;
    int position; // 1-3
    double salary;
    string department;
    int id;

    Employee* next; // Pointer to the next employee in the list

    // Constructor to initialize an employee
    Employee(string fName, string lName, int bYear, int bMonth, string jTitle, int pos, double sal, string dept, int empId)
        : firstName(fName), lastName(lName), birthYear(bYear), birthMonth(bMonth), jobTitle(jTitle), position(pos), salary(sal), department(dept), id(empId), next(NULL) {}
};

// To manage the Employee Database by ANGELES
// NOTE: We created many funtions in order to apply recvursion into our programs inorder to do our sorting Algorithms an also applied it to our searching algorithms.
class EmployeeDatabase {
private:
	//NOTE: Functions in this area focuses more on the operations and implementations of the Algorithms.
    Employee* head; // Pointer to the head of the linked list
    int idCounter; // Counter to assign unique IDs

    void addEmployeeHelper(Employee*& head, Employee* newEmployee); // Helper function to add an employee by Denmarc Angeles
    void showEmployee(Employee* emp); // Helper function to display an employee's details by Denmarc Angeles
    Employee* findEmployeeByID(Employee* head, int id); // Helper function to search an employee by ID by Denmarc Angeles
    Employee* removeEmployeeHelper(Employee* head, int id); // Helper function to delete an employee by ID by Denmarc Angeles
    void showAllEmployees(Employee* head); // Helper function to display all employees by John Andrew Balbarosa
    void searchEmployeesHelper(Employee* head, const string& searchTerm, int criteria); // Helper function to search employees based on criteria by John Andrew Balbarosa
    void swapEmployees(Employee* a, Employee* b); // Helper function to swap data between two Employee nodes by Denmarc Angeles
    void sortEmployeesByHelper(int criteria); // Helper function to sort employees by department, position or ID by Denmarc Angeles

public:
	//NOTE: Functions in this area focuses on being more interactive to the user.
    EmployeeDatabase(); // Constructor to initialize the database

    void addEmployee(string fName, string lName, int bYear, int bMonth, string jTitle, int pos, double sal, string dept); // Function to add an employee
    void updateEmployee(int id, string fName, string lName, int bYear, int bMonth, string jTitle, int pos, double sal, string dept); // Function to update an employee's details
    void deleteEmployee(int id); // Function to delete an employee
    void displayAll(); // Function to display all employees
    void addEmployeeInteractive(); // Function to interactively add an employee
    void updateEmployeeInteractive(); // Function to interactively update an employee's details
    void deleteEmployeeInteractive(); // Function to interactively delete an employee
    void searchEmployeeInteractive(); // Function to interactively search employees
	void sortEmployeesByID(); // Function to sort employees by ID
    void sortEmployeesByDepartment(); // Function to sort employees by department
    void sortEmployeesByPosition(); // Function to sort employees by position
};



// Main Program
int main() {
    EmployeeDatabase db;
    int choice;

    //NOTE: Sample employees for demonstration
    db.addEmployee("Oscar", "Doe", 1985, 7, "Manager", 1, 60000, "Sales");
    db.addEmployee("Marc", "Smith", 1991, 3, "CEO", 3, 550000, "Management");
    db.addEmployee("John", "Doe", 2003, 7, "Manager", 1, 60000, "Sales");
    db.addEmployee("Maria", "Smith", 2004, 3, "Secretary", 3, 80000, "Management");
    db.addEmployee("John", "Joe", 1985, 7, "Director", 2, 60000, "Sales");
    db.addEmployee("Greg", "Hart", 1997, 3, "Sr. Engineer", 1, 55000, "Engineering");
    db.addEmployee("Ferdi", "Hart", 1985, 7, "Manager", 1, 60000, "Sales");
    db.addEmployee("David", "Smith", 1981, 3, "Market Analyst", 1, 55000, "Marketing");
    db.addEmployee("John", "Cranium", 1985, 7, "Manager", 2, 60000, "Sales");
    db.addEmployee("Larry", "Smith", 2000, 3, "Jr. Programmer", 1, 55000, "IT");
    db.addEmployee("John", "Baptist", 1985, 7, "Director", 1, 60000, "Sales");
    db.addEmployee("Gerald", "Vlod", 2002, 3, "Sr. Programmer", 2, 55000, "IT");
    db.addEmployee("Klyde", "Cranium", 1985, 7, "Manager", 2, 60000, "Sales");
    db.addEmployee("Verdun", "Vichy", 2000, 3, "Jr. Programmer", 1, 55000, "IT");
    db.addEmployee("Pope", "Francis", 1985, 7, "Director", 1, 60000, "Sales");
    db.addEmployee("Gerald", "Frod", 2002, 3, "Sr. Engineer", 2, 55000, "Engineering");

    while (true) {
    	
    	system("cls");
    	
        cout << "_____________________________________________\n";
        cout << "\n\tEmployee Database Menu\n";
        cout << "_____________________________________________\n";
        cout << "\t1. Add Employee\n";
        cout << "\t2. Update Employee\n";
        cout << "\t3. Delete Employee\n";
        cout << "\t4. Display All Employees\n";
        cout << "\t5. Search Employee\n";
        cout << "\t6. Sort Employees by Department\n";
        cout << "\t7. Sort Employees by Position\n";
        cout << "\t8. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                db.addEmployeeInteractive();
                break;
            case 2:
                db.updateEmployeeInteractive();
                break;
            case 3:
                db.deleteEmployeeInteractive();
                break;
            case 4:
            	system("cls");
            	db.sortEmployeesByID();
                db.displayAll();
                break;
            case 5:
            	system("cls");
                db.searchEmployeeInteractive();
                break;
            case 6:
            	system("cls");
                db.sortEmployeesByDepartment();
                db.displayAll();
                break;
            case 7:
            	system("cls");
                db.sortEmployeesByPosition();
                db.displayAll();
                break;
            case 8:
                return 0;
            default:
                cout << "Invalid choice. Please try again.\n";
        }
        system("pause");
    }
}




// Constructor to initialize the database 
EmployeeDatabase::EmployeeDatabase() : head(NULL), idCounter(1000) {}

// Helper function to add an employee
void EmployeeDatabase::addEmployeeHelper(Employee*& head, Employee* newEmployee) {
    if (!head) {
        head = newEmployee;
        return;
    }
    addEmployeeHelper(head->next, newEmployee);
}

// Helper function to display an employee's details
void EmployeeDatabase::showEmployee(Employee* emp) {
    if (!emp) return;
    cout << emp->id << setw(10) << emp->firstName << " " << emp->lastName
         << setw(20) << emp->birthMonth << "/" << emp->birthYear
         << setw(20) << emp->jobTitle << setw(20) << emp->position
         << setw(20) << "$" << fixed << setprecision(2) << emp->salary
         << setw(20) << emp->department << endl;
}

// Helper function to search an employee by ID
Employee* EmployeeDatabase::findEmployeeByID(Employee* head, int id) {
    if (!head) return NULL;
    if (head->id == id) return head;
    return findEmployeeByID(head->next, id);
}

// Helper function to delete an employee by ID
Employee* EmployeeDatabase::removeEmployeeHelper(Employee* head, int id) {
    if (!head) return NULL;
    if (head->id == id) {
        Employee* temp = head->next;
        delete head;
        return temp;
    }
    head->next = removeEmployeeHelper(head->next, id);
    return head;
}

// Helper function to display all employees
void EmployeeDatabase::showAllEmployees(Employee* head) {
    if (!head) return;
    showEmployee(head);
    showAllEmployees(head->next);
}

// Helper function to search employees based on criteria
void EmployeeDatabase::searchEmployeesHelper(Employee* head, const string& searchTerm, int criteria) {
    if (!head) return;
    switch (criteria) {
        case 1: // Search by ID
            if (to_string(head->id) == searchTerm) showEmployee(head);
            break;
        case 2: // Search by last name
            if (head->lastName == searchTerm) showEmployee(head);
            break;
        case 3: // Search by date of birth
            if (to_string(head->birthYear) == searchTerm || to_string(head->birthMonth) == searchTerm) showEmployee(head);
            break;
        case 4: // Search by position
            if (to_string(head->position) == searchTerm) showEmployee(head);
            break;
        case 5: // Search by job title
            if (head->jobTitle == searchTerm) showEmployee(head);
            break;
        case 6: // Search by department
            if (head->department == searchTerm) showEmployee(head);
            break;
        default:
            cout << "Invalid search criteria." << endl;
            return;
    }
    searchEmployeesHelper(head->next, searchTerm, criteria);
}

// Helper function to swap data between two Employee nodes
void EmployeeDatabase::swapEmployees(Employee* a, Employee* b) {
    swap(a->firstName, b->firstName);
    swap(a->lastName, b->lastName);
    swap(a->birthYear, b->birthYear);
    swap(a->birthMonth, b->birthMonth);
    swap(a->jobTitle, b->jobTitle);
    swap(a->position, b->position);
    swap(a->salary, b->salary);
    swap(a->department, b->department);
    swap(a->id, b->id);
}

// Bubble sort implementation to sort employees by department, position or ID
void EmployeeDatabase::sortEmployeesByHelper(int criteria) {
    if (!head) return;

    bool swapped;
    Employee* ptr1;
    Employee* lptr = NULL;

    do {
        swapped = false;
        ptr1 = head;

        while (ptr1->next != lptr) {
            if ((criteria == 1 && ptr1->department > ptr1->next->department) ||
                (criteria == 2 && ptr1->position > ptr1->next->position) || (criteria == 3 && ptr1->id > ptr1->next->id))  {
                swapEmployees(ptr1, ptr1->next);
                swapped = true;
            }
            ptr1 = ptr1->next;
        }
        lptr = ptr1;
    } while (swapped);
}

// Function to add an employee
void EmployeeDatabase::addEmployee(string fName, string lName, int bYear, int bMonth, string jTitle, int pos, double sal, string dept) {
    Employee* newEmployee = new Employee(fName, lName, bYear, bMonth, jTitle, pos, sal, dept, idCounter++);
    addEmployeeHelper(head, newEmployee);
}

// Function to update an employee's details
void EmployeeDatabase::updateEmployee(int id, string fName, string lName, int bYear, int bMonth, string jTitle, int pos, double sal, string dept) {
    Employee* emp = findEmployeeByID(head, id);
    if (emp) {
        emp->firstName = fName;
        emp->lastName = lName;
        emp->birthYear = bYear;
        emp->birthMonth = bMonth;
        emp->jobTitle = jTitle;
        emp->position = pos;
        emp->salary = sal;
        emp->department = dept;
    } else {
        cout << "Employee with ID " << id << " not found." << endl;
    }
}

// Function to delete an employee
void EmployeeDatabase::deleteEmployee(int id) {
    head = removeEmployeeHelper(head, id);
}

// Function to display all employees
void EmployeeDatabase::displayAll() {
	cout << "_______________________________________________________________________________________________________________________________________________\n";
	cout << "\t\t\t\t\t\t\tEMPLOYEE LIST\n";
	cout << "_______________________________________________________________________________________________________________________________________________\n";
    cout << "ID" << setw(15) << "NAME" << setw(30) << "DATE OF BIRTH" << setw(15) << "JOB TITLE" << setw(30) << "AUTHORIZATION LEVEL" << setw(20) << "SALARY" << setw(23) << "DEPARTMENT\n";
    cout << "_______________________________________________________________________________________________________________________________________________\n";
    showAllEmployees(head);
}

// Function to interactively add an employee
void EmployeeDatabase::addEmployeeInteractive() {
    string fName, lName, jTitle, dept;
    int bYear, bMonth, pos;
    double sal;

    cout << "Enter first name: ";
    cin.ignore();
    getline(cin, fName);
    cout << "Enter last name: ";
    cin.ignore();
    getline(cin, lName);
    cout << "Enter birth year: ";
    cin >> bYear;
    cout << "Enter birth month: ";
    cin >> bMonth;
    cout << "Enter job title: ";
    cin.ignore();
    getline(cin, jTitle);
    cout << "Enter position (1-3): ";
    cin >> pos;
    cout << "Enter salary: ";
    cin >> sal;
    cout << "Enter department: ";
    cin.ignore();
    getline(cin, dept);

    addEmployee(fName, lName, bYear, bMonth, jTitle, pos, sal, dept);
}

// Function to interactively update an employee's details
void EmployeeDatabase::updateEmployeeInteractive() {
    int id;
    string fName, lName, jTitle, dept;
    int bYear, bMonth, pos;
    double sal;

    cout << "Enter employee ID to update: ";
    cin >> id;
    cout << "Enter first name: ";
    cin.ignore();
    getline(cin, fName);
    cout << "Enter last name: ";
    cin.ignore();
    getline(cin, lName);
    cout << "Enter birth year: ";
    cin >> bYear;
    cout << "Enter birth month: ";
    cin >> bMonth;
    cout << "Enter job title: ";
    cin.ignore();
    getline(cin, jTitle);
    cout << "Enter position (1-3): ";
    cin >> pos;
    cout << "Enter salary: ";
    cin >> sal;
    cout << "Enter department: ";
    cin.ignore();
    getline(cin, dept);

    updateEmployee(id, fName, lName, bYear, bMonth, jTitle, pos, sal, dept);
}

// Function to interactively delete an employee
void EmployeeDatabase::deleteEmployeeInteractive() {
    int id;
    cout << "Enter employee ID to delete: ";
    cin >> id;
    deleteEmployee(id);
}

// Function to interactively search employees
void EmployeeDatabase::searchEmployeeInteractive() {
    int criteria;
    string searchTerm;

    cout << "\nSearch Employee by:\n";
    cout << "[1] ID\n";
    cout << "[2] Last Name\n";
    cout << "[3] Date of Birth (Year or Month)\n";
    cout << "[4] Position\n";
    cout << "[5] Job Title\n";
    cout << "[6] Department\n";
    cout << "Enter your choice: ";
    cin >> criteria;

    cout << "Enter search term: ";
    cin.ignore();
    getline(cin, searchTerm);

    searchEmployeesHelper(head, searchTerm, criteria);
}

// Function to sort employees by department
void EmployeeDatabase::sortEmployeesByDepartment() {
    sortEmployeesByHelper(1);
}

// Function to sort employees by position
void EmployeeDatabase::sortEmployeesByPosition() {
    sortEmployeesByHelper(2);
}

// Function to sort employees by position
void EmployeeDatabase::sortEmployeesByID() {
    sortEmployeesByHelper(3);
}



