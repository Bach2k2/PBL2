#include "Customer.h"
int Customer::increment = 1;
Customer::Customer()
{
	this->MKH = increment++;
	this->age = 0;
	this->address = "";
	this->phoneNum = "";
	this->customerName = "";
	this->next = NULL;
}
Customer::Customer(int age,string address,string phoneNum,string customerName):
	age(age),address(address),customerName(customerName),phoneNum(phoneNum)
{
	this->MKH = increment++;
	this->next = NULL;
}
