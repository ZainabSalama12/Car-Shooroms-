#include <iostream>
#include <fstream>
#include "Car.h"
#include "Customer.h"
#include "Showrooms.h"
#include"Utils.h"
#include<unordered_map>
#include"Admin.h"
#include"BuyOrRent.h"
#include"Garages.h"
#include"Service.h"
#include <conio.h>
#include <windows.h>
#include<cstdlib>
using namespace std;
void main() {
	Utils* utils = Utils::getinstance();
	 
	Admin newAdmin;
	Customer newCustomer;

	unordered_map<string, Admin> admin;
	unordered_map<string, Customer> customer;
	unordered_map<string, Car> car;
	unordered_map<string, Garages> garage;
	unordered_map<string, Showrooms> room;
	unordered_map<string, Service> service;

	utils->mappingCarLineToObj(car);
	utils->mappingGarageLineToObj(garage);
	utils->mappingServiceLineToObj(service);
	utils->mappingShowroomsLineToObj(room);
	utils->mappingAdminLineToObj(admin);
	utils->mappingCustomerLineToObj(customer);




	int choiceOfMenue, numOfOperation{};
	string logIn;

Top_menu: choiceOfMenue = utils->loginChoice();

	if (choiceOfMenue == 1)
	{
		system("CLS");
		logIn = newAdmin.logIn(admin);
	Admin_Menu:
		system("CLS");
		numOfOperation = utils->adminOperation();
		if (numOfOperation == 1)
		{
			system("CLS");
			admin[logIn].addNewCar(car);
			utils->mappingObjCarToLine(car);
			cout << "~~~~~> Press enter key to go back to menu of operation." << endl;
			_getch();
			system("CLS");
			goto Admin_Menu;
		}
		if (numOfOperation == 2)
		{
			system("CLS");
	//		utils->mappingObjGarageToLine(garage);
			admin[logIn].addNewGarages(garage);
			utils->mappingObjGarageToLine(garage);
			cout << "~~~~~> Press enter key to go back to menu of operation." << endl;
			_getch();
			system("CLS");
			goto Admin_Menu;
		}
		if (numOfOperation == 3)
		{
			system("CLS");
			admin[logIn].addNewServices(service);
			utils->mappingObjServiceToLine(service);
			cout << "~~~~~> Press enter key to go back to menu of operation." << endl;
			_getch();
			system("CLS");
			goto Admin_Menu;
		}
		if (numOfOperation == 4)
		{
			system("CLS");
			admin[logIn].addNewShowrooms(room);
			utils->mappingObjShowroomsToLine(room);
			cout << "~~~~~> Press enter key to go back to menu of operation." << endl;
			_getch();
			system("CLS");
			goto Admin_Menu;
		}
		if (numOfOperation == 5)
		{
			system("CLS");
			admin[logIn].editAllCarData(car);
			utils->mappingObjCarToLine(car);
			cout << "~~~~~> Press enter key to go back to menu of operation." << endl;
			_getch();
			system("CLS");
			goto Admin_Menu;
		}
		if (numOfOperation == 6)
		{
			system("CLS");
			admin[logIn].editAllGarageData(garage);
			utils->mappingObjGarageToLine(garage);
			cout << "~~~~~> Press enter key to go back to menu of operation." << endl;
			_getch();
			system("CLS");
			goto Admin_Menu;
		}
		if (numOfOperation == 7)
		{
			system("CLS");
			admin[logIn].editAllServiceData(service);
			utils->mappingObjServiceToLine(service);
			cout << "~~~~~> Press enter key to go back to menu of operation." << endl;
			_getch();
			system("CLS");
			goto Admin_Menu;
		}
		if (numOfOperation == 8)
		{
			system("CLS");
			admin[logIn].editAllRoomsData(room);
			utils->mappingObjShowroomsToLine(room);
			cout << "~~~~~> Press enter key to go back to menu of operation." << endl;
			_getch();
			system("CLS");
			goto Admin_Menu;
		}
		if (numOfOperation == 9)
		{
			system("CLS");
			admin[logIn].deleteCar(car);
			utils->mappingObjCarToLine(car);
			cout << "~~~~~> Press enter key to go back to menu of operation." << endl;
			_getch();
			system("CLS");
			goto Admin_Menu;
		}
		if (numOfOperation == 10)
		{
			system("CLS");
			admin[logIn].deleteService(service);
			utils->mappingObjServiceToLine(service);
			cout << "~~~~~> Press enter key to go back to menu of operation." << endl;
			_getch();
			system("CLS");
			goto Admin_Menu;
		}
		if (numOfOperation == 11)
		{
			system("CLS");
			admin[logIn].deleteGarage(garage);
			utils->mappingObjGarageToLine(garage);
			cout << "~~~~~> Press enter key to go back to menu of operation." << endl;
			_getch();
			system("CLS");
			goto Admin_Menu;
		}
		if (numOfOperation == 12)
		{
			system("CLS");
			admin[logIn].deleteRoom(room);
			utils->mappingObjShowroomsToLine(room);
			cout << "~~~~~> Press enter key to go back to menu of operation." << endl;
			_getch();
			system("CLS");
			goto Admin_Menu;
		}
		else
		{
			utils->mappingObjToAdminLine(admin);
			utils->mappingObjCarToLine(car);
			utils->mappingObjGarageToLine(garage);
			utils->mappingObjServiceToLine(service);
			utils->mappingObjShowroomsToLine(room);
			utils->mappingObjToCustomerLine(customer);
			system("CLS");
			goto Top_menu;
		}
	}

	else if (choiceOfMenue == 2)
	{
		system("CLS");
		logIn = newCustomer.logIn(customer);
	Customer_Menu:
		system("CLS");
		numOfOperation = utils->CustomarOperation();
		if (numOfOperation == 1)
		{
			system("CLS");
			customer[logIn].whatToDo();
			cout << "~~~~~> Press enter key to go back to menu of operation.";
			_getch();
			system("CLS");
			goto Customer_Menu;
		}
		if (numOfOperation == 0)
		{
			system("CLS");
			cout << "~~~~~> Press enter key to go back to menu of operation.";
			_getch();
			system("CLS");
			goto Top_menu;
		}
		else
		{

			utils->mappingCarLineToObj(car);
			utils->mappingGarageLineToObj(garage);
			utils->mappingServiceLineToObj(service);
			utils->mappingShowroomsLineToObj(room);
			utils->mappingAdminLineToObj(admin);
			utils->mappingCustomerLineToObj(customer);

			utils->mappingObjToCustomerLine(customer);
			utils->mappingObjCarToLine(car);
			utils->mappingObjGarageToLine(garage);
			utils->mappingObjServiceToLine(service);
			utils->mappingObjShowroomsToLine(room);
			system("CLS");
			goto Top_menu;
		}
	}

	else if (choiceOfMenue == 3) {
		system("CLS");
		Customer newCustomer;
		newCustomer.registers(customer);
		utils->mappingObjToCustomerLine(customer);
		cout << "~~~~~> Press enter key to go back to menu of operation.";
		_getch();
		system("CLS");
		goto Top_menu;
	}
	else if (numOfOperation == 4) {
		_getch();
		goto Top_menu;
		exit(0);
}

	else
	{
		utils->mappingObjToAdminLine(admin);
		utils->mappingObjToCustomerLine(customer);
		utils->mappingObjCarToLine(car);
		utils->mappingObjGarageToLine(garage);
		utils->mappingObjServiceToLine(service);
		utils->mappingObjShowroomsToLine(room);
		system("CLS");
		goto Top_menu;
	}
}