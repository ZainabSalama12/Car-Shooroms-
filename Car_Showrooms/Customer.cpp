#include "Customer.h"
#include"Utils.h"
#include <conio.h>
#include"serviceProcess.h"

using namespace std;


Customer::Customer() {
	
}

void Customer::registers(unordered_map<string,Customer>customer) {
	string value;
	Customer newCustomer;
	unordered_map <string, Customer>::iterator it;
	cout << "Please , Enter Your Name :";
	cin >> value;
	newCustomer.Username = value;

	it = customer.find(newCustomer.Username);
	if (it == customer.end())
	{
		cout << "Please, Enter Id :";
		cin >> newCustomer.Id;
		cout << "Please , Password :";
		cin >> newCustomer.Password;
	}
	else
	{
		cout << " this customer is allready exist";
	}
	ofstream Myfile;
	Myfile.open("customers.txt", ios::app);
	if (Myfile.is_open()) {
		Myfile << newCustomer.Username << "|" << newCustomer.Password << endl;
		Myfile.close();
	}
}

void Customer::whatToDo()
{
	Utils* utils = Utils::getinstance();
	unordered_map<string, Car> car;
	unordered_map<string, Showrooms> room;
	unordered_map<string, Service> service;
	unordered_map<string, Garages> garage;
	unordered_map<string, Customer> customer;

	utils->mappingCarLineToObj(car);
	utils->mappingGarageLineToObj(garage);
	utils->mappingServiceLineToObj(service);
	utils->mappingShowroomsLineToObj(room);
	utils->mappingCustomerLineToObj(customer);

	BuyOrRent operation;
	Car newCar;
	Service newService;
	Garages newGarage;
	Showrooms newRoom;
	serviceProcess process;

	int choise;
Top_Menu:
	cout << "enter the choise of operation you want." << endl;
	cout << "------------------------------------------------" << endl;
	cout << "1-BuyOrRent" << endl;
	cout << "2-View List of Cars" << endl;
	cout << "3-View List of Garages" << endl;
	cout << "4-View List of rooms" << endl;
	cout << "5-search for specefic car" << endl;
	cout << "6-search for specefic  showrooms"<< endl;
	cout << "7-search for specefic garage" << endl;
	cout << "8-search for specefic service" << endl;
	cout << "9-Book for service" << endl;
	cout << "0-Exit" << endl;

	cout << "~~~~~~~~~~~~~~>";
	cin >> choise;
	system("CLS");
	switch (choise)
	{
		int id;
	case 1:
		operation.BuyorRent(car);
		utils->mappingObjCarToLine(car);
		cout << "~~~~~> Press enter key to go back to menu of operation." << endl;
		_getch();
		system("CLS");
		goto Top_Menu;
		break;
	case 2:
		newCar.viewListOfCars(car);
		utils->mappingObjCarToLine(car);
		cout << "~~~~~> Press enter key to go back to menu of operation." << endl;
		_getch();
		system("CLS");
		goto Top_Menu;
		break;
	case 3:
		newGarage.viewListOfGarages(garage);
		utils->mappingObjGarageToLine(garage);
		cout << "~~~~~> Press enter key to go back to menu of operation." << endl;
		_getch();
		system("CLS");
		goto Top_Menu;
		break;
	case 4:
		newRoom.viewListOfRooms(room);
		utils->mappingObjShowroomsToLine(room);
		cout << "~~~~~> Press enter key to go back to menu of operation." << endl;
		_getch();
		system("CLS");
		goto Top_Menu;
		break;
	case 5:
		newCar.searchforCar(car);
		utils->mappingObjCarToLine(car);
		cout << "~~~~~> Press enter key to go back to menu of operation." << endl;
		_getch();
		system("CLS");
		goto Top_Menu;
		break;
	case 6:
		utils->mappingObjShowroomsToLine(room);
		newRoom.searchforShowroom(room);
		
		cout << "~~~~~> Press enter key to go back to menu of operation." << endl;
		_getch();
		system("CLS");
		goto Top_Menu;
		break;
	case 7:
		utils->mappingObjGarageToLine(garage);
		newGarage.searchforGarage(garage);
		cout << "~~~~~> Press enter key to go back to menu of operation." << endl;
		_getch();
		system("CLS");
		goto Top_Menu;
		break;
	case 8:
		utils->mappingObjServiceToLine(service);
		newService.searchForService(service);
		cout << "~~~~~> Press enter key to go back to menu of operation." << endl;
		_getch();
		system("CLS");
		goto Top_Menu;
		break;
	case 9:
		utils->mappingObjServiceToLine(service);
		utils->mappingObjToCustomerLine(customer);
		process.bookProcess(service, customer);
		cout << "~~~~~> Press enter key to go back to menu of operation." << endl;
		_getch();
		system("CLS");
		goto Top_Menu;
		break;
	case 0:
		_getch();
		goto Top_Menu;
		break;
	}
}

string Customer::logIn(unordered_map<string, Customer> customer)
{
	string user, pass;
	cout << "\t\t\t\t LOGIN PAGE ...\n\n\n\n";
	cout << "\tEnter Username :: ";
	cin.ignore();
	getline(cin, user);
	cout << "\n\tEnter Password :: ";
	cin >> pass;

	unordered_map <string, Customer> ::iterator it;
	it = customer.find(user);
	while (customer[user].Password != pass || it == customer.end())
	{

		cout << "Wrong Username or Password ... please try again" << endl;
		cout << "***********************************************" << endl;
		cout << "please, Enter your name: " << endl;
		cin >> user;
		cout << "please, Enter your password: " << endl;
		cin >> pass;
		it = customer.find(user);

	}
	return user;
}




