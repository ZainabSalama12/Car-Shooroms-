#pragma once
#include "Car.h"
#include<iostream>
#include<fstream>
#include<string>
#include<vector>
using namespace std;
class Showrooms
{
public :
	string Id;
	string Name;
	string Location;
	string Phone_Number;
	vector<string> listOfCars;

	Showrooms();
	void searchforShowroom(unordered_map<string, Showrooms> room);
	void viewListOfRooms(unordered_map<string, Showrooms> room);
	void addnewCar(string carName);

	
};

