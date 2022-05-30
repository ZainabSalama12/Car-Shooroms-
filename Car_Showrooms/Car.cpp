#include "Car.h"
#include<iostream>
#include<fstream>
#include<string>
#include<unordered_map>
using namespace std;

Car::Car()
{
}


void Car::viewListOfCars(unordered_map<string, Car>car)
{
	unordered_map<string, Car>::iterator it;
	cout << "\t\t\t\t\t The List Of Cars .\n";
	for (it = car.begin(); it != car.end(); it++)
	{
		std::cout << " the model of car Is :  " << it->second.Model<< endl << endl;
		std::cout << " the id of car Is :  " << it->second.Id << endl << endl;
		std::cout << " the make of car Is :  " << it->second.Make << endl << endl;
		cout << "the year of car is : " << it->second.Year << endl << endl;
		std::cout << " the price of car Is : " << it->second.Price << endl << endl;
		cout << "__________________________________________\n\n";
	}
}


Car::~Car()
{
}

void Car::searchforCar(unordered_map<string, Car> car)
{
	unordered_map<string, Car>::iterator it;
	Car carr;
	//	string id;
	cout << "enter model of Car you want." << endl;
	cin >> carr.Model;
	it = car.find(carr.Model);
	if (it != car.end())
	{
		cout << "car id: " << it->second.Id << " , car maker: " << it->second.Make << " , car year: " << it->second.Year << " , car price :" << it->second.Price<<" , car installment : "<<it->second.Installment<<endl;
	}
	else
		cout << "not found" << endl;
}


