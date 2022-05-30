#include"Service.h"
#include<fstream>
#include<string> 

Service::Service()
{
}


void Service::searchForService(unordered_map<string, Service> service)
{
	unordered_map<string, Service>::iterator it;
	Service servicee;
	cout << "enter name of Service you want." << endl;
	cin >> servicee.nameService;
	it = service.find(servicee.nameService);
	if (it != service.end())
	{
		cout << "service id : " << it->second.idService << " , service price : " << it->second.priceService << endl;
	}
	else
		cout << "not found" << endl;
}

void Service::addnewService(string serviceName)
{
	listOfService.push_back(serviceName);
}


