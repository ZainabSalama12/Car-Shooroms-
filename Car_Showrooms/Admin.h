#pragma once
#include<iostream>
#include<unordered_map>
#include"Car.h"
#include<string>
#include"Garages.h"
#include"Service.h"
#include"Showrooms.h"
#include<fstream>
using namespace std;


class Admin
{
public :
	int Id;
	string Username;
	string password;
	Admin();
	void addNewCar(unordered_map<string, Car>& car);
	void addNewGarages(unordered_map<string, Garages>& garage);
	void addNewServices(unordered_map<string, Service>& service);
	void addNewShowrooms(unordered_map<string, Showrooms>& room);

	void editAllCarData(unordered_map<string, Car>& car);
	void editAllGarageData(unordered_map<string, Garages>& garage);
	void editAllServiceData(unordered_map<string, Service>& service);
	void editAllRoomsData(unordered_map<string, Showrooms>& room);

	void deleteCar(unordered_map<string, Car>& car);
	void deleteGarage(unordered_map<string, Garages>& garage);
	void deleteService(unordered_map<string, Service>& service);
	void deleteRoom(unordered_map<string, Showrooms>& room);

	string logIn(unordered_map<string, Admin> admin);




};

