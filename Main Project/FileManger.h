#pragma once

using namespace std;

class FileManger : public DataSourceInterface {
private:
	static void addClient(Client c) {
		FileHelper::saveClient(c);
	}

	static void addEmployee(Employee e) {
		FileHelper::saveEmployee(fileEmployee, employeeLastID, e);
	}

	static void addAdmin(Admin a) {
		FileHelper::saveEmployee(fileAdmin, adminLastID, a);
	}

	static void getAllClients() {
		FileHelper::getClients();
	}

	static void getAllEmployees() {
		FileHelper::getEmployees();
	}

	static void getAllAdmins() {
		FileHelper::getAdmins();
	}

	static void removeAllClients() {
		FileHelper::clearFile(fileClient, clientLastID);
	}

	static void removeAllEmployees() {
		FileHelper::clearFile(fileEmployee, employeeLastID);
	}

	static void removeAllAdmins() {
		FileHelper::clearFile(fileAdmin, adminLastID);
	}
public:
	static void getAllData() {
		getAllClients();
		getAllEmployees();
		getAllAdmins();
	}

	static void updateClients() {
		removeAllClients();
		//Client c;
		//for (int i = 0; i < allClients.size(); i++) {
		//	
		//	addClient(c);
		//}
		for (clIt = allClients.begin(); clIt != allClients.end(); clIt++) addClient(*clIt);
	}

	static void updateEmployees() {
		removeAllEmployees();
		for (eIt = allEmployees.begin(); eIt != allEmployees.end(); eIt++) addEmployee(*eIt);
	}

	static void updateAdmins(){
		removeAllAdmins();
		for (aIt = allAdmins.begin(); aIt != allAdmins.end(); aIt++) addAdmin(*aIt);
	}
};