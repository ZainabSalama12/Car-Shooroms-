#pragma once
#include<iostream>
#include<string.h>
#include<unordered_map>
#include"Car.h"
using namespace std;
class BuyOrRent
{
public:
	int processId;
	int cusotmarId;
	string date;
	double priceOfProcesser;
	int chosenCar;
	BuyOrRent();
	~BuyOrRent();
	void BuyorRent(unordered_map<string, Car>car);


};

