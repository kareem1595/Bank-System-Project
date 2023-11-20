#pragma once

using namespace std;

// Data files
const string fileClient = "Clients Data.txt";
const string fileEmployee = "Employees Data.txt";
const string fileAdmin = "Admins Data.txt";

// ID files
const string clientLastID = "Client Last ID.txt";
const string employeeLastID = "Employee Last ID.txt";
const string adminLastID = "Admin Last ID.txt";

class FileHelper
{
public:
	static int getLast(string fileName) {
		fstream myFile;
		int lastId;

		if (fileName == clientLastID || fileName == employeeLastID || fileName == adminLastID) {
			myFile.open(fileName, ios::in);
			myFile >> lastId;
			myFile.close();

			return lastId;
		}
	}

	static void saveLast(string fileName, int id) {
		fstream myFile;

		myFile.open(fileName, ios::out);
		myFile << id;
		myFile.close();

	}

	static void saveClient(Client c) {
		fstream myFile;
		int lastID = getLast(clientLastID);
		lastID++;

		myFile.open(fileClient, ios::app);
		c.setId(lastID);
		myFile << c.getId() << "|" << c.getName() << "|" << c.getPassword() << "|" << c.getBalance() << endl;
		myFile.close();
		saveLast(clientLastID, getLast(clientLastID) + 1);
	}

	static void saveEmployee(string fileName, string lastIdFile, Employee e) {
		fstream myFile;
		int employeeId = getLast(lastIdFile);
		employeeId++;

		myFile.open(fileName, ios::app);
		e.setId(employeeId);
		//myFile << e.getId() << "|" << e.getName() << "|" << e.getPassword() << "|" << e.getSalary() << endl;
		
		myFile.close();
		saveLast(lastIdFile, getLast(lastIdFile) + 1);
	}

	static void getClients() {
		fstream file;
		string line;

		file.open(fileClient, ios::in);
		while (getline(file, line)) {
			allClients.push_back(Parser::parserToClient(line));
		}
		file.close();
	}

	static void getEmployees() {
		string line;
		fstream file;

		file.open(fileEmployee, ios::in);
		while (getline(file, line)) {
			allEmployees.push_back(Parser::parserToEmployee(line));
		}
		file.close();
	}

	static void getAdmins() {
		string line;
		fstream file;

		file.open(fileAdmin, ios::in);
		while (getline(file, line)) {
			allAdmins.push_back(Parser::parserToAdmin(line));
		}
		file.close();
	}

	static void clearFile(string fileName, string lastIdFile) {
		fstream file;

		file.open(fileName, ios::out);
		file.close();

		file.open(lastIdFile, ios::out);
		file << 0;
		file.close();
	}
};