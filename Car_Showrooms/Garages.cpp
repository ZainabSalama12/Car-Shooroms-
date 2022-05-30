#include "Garages.h"
#include<iostream>
#include<fstream>
#include<string>
#include<unordered_map>
Garages::Garages() {

}

void Garages::addnewService(string serviceName)
{
		listOfservice.push_back(serviceName);
}

void Garages::searchforGarage(unordered_map<string, Garages> garage)
{
	unordered_map<string, Garages>::iterator it;
	Garages garagee;
	cout << "enter name of garage you want.";
	cin >> garagee.Name;
	it = garage.find(garagee.Name);
	if (it != garage.end())
	{
		cout << "garage id " << it->second.Id << " , garage location : " <<it->second.Location <<" , garage phone : "<<it->second.Phone_Num<<endl;
	}
	else
		cout << "not found" << endl;
}

void Garages::viewListOfGarages(unordered_map<string, Garages>garage)
{
	int counter=0;
	unordered_map<string, Garages>::iterator it;
	vector<string>::iterator itv;
	cout << "\t\t\t\t\t The List Of Garages .\n";
	for (it = garage.begin(); it != garage.end(); it++)
	{
		std::cout << " the name of garage Is :  " << it->second.Name << endl << endl;
		std::cout << " the id of this garage Is :  " << it->second.Id << endl << endl;
		std::cout << " the Location Is :  " << it->second.Location << endl << endl;
		cout << "the Phone number is : " << it->second.Phone_Num << endl << endl;
		cout << "the list of Services in this garage are : ";
		cout << "__________________________________________\n\n";
		for (itv = it->second.listOfservice.begin(); itv != it->second.listOfservice.end(); itv++)
		{
			if (*itv == "null")
			{
				cout << " There is NO Services in this garage \n\n" << endl;
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

Garages::~Garages()
{
}


