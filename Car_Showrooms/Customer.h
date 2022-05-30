#pragma once
#include<iostream>
#include"Car.h"
#include"BuyOrRent.h"
#include"Showrooms.h"
#include"Garages.h"
#include"Service.h"
#include<fstream>
#include<string>
using namespace std;
class Customer
{
public :
	string Id;
	string Username;
	string Password;
	string What;

	Customer();
	void whatToDo();
	string logIn(unordered_map<string, Customer> customer);
	void registers(unordered_map<string, Customer>customer);
};

