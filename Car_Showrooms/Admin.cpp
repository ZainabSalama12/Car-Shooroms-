#include "Admin.h"
#include "Utils.h"

Admin::Admin() {
}

Utils* utils = Utils::getinstance();

void Admin::addNewCar(unordered_map<string, Car>& car)
{
	//int num, valueint;
	string value;
	Car newcar;
	unordered_map <string, Car>::iterator it;
	cout << "Please , Enter the Model Of Car you want to add:";
	cin >> value;
	newcar.Model = value;

	it = car.find(newcar.Model);
	if (it == car.end())
	{
		cout << "Please, Enter Id :";
		cin >> newcar.Id;
		cout << "Please , Enter maker :";
		cin >> newcar.Make;
		cout << "Please , Enter price :";
		cin >> newcar.Price;
		cout << "Please, Enter Year :";
		cin >> newcar.Year;
		cout << "Please, Enter installment";
		cin >> newcar.Installment;
	}
	else
	{
		cout << " this Car is allready exist";
	}
	fstream Myfile;
	Myfile.open("newCar.txt", ios::app);
	if (Myfile.is_open()) {
		Myfile << newcar.Model << "|"<< newcar.Id << "|" << newcar.Make<<"|" << newcar.Year <<"|"<<newcar.Price<<"|"<<newcar.Installment << endl;
		Myfile.close();
	}
	cout << endl;
}

void Admin::addNewGarages(unordered_map<string, Garages>& garage)
{
	int num, valueint;
	string value;
	Garages newgar;
	unordered_map <string, Garages>::iterator it;
	cout << "Please , Enter the name of garage you want to add:";
	cin >> value;
	newgar.Name = value;

	it = garage.find(newgar.Id);
	if (it == garage.end())
	{
		cout << "Please, Enter Id :";
		cin >> newgar.Id;
		cout << "Please , Enter location :";
		cin >> newgar.Location;
		cout << "Please , Enter phone :";
		cin >> newgar.Phone_Num;
		cout << "enter the num of Service you want to add" << endl;
		cin >> num;
		if (num == 0) {
			newgar.addnewService("null");
		}
		else {
			for (int i = 0; i < num; i++)
			{
				string item;
				cout << "enter the name of service" << endl;
				cin >> item;
				newgar.addnewService(item);
			}
		}

	}
	else
	{
		cout << " this Garage is allready exist"<<endl;
	}
	ofstream Myfile;
	Myfile.open("newGarage.txt", ios::app);
	if (Myfile.is_open()) {
		Myfile << newgar.Name << "|" << newgar.Id<< "|" <<newgar.Location << "|" << newgar.Phone_Num << "|[";
		for (int i = 0; i < newgar.listOfservice.size(); i++) {
			Myfile << newgar.listOfservice[i]<<",";
		}
		Myfile << "]" << endl;
		Myfile.close();
	}
}

void Admin::addNewServices(unordered_map<string, Service>& service)
{
	int num, valueint;
	string value;
	Service newService;
	unordered_map <string, Service>::iterator it;
	cout << "Please , Enter the name Of Service you want to add:";
	cin >> value;
	newService.nameService = value;

	it = service.find(newService.nameService);
	if (it == service.end())
	{
		cout << "Please, Enter id :";
		cin >> newService.idService;
		cout << "Please , Enter Price :";
		cin >> newService.priceService;
	}
	else
	{
		cout << " this Service is allready exist";
	}
	fstream Myfile;
	Myfile.open("newService.txt", ios::app);
	if (Myfile.is_open()) {
		Myfile << newService.nameService << "|" << newService.idService << "|" << newService.priceService << endl;
		Myfile.close();
	}


}

void Admin::addNewShowrooms(unordered_map<string, Showrooms>& room)
{
	int num, valueint;
	string value;
	Showrooms newRoom;
	unordered_map <string, Showrooms>::iterator it;
	cout << "Please , Enter the name Of Showroom you want to add:";
	cin >> value;
	newRoom.Name = value;

	it = room.find(newRoom.Name);
	if (it == room.end())
	{
		cout << "Please, Enter id :";
		cin >> newRoom.Id;
		cout << "Please , Enter location :";
		cin >> newRoom.Location;
		cout << "Please , Enter phone number :";
		cin >> newRoom.Phone_Number;
		cout << "enter the num of Cars you want to add" << endl;
		cin >> num;
		if (num == 0) {
			newRoom.addnewCar("null");
		}
		else {
			for (int i = 0; i < num; i++)
			{
				string item;
				cout<<"enter the name of car"<<endl;
				cin >> item;
				newRoom.addnewCar(item);
			}
		}
	}
	else
	{
		cout << " this Service is allready exist";
	}
	fstream Myfile;
	Myfile.open("newShowroom.txt", ios::app);
	if (Myfile.is_open()) {
		Myfile << newRoom.Name << "|" << newRoom.Id << "|" << newRoom.Location << "|" << newRoom.Phone_Number << "|[";
		for (int i = 0; i < newRoom.listOfCars.size(); i++) {
			Myfile << newRoom.listOfCars[i];

		}
		Myfile << "]" << endl;
		Myfile.close();
	}


}



void Admin::editAllCarData(unordered_map<string, Car>& car)
{
	unordered_map<string, Car>::iterator it;
	string nameofCar;
	cout << "What is the car that you want : ";
	cin >> nameofCar;
	it = car.find(nameofCar);
	if (it != car.end())
	{
		int choice, value;;
		string changeValue;
		cout << "Please , Enter the num of data that you want to change it : " << endl;
		cout << "-----------------------------------------------------------" << endl;
		cout << "1- model \n";
		cout << "2- id \n";
		cout << "3- Make\n";
		cout << "4- Year \n";
		cout << "5- Price \n";
		cout << "6- Installment \n";

		cin >> choice;

		switch (choice)
		{
		case 1:
			cout << "Please , Enter Your Change :  ";
			cin >> changeValue;
			car[nameofCar].Model = changeValue;
			changeValue = "";
			break;
		case 2:
			cout << "Please , Enter Your Change :  ";
			cin >> changeValue;
			car[nameofCar].Id = changeValue;
			changeValue = "";
			break;
		case 3:
			cout << "Please , Enter Your Change :  ";
			cin >> changeValue;
			car[nameofCar].Make = changeValue;
			changeValue = "";
			break;
		
	
		case 4:
			cout << "Please , Enter Your Change :  ";
			cin >> changeValue;
			car[nameofCar].Year = changeValue;
			changeValue = "";
			break;
		case 5:
			cout << "Please , Enter Your Change :  ";
			cin >> changeValue;
			 car[nameofCar].Price=changeValue;
			break;
		case 6:
			cout << "Please , Enter Your Change :  ";
			cin >> changeValue;
			car[nameofCar].Installment=changeValue;
			changeValue = "";
			break;

		default:
			break;
		}
	}
	else
	{
		cout << " Sorry , Car not found.... \n";
	}
}

void Admin::editAllGarageData(unordered_map<string, Garages>& garage)
{
	unordered_map<string, Garages>::iterator it;
	string nameofgar;
	cout << "What is the Garage that you want : ";
	cin >> nameofgar;
	it = garage.find(nameofgar);
	if (it != garage.end())
	{
		int choice, value;;
		string changeValue;
		cout << "Please , Enter the num of data that you want to change it : " << endl;
		cout << "-----------------------------------------------------------" << endl;
		cout << "1- name \n";
		cout << "2- id \n";
		cout << "3- location\n";
		cout << "4- phone number \n";

		cin >> choice;

		switch (choice)
		{
		case 1:
			cout << "Please , Enter Your Change :  ";
			cin >> changeValue;
			garage[nameofgar].Name = changeValue;
			changeValue = "";
			break;
		case 2:
			cout << "Please , Enter Your Change :  ";
			cin >> changeValue;
			garage[nameofgar].Id = changeValue;
			changeValue = "";
			break;
		case 3:
			cout << "Please , Enter Your Change :  ";
			cin >> changeValue;
			garage[nameofgar].Location = changeValue;
			changeValue = "";
			break;


		case 4:
			cout << "Please , Enter Your Change :  ";
			cin >> changeValue;
			garage[nameofgar].Phone_Num = changeValue;
			changeValue = "";
			break;

		default:
			break;
		}
	}
	else
	{
		cout << " Sorry , Garage not found.... \n";
	}
}

void Admin::editAllServiceData(unordered_map<string, Service>& service)
{
	unordered_map<string, Service>::iterator it;
	string nameofservice;
	cout << "What is the Service that you want : ";
	cin >> nameofservice;
	it = service.find(nameofservice);
	if (it != service.end())
	{
		int choice, value;;
		string changeValue;
		cout << "Please , Enter the num of data that you want to change it : " << endl;
		cout << "-----------------------------------------------------------" << endl;
		cout << "1- name \n";
		cout << "2- id \n";
		cout << "5- Price \n";

		cin >> choice;

		switch (choice)
		{
		case 1:
			cout << "Please , Enter Your Change :  ";
			cin >> changeValue;
			service[nameofservice].nameService = changeValue;
			changeValue = "";
			break;
		case 2:
			cout << "Please , Enter Your Change :  ";
			cin >> changeValue;
			service[nameofservice].idService = changeValue;
			changeValue = "";
			break;
		case 3:
			cout << "Please , Enter Your Change :  ";
			cin >> changeValue;
			service[nameofservice].priceService = stoi(changeValue);
			changeValue = "";
			break;

		default:
			break;
		}
	}
	else
	{
		cout << " Sorry , Service not found.... \n";
	}
}

void Admin::editAllRoomsData(unordered_map<string, Showrooms>& room)
{
	unordered_map<string, Showrooms>::iterator it;
	string nameofroom;
	cout << "What is the Room that you want : ";
	cin >> nameofroom;
	it = room.find(nameofroom);
	if (it != room.end())
	{
		int choice, value;;
		string changeValue;
		cout << "Please , Enter the num of data that you want to change it : " << endl;
		cout << "-----------------------------------------------------------" << endl;
		cout << "1- name \n";
		cout << "2- id \n";
		cout << "3- location\n";
		cout << "4- phone number \n";

		cin >> choice;

		switch (choice)
		{
		case 1:
			cout << "Please , Enter Your Change :  ";
			cin >> changeValue;
			room[nameofroom].Name = changeValue;
			changeValue = "";
			break;
		case 2:
			cout << "Please , Enter Your Change :  ";
			cin >> changeValue;
			room[nameofroom].Id = changeValue;
			changeValue = "";
			break;
		case 3:
			cout << "Please , Enter Your Change :  ";
			cin >> changeValue;
			room[nameofroom].Location = changeValue;
			changeValue = "";
			break;


		case 4:
			cout << "Please , Enter Your Change :  ";
			cin >> changeValue;
			room[nameofroom].Phone_Number = changeValue;
			changeValue = "";
			break;

		default:
			break;
		}
	}
	else
	{
		cout << " Sorry , Room not found.... \n";
	}
}



void Admin::deleteCar(unordered_map<string, Car>& car)
{
	unordered_map<string, Car>::iterator it;
	Car carr;
	cout << "enter name of Car you want. ";
	cin >> carr.Model;
	it = car.find(carr.Model);
	if (it != car.end())
	{
		car.erase(it->second.Model);
		ofstream Myfile;
		Myfile.open("newCar.txt", ios::trunc);
		Myfile.close();
		utils->mappingCarLineToObj(car);
	}
	else
	{
		cout << "not found" << endl;
	}
	
}

void Admin::deleteGarage(unordered_map<string, Garages>& garage)
{
	unordered_map<string, Garages>::iterator it;
	Garages garagee;
	cout << "enter name of garage you want." << endl;
	cin >> garagee.Name;
	it = garage.find(garagee.Name);
	if (it != garage.end())
	{
		garage.erase(it->second.Name);
		ofstream Myfile;
		Myfile.open("newGarage.txt", ios::trunc);
		Myfile.close();
		utils->mappingGarageLineToObj(garage);
	}
	else
	{
		cout << "not found"<<endl;
	}
}

void Admin::deleteService(unordered_map<string, Service>& service)
{
	unordered_map<string, Service>::iterator it;
	Service serv;
	cout << "enter name of service you want." << endl;
	cin >> serv.nameService;
	it = service.find(serv.nameService);
	if (it != service.end())
	{
		service.erase(it->second.nameService);
		ofstream Myfile;
		Myfile.open("newService.txt", ios::trunc);
		Myfile.close();
		utils->mappingServiceLineToObj(service);
	}
	else
	{
		cout << "not found"<<endl;
	}
}

void Admin::deleteRoom(unordered_map<string, Showrooms>& room)
{
	unordered_map<string, Showrooms>::iterator it;
	Showrooms roomm;
	cout << "enter name of room you want." << endl;
	cin >> roomm.Name;
	it = room.find(roomm.Name);
	if (it != room.end())
	{
		room.erase(it->second.Name);
		ofstream Myfile;
		Myfile.open("newShowroom.txt", ios::trunc);
		Myfile.close();
		utils->mappingShowroomsLineToObj(room);
	}
	else
	{
		cout << "not found"<<endl;
	}
}


string Admin::logIn(unordered_map<string, Admin> admin)
{
	string user, pass;
	cout << "\t\t\t\t LOGIN PAGE ...\n\n\n\n";
	cout << "\tEnter Username :: ";
	cin.ignore();
	getline(cin, user);
	cout << "\n\tEnter Password :: ";
	cin >> pass;

	unordered_map <string, Admin> ::iterator it;
	it = admin.find(user);
	while (admin[user].password != pass || it == admin.end())
	{

		cout << "Wrong Username or Password ... please try again" << endl;
		cout << "***********************************************" << endl;
		cout << "please, Enter your name: " << endl;
		cin >> user;
		cout << "please, Enter your password: " << endl;
		cin >> pass;
		it = admin.find(user);

	}
	return user;
}
