#pragma once
using namespace std;

class Admin : public Employee
{
public:
	//Constructors
	Admin() {

	}

	Admin(string name, string password, int id, double salary) : Employee(name, password, id, salary) {

	}
	
	// Methods
	void addEmployee(Employee& e) {
		allEmployees.push_back(e);
	}

	Employee* searchEmployee(int id) {
		for (int i = 0; i < allEmployees.size(); i++) {
			if (allEmployees[i].getId() == id) {
				return & allEmployees[i];
			}
		}
		return NULL;
	}
	 
	void editEmployee(int id, string name, string password, double salary) {
		searchEmployee(id)->setName(name);
		searchEmployee(id)->setPassword(password);
		searchEmployee(id)->setSalary(salary);
	}

	void listEmployee() {
		for (int i = 0; i < allEmployees.size(); i++) {
			cout << "ID = " << allEmployees[i].getId() << endl;
			cout << "Name = " << allEmployees[i].getName() << endl;
			cout << "Password = " << allEmployees[i].getPassword() << endl;
			cout << "Salary = " << allEmployees[i].getSalary() << " EGP." << endl;
			cout << "=========================\n";
		}
	}
};

static vector <Admin> allAdmins;
static vector<Admin>::iterator aIt;