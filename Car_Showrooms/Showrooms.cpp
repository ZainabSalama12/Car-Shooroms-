#include "Showrooms.h"
#include "Car.h"
#include<iostream>
#include<fstream>
#include<string>

void Showrooms::addnewCar(string carName)
{
		listOfCars.push_back(carName);	
}

Showrooms::Showrooms() {

}


void Showrooms:: searchforShowroom(unordered_map<string, Showrooms> room)
{
	unordered_map<string, Showrooms>::iterator it;
	Showrooms roomm;
	cout << "enter name of Room you want." << endl;
	cin >> roomm.Name;
	it = room.find(roomm.Name);
	if (it != room.end())
	{
		cout << "room id : " << it->second.Id << " , room location : " << it->second.Location<<endl;
	}
	else {
		cout << "not found" << endl;
	}
}


void Showrooms::viewListOfRooms(unordered_map<string, Showrooms>room)
{
	int counter=0;
	unordered_map<string, Showrooms>::iterator it;
	vector<string>::iterator itv;
	cout << "\t\t\t\t\t The List Of Cars .\n";
	for (it = room.begin(); it != room.end(); it++)
	{
		std::cout << " the name of room Is :  " << it->second.Name << endl << endl;
		std::cout << " the id of this room Is :  " << it->second.Id << endl << endl;
		std::cout << " the Location Is :  " << it->second.Location << endl << endl;
		cout << "the Phone number is : " << it->second.Phone_Number << endl << endl;
		cout << "the list of cars in this room are : ";
		cout << "__________________________________________\n\n";
		for (itv = it->second.listOfCars.begin(); itv != it->second.listOfCars.end(); itv++)
		{
			if (*itv == "null")
			{
				cout << " There is NO Cars in this room \n\n" << endl;
				break;
			}
			else
			{
				counter++;
				std::cout << counter << " - " << *itv << endl << endl;
			}
		}
	}
}


