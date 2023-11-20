#pragma once

using namespace std;

class Client : public Person
{
protected:
	double balance;
public:

	// Constructors
	Client() {
		balance = NULL;
	}

	Client(string name, string password, int id, double balance) : Person(name, password, id)
	{
		setBalance(balance);
	}

	//setter 
	void setBalance(double balance)
	{
		bool checkBalanceReturn = Validation::checkBalance(balance);

		if (checkBalanceReturn == 1)
			cout << "The balance must not be less than 1,500 EGP.\n";
		else if (checkBalanceReturn == 0)
			this->balance = balance;
	}

	//getter 
	double getBalance() {
		return balance;
	}

	// Methods
	void deposit(double amount)
	{
		balance += amount;
	}

	void withdraw(double amount)
	{
		balance -= amount;
	}

	void trasferTo(double amount, Client& recipient)
	{
		if (balance < amount)
		{
			cout << "Sorry, there is no enough money in this account.\n";
		}
		else
		{
			recipient.balance += amount;
			balance -= amount;
		}
	}

	void print() {
		cout << "ID = " << getId() << endl;
		cout << "Name = " << getName() << endl;
		cout << "Password = " << getPassword() << endl;
		cout << "Balance = " << getBalance() << " EGP." << endl;
	}
};

static vector <Client> allClients;
static vector<Client>::iterator clIt;