#pragma once
#include<iostream>
#include<fstream>
#include<string.h>
#include<unordered_map>
#include<string>
using namespace std;
class Car
{
public :
	string Id;
	string Make;
	string Model;
	string Year;
	string Price;
	string Installment;

	Car();
	void viewListOfCars(unordered_map<string, Car>car);
	void searchforCar(unordered_map<string, Car>car);
	~Car();
};

