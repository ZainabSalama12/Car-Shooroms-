#pragma once
#include <iostream>
#include<vector>
using namespace std;
#include<unordered_map>

class Service
{
public:
	string idService;
	string nameService;
	int priceService;
	vector<string>listOfService;

	Service();
	void searchForService(unordered_map<string, Service>service);
	void addnewService(string serviceName);

};