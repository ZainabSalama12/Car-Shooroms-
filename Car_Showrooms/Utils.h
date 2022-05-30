#pragma once
#include <stdlib.h>
#include <string>
#include <vector>
#include<unordered_map>
#include"Car.h"
#include "Showrooms.h"
#include "Service.h"
#include "Garages.h"
#include "Admin.h"
#include"Customer.h"
using namespace std;
class Utils
{
private:
	Utils();
	
public:
	static Utils* instance;
	static Utils* getinstance();
	string DATABASE_PATH = "C:/Users/Lenovo/source/repos/Car_Showrooms/Database";
	vector<string> getVectorFromLine(string line);

	void mappingAdminLineToObj(unordered_map<string, Admin>& admin);
	void mappingObjToAdminLine(unordered_map<string, Admin>& newAdmin);

	void mappingCustomerLineToObj(unordered_map<string, Customer>& customer);  
	void mappingObjToCustomerLine(unordered_map<string, Customer> customer); 



	void mappingCarLineToObj(unordered_map<string, Car> &car);
	void mappingGarageLineToObj(unordered_map<string, Garages>& garage);
	void mappingServiceLineToObj(unordered_map<string, Service>& service);
	void mappingShowroomsLineToObj(unordered_map<string, Showrooms>& room);

	void mappingObjCarToLine(unordered_map<string, Car>& car);
	void mappingObjGarageToLine(unordered_map<string, Garages>& garage);
	void mappingObjServiceToLine(unordered_map<string, Service>& service);
	void mappingObjShowroomsToLine(unordered_map<string, Showrooms>& room);

	int loginChoice();
	int adminOperation();
	int CustomarOperation();

	
};