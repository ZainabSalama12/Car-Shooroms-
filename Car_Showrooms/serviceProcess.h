#pragma once
#include"Service.h"
#include"Customer.h"
class serviceProcess
{	
public:
	string Id_process;
	 string Id_customer;
	string Date;
	double amountOfMoney;
	string nameService;

	serviceProcess();
	~serviceProcess();

	void bookProcess(unordered_map<string,Service>service,unordered_map<string,Customer>customer);

};

