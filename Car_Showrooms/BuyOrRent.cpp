#include "BuyOrRent.h"
#include<unordered_map>
BuyOrRent::BuyOrRent()
{
}

BuyOrRent::~BuyOrRent()
{
}

void BuyOrRent::BuyorRent(unordered_map<string,Car>car)
{
	unordered_map<string, Car>::iterator it;
	Car carr;
//	string id;
	cout<<"enter model of Car you want."<<endl;
	cin >> carr.Model;
	it = car.find(carr.Model);	
	if (it != car.end())
	{
		cout << "the price of this car is " << it->second.Price << endl;
		int num;
		cout << "to confirm enter 1" << endl;
		cout << "to exit enter 0" << endl;
		cin >> num;
		switch (num)
		{
		case 1:
			cout << "now you can buy or rent this car." << endl;
			break;
		case 0:
			break;
		default:
			break;
		}
	}
	
	else {
		cout << "not found" << endl;
	}
}
