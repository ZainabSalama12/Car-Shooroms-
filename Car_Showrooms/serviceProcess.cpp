#include "serviceProcess.h"


serviceProcess::serviceProcess()
{

}

serviceProcess::~serviceProcess()
{
}


void serviceProcess::bookProcess(unordered_map<string, Service>service, unordered_map<string, Customer>customer) {
	unordered_map<string, Service>::iterator itS;
	unordered_map<string, Customer>::iterator itC;
	cout << "enter name of service : " << endl;
	Service servicee;
	cin >> servicee.nameService;
	itS = service.find(servicee.nameService);
	 nameService= servicee.nameService;
	if (itS != service.end())
	{
		cout << "enter name of customer : " << endl;
		Customer customerr;
		cin >> customerr.Username;
		itC = customer.find(customerr.Username);
		Id_customer = itC->second.Password;
		if (itC != customer.end()) {
			cout << "enter  date : " << endl;
			cin >> Date;
			cout << "enter the amount of money  : " << endl;
			cin >> amountOfMoney;
			Id_process = itS->second.idService;
			cout << "Welcome, Now you can book this Service." << endl;
			cout << "Service ID is : " << Id_process << " , your ID is : " << Id_customer << " , its Money is : " << amountOfMoney << " and the name of Service is " << nameService << endl;
		}
		else {
			cout << "customer not found." << endl;
		}
	}
	else {
		cout << "service not found." << endl;
		}
}


	


