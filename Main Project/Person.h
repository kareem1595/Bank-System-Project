#pragma once

using namespace std;

class Person
{
protected:
	string name, password;
	int id;
public:
	// Constructors
	Person()
	{
		id = 0;
	}

	Person(string name, string password, int id) {
		setId(id);
		setName(name);
		setPassword(password);
	}

	//setter 
	void setName(string name)
	{
		if (Validation::checkName(name) == 1) {
			this->name = name;
		}
	}

	void setPassword(string password)
	{
		bool checkPaswword = Validation::checkPassword(password);

		if (checkPaswword == 1)
			cout << "Password must be between 8 and 20 characters.\n";
		else
			this->password = password;
	}

	void setId(int id) {
		this->id = id;
	}

	//getter 
	string getName()
	{
		return name;
	}

	string getPassword()
	{
		return password;
	}

	int getId()
	{
		return id;
	}

	// Methods
	virtual void print() = 0;
};