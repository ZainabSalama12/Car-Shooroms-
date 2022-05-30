#pragma once
#include<string>
#include<vector>
#include<unordered_map>
using namespace std;
class Garages
{
public :
	string Id;
	string Name;
	string Location;
	string Phone_Num;
	vector<string>listOfservice;


	Garages();
	void addnewService(string serviceName);
	void searchforGarage(unordered_map<string, Garages> garage);
	void viewListOfGarages(unordered_map<string, Garages> garage);
	~Garages();
};

