#pragma once

using namespace std;

class Employee : public Person
{
protected:
	double salary;
public:
	Employee() {
		salary = 0;
	}
	Employee(string name, string password, int id, double salary) : Person(name, password, id)
	{
		setSalary(salary);
	}

	//setter 
	void setSalary(double salary) {
		bool checkSalaryReturn = Validation::checkSalary(salary);

		if (checkSalaryReturn == 1)
		{
			cout << "The salaty must not be less than 5000 EGP.\n";
		}
		else
			this->salary = salary;
	}

	//getter 
	double getSalary() {
		return salary;
	}

	void print() {
		cout << "ID = " << getId() << endl;
		cout << "Name = " << getName() << endl;
		cout << "Password = " << getPassword() << endl;
		cout << "Salary = " << getSalary() << " EGP." << endl;
	}

	void addClient(Client& c) {
		allClients.push_back(c);
	}

	Client* searchClient(int id) {
		for (int i = 0; i < allClients.size(); i++) {
			if (allClients[i].getId() == id)
				return &allClients[i];
		}
		return NULL;
	}

	void editClient(int id, string name, string password, double balance) {
		searchClient(id)->setName(name);
		searchClient(id)->setPassword(password);
		searchClient(id)->setBalance(balance);
	}

	void listClient() {
		for (int i = 0; i < allClients.size(); i++) {
			cout << "ID = " << allClients[i].getId() << endl;
			cout << "Name = " << allClients[i].getName() << endl;
			cout << "Password = " << allClients[i].getPassword() << endl;
			cout << "Balance = " << allClients[i].getBalance() << " EGP." << endl;
			cout << "=========================\n";
		}
	}
};

static vector<Employee> allEmployees;
static vector<Employee>::iterator eIt;