#include "Utils.h"
#include <iostream>
#include <fstream>
#include"Customer.h"
#include"Admin.h"
#include "serviceProcess.h"
using namespace std;

Utils::Utils() {
}

Utils* Utils::instance = 0;

Utils* Utils::getinstance() {
	if (instance == NULL)
	{
		instance = new Utils;
	}
	return instance;
}

void Utils::mappingCarLineToObj(unordered_map<string, Car>& car)  // from file to system
{
	ifstream input( "newCar.txt");
	string line;
	while (getline(input, line)) {
		int lineSize = line.size();
		int dataMemberCnt = 0;
		string carName;
		string currentDataMember = "";
		for (int i = 0; i < lineSize; i++) {
			if (line[i] == '|') {
				dataMemberCnt++;
				switch (dataMemberCnt) {
				case 1: {
					carName = currentDataMember;
					car[carName].Model = currentDataMember;
					currentDataMember = "";
					break;
				}
				case 2: {

					car[carName].Id = currentDataMember;
					currentDataMember = "";
					break;
				}
				case 3: {

					car[carName].Make = currentDataMember;
					currentDataMember = "";
					break;
				}
				case 4: {

					car[carName].Year = currentDataMember;
					currentDataMember = "";
					break;
				}
				case 5: {

					car[carName].Price = currentDataMember;
					currentDataMember = "";
					break;
				}
			}

			}
			else {
				if (i == lineSize - 1) {
					currentDataMember += line[i];
					car[carName].Installment=currentDataMember;
					currentDataMember = "";
				}
				else {
					currentDataMember += line[i];
				}
			}
		}
	}

}

void Utils::mappingGarageLineToObj(unordered_map<string, Garages>& garage)
{
	ifstream input("newGarage.txt");
	string line;
	while (getline(input, line)) {
		int lineSize = line.size();
		Garages gar;
		int dataMemberCnt = 0;
		string garageName;
		string currentDataMember = "";
		for (int i = 0; i < lineSize; i++) {
			if (line[i] == '|') {
				dataMemberCnt++;
				switch (dataMemberCnt) {
				case 1: {
					garageName = currentDataMember;
					garage[garageName].Name = currentDataMember;
					currentDataMember = "";
					break;
				}
				case 2: {
					garage[garageName].Id = currentDataMember;
					currentDataMember = "";
					break;
				}
				case 3: {
					garage[garageName].Location = currentDataMember;
					currentDataMember = "";
					break;
				}
				case 4: {
					garage[garageName].Phone_Num = currentDataMember;
					currentDataMember = "";
					break;
				}

				}
			}
			else {
				if (i == lineSize - 1) {
					currentDataMember += line[i];
					garage[garageName].listOfservice = getVectorFromLine(currentDataMember);
					currentDataMember = "";
					break;
				}
				else {
					currentDataMember += line[i];
				}
			}
			
		//	garage[garageName] = gar;
		}
	}
}

void Utils::mappingServiceLineToObj(unordered_map<string, Service>& service)
{
	ifstream input("newService.txt");
	string line;
	while (getline(input, line)) {
		int lineSize = line.size();
		Service ser;
		int dataMemberCnt = 0;
		string serviceName;
		string currentDataMember = "";
		for (int i = 0; i < lineSize; i++) {
			if (line[i] == '|') {
				dataMemberCnt++;
				switch (dataMemberCnt) {
				case 1: {
					serviceName = currentDataMember;
					service[serviceName].nameService = currentDataMember;
					currentDataMember = "";
					break;
				}
				case 2: {
					service[serviceName].idService = currentDataMember;
					currentDataMember = "";
					break;
				}
				
				}
			}
			else {
				if (i == lineSize - 1) {
					currentDataMember += line[i];
					service[serviceName].priceService =stoi(currentDataMember);
					currentDataMember = "";
					break;
				}
				else {
					currentDataMember += line[i];
				}
			}
		//	service[ser.nameService] =ser;
		}
	}
}

void Utils::mappingShowroomsLineToObj(unordered_map<string, Showrooms>& room)
{
	ifstream input("newShowroom.txt");
	string line;
	while (getline(input, line)) {
		int lineSize = line.size();
		Showrooms roomm;
		int dataMemberCnt = 0;
		string roomName;
		string currentDataMember = "";
		for (int i = 0; i < lineSize; i++) {
			if (line[i] == '|') {
				dataMemberCnt++;
				switch (dataMemberCnt) {
				case 1: {
					roomName = currentDataMember;
					room[roomName].Name = currentDataMember;
					currentDataMember = "";
					break;
				}
				case 2: {
					room[roomName].Id = currentDataMember;
					currentDataMember = "";
					break;
				}
				case 3: {
					room[roomName].Location = currentDataMember;
					currentDataMember = "";
					break;
				}
				case 4: {
					room[roomName].Phone_Number = currentDataMember;
					currentDataMember = "";
					break;
				}

				}
			}
			else {
				if (i == lineSize - 1) {
					currentDataMember += line[i];
					room[roomName].addnewCar(currentDataMember);
					currentDataMember = "";
					break;
				}
				else {
					currentDataMember += line[i];
				}
			}

			//room[roomm.Name] = roomm;
		}
	}
}



void Utils::mappingObjCarToLine(unordered_map<string, Car>& car)
{
	ifstream fileOpen("newCar.txt");
	fileOpen.clear();
	unordered_map <string, Car>::iterator it;
	fstream update; 
	update.open("newCar.txt");
	for (it = car.begin(); it != car.end(); it++)
	{

		update << it->second.Model << "|" << it->second.Id << "|" << it->second.Make << "|" << it->second.Year << "|" << it->second.Price << "|" << it->second.Installment << endl;
	}
	update.close();
}

void Utils::mappingObjGarageToLine(unordered_map<string, Garages>& garage)
{
	fstream fileOpen("newGarage.txt");
	fileOpen.clear();
	unordered_map <string, Garages>::iterator it;
	vector <string>::iterator it2;
	fstream update;
	update.open("newGarage.txt");
	for (it = garage.begin(); it != garage.end(); it++)
	{
		update << it->second.Name << "|" << it->second.Id<< "|" << it->second.Location << "|" << it->second.Phone_Num<<"[";
		string line;
		for (it2 = it->second.listOfservice.begin(); it2 != it->second.listOfservice.end(); it2++)
		{
			if (*it2 == "null")
			{
				line += "null,";
				break;
			}
			else
			{
				line += *it2;
				line += ",";
			}
		}
	//	line.pop_back();
		update << line << "]|"<< endl;
	}
	update.close();
}

void Utils::mappingObjServiceToLine(unordered_map<string, Service>& service)
{
	ifstream fileOpen("newService.txt");
	fileOpen.clear();
	unordered_map <string, Service>::iterator it;
	fstream update;
	update.open("newService.txt");
	for (it = service.begin(); it != service.end(); it++)
	{
		update << it->second.nameService << "|" << it->second.idService << "|" << it->second.priceService << endl;
	}
	update.close();
}

void Utils::mappingObjShowroomsToLine(unordered_map<string, Showrooms>& room)
{
	ifstream fileOpen("newShowroom.txt");
	fileOpen.clear();
	unordered_map <string, Showrooms>::iterator it;
	fstream update;
	update.open("newShowroom.txt");
	for (it = room.begin(); it != room.end(); it++)
	{
		update << it->second.Name << "|" << it->second.Id << "|" << it->second.Location << "|" << it->second.Phone_Number;
	}
	update.close();
}



vector<string> Utils::getVectorFromLine(string line)
{
	// VECTOR SHOULD BE LIKE THAT!!!! -> ,,,
	line.pop_back();
	line.erase(line.begin());
	string item = "";
	vector<string> items;
	for (int i = 0; i < line.size(); i++) {

		if (line[i] == ',') {
			items.push_back(item);
			item = "";
		}
		else {
			item += line[i];
		}
		if (i == line.size() - 1)
		{
			items.push_back(item);
			break;
		}
	}
	return items;
}

int Utils::loginChoice()
{
	int choice;
	cout << "\tEnter the Number Of Choice That you Want" << endl;
	cout << "\t__________________________________________________" << endl;
	cout << "\t__________________________________________________" << endl;
	cout << "\t1- Enter As ADMIN\n";
	cout << "\t2- Enter As Customar\n";
	cout << "\t3- Register As Customar\n";
	cout << "\t4- Exit the programme\n";
	cout << endl << "----------> ";
	cin >> choice;
	return choice;
}

int Utils::adminOperation()
{
	int choiceOfOperation;
	cout << "Enter the Number Of operation That you Want" << endl;
	cout << "*******************************************" << endl;
	cout << "\t1- Add New Car\n\n";
	cout << "\t2- Add New garage\n\n";
	cout << "\t3- Add New service\n\n";
	cout << "\t4- Add New Showrooms\n\n";
	cout << "\t5- Edit Car data\n\n";
	cout << "\t6- Edit Garage data\n\n";
	cout << "\t7- Edit Service data\n\n";
	cout << "\t8- Edit Showrooms data\n\n";
	cout << "\t9- Delete Car\n\n";
	cout << "\t10- Delete Service\n\n";
	cout << "\t11- Delete Garage\n\n";
	cout << "\t12- Delete Showroom\n\n";
	cout << "\t0- Exit\n\n";
	cout << endl << "----------> ";
	cin >> choiceOfOperation;
	return choiceOfOperation;
}

int Utils::CustomarOperation()
{
	int choiceOfOperation;
	cout << "Enter the Number Of operation That you Want" << endl;
	cout << "*******************************************\n\n" << endl;
	cout << "\t1- What to do \n\n";
	cout << "\t0- Exit\n\n";
	cout << endl << "----------> ";
	cin >> choiceOfOperation;
	return choiceOfOperation;
}

void Utils::mappingAdminLineToObj(unordered_map<string, Admin>& admin)
{
	ifstream input("admins.txt");
	string line;
	while (getline(input, line)) {
		int lineSize = line.size();
		Admin currentAdmin;
		string adminName;
		int dataMemberCnt = 0;
		string currentDataMember = "";
		for (int i = 0; i < lineSize; i++)
		{
			if (line[i] == '|') {
				dataMemberCnt++;
				switch (dataMemberCnt) {
				case 1: {
					currentAdmin.Username=currentDataMember;
					adminName = currentDataMember;
					currentDataMember = "";
					break;
				}
				case 2: {
					currentAdmin.password=currentDataMember;
					currentDataMember = "";
					break;
				}
				}
				currentDataMember = "";
			}
			else {
				if (i == lineSize - 1)
				{
					currentDataMember += line[i];
					currentAdmin.password=currentDataMember;
					currentDataMember = "";

				}
				else {
					currentDataMember += line[i];
				}
			}
		}
		admin[adminName] = currentAdmin;
	}
}

void Utils::mappingObjToAdminLine(unordered_map<string, Admin>& newAdmin)
{
	ifstream fileOpen("admins.txt");
	fileOpen.clear();
	unordered_map <string, Admin>::iterator it;
	ofstream update("admins.txt");
	for (it = newAdmin.begin(); it != newAdmin.end(); it++)
	{
		Admin admin = it->second;
		update << admin.Username << "|" << admin.password << endl;
	}
	update.close();
}

void Utils::mappingCustomerLineToObj(unordered_map<string, Customer>& customer)
{
	ifstream input("customers.txt");
	string line;
	while (getline(input, line)) {
		int lineSize = line.size();
		Customer currentCustomr;
		string customerName;
		int dataMemberCnt = 0;
		string currentDataMember = "";
		for (int i = 0; i < lineSize; i++)
		{
			if (line[i] == '|') {
				dataMemberCnt++;
				switch (dataMemberCnt) {
				case 1: {
					customerName = currentDataMember;
					currentCustomr.Username = currentDataMember;
					currentDataMember = "";
					break;
				}
				case 2: {
					currentCustomr.Password = currentDataMember;
					currentDataMember = "";
					break;
				}
				}
				currentDataMember = "";
			}
			else {
				if (i == lineSize - 1)
				{
					currentDataMember += line[i];
					currentCustomr.Password = currentDataMember;
					currentDataMember = "";
				}
				else {
					currentDataMember += line[i];
				}
			}
		}
		customer[customerName] = currentCustomr;
	}
}

void Utils::mappingObjToCustomerLine(unordered_map<string, Customer> customer)
{
	ifstream fileOpen("customers.txt");
	fileOpen.clear();
	unordered_map <string, Customer>::iterator it;
	ofstream update("customers.txt",ios::app);
	for (it = customer.begin(); it != customer.end(); it++)
	{
		update << it->second.Username << "|" << it->second.Password<< endl;
	}
	update.close();

	
}