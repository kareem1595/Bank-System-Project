#pragma once

using namespace std;

class Validation {
public:
	static bool checkName(string name)
	{
		for (int i = 0; i < name.size(); i++) {
			if (isalpha(name[i]) == 0)
				return false;
		}
		if (name.size() >= 5 && name.size() <= 20)
			return true;
		else
			return false;
	}

	static bool checkPassword(string password)
	{
		if (password.size() < 8 || password.size() > 20)
			return 1;
		else
			return 0;
	}

	static bool checkBalance(double balance)
	{
		if (balance < 1500)
			return 1;
		else
			return 0;
	}

	static bool checkSalary(double salary)
	{
		if (salary < 5000)
			return 1;
		else
			return 0;
	}
};



