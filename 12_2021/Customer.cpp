#include "Customer.h"
#include <iostream>
#include <string>
#include<fstream>
using namespace std;
Customer::Customer(string MKH, string customerName, int age, string address, string phoneNum) :
	customerId(MKH), customerName(customerName), age(age), address(address), phoneNum(phoneNum)
{
	this->next = NULL;
}
Customer::~Customer() {}
void Customer::setCustomerId(string customerId)
{
	this->customerId = customerId;
}
void Customer::setCustomerName(string name){
	customerName = name;
}
void Customer::setAge(int age)
{
	this->age = age;
}
void Customer::setAddress(string address)
{
	this->address = address;
}
void Customer::setPhoneNumber(string phoneNum)
{
	this->phoneNum = phoneNum;
}
// tạo tất cả thông tin
void Customer::setData()
{
	bool check = true;
	string customerName;
	do
	{
		cout << "Enter the name of customer";
		cin.ignore(32767, '\n');
		getline(cin, customerName);
		if (customerName == "\n" || customerName == " ")
		{
			check = false;
			cout << "Nhap lai" << endl;
		}
		else check = true;
	} while (!check);
	this->customerName = customerName;
	do
	{
		cout << "Age: ";
		cin >> this->age;
	} while (this->age <= 0);
	string address;
	do
	{
		cout << "Enter address: ";
		cin.ignore(32767, '\n');
		getline(cin, address);
		if (address == "\n" || address == " ")
		{
			check = false;
			cout << "Nhap lai" << endl;
		}
		else check = true;
	} while (!check);
	this->address = address;

	string phoneNumber;
	do
	{
		cout << "Enter phone number: ";
		cin.ignore(32767, '\n');
		getline(cin, phoneNumber);
		for (int i = 0; i < phoneNumber.size(); i++)
		{
			if (!isdigit(phoneNumber[i])) { check = false; break; }
			check = true;
		}
		if (phoneNumber == "\n" || phoneNumber == " ")check = false;
		else
		{
			check = true;
		}
	} while (!check);
	this->phoneNum = phoneNumber;
}
ostream& operator<<(ostream& o, const Customer& cus)
{
	o << "Customer:  Ma Khach Hang: " << cus.customerId
		<< ",Ten khach hang: " << cus.customerName
		<< ", age: " << cus.age
		<< ", address: " << cus.address
		<< ", phone number: " << cus.phoneNum << endl;
	return o;
}
void Customer::fromString(string str)
{
	string arr[10];
	int count = 0;
	string word;
	for (int i = 0; i <= str.length(); i++)
	{
		if (str[i] == ' ' || i == str.length())
		{

			arr[count++] = word;
			word = "";
		}
		else
		{
			word += str[i];
		}
	}
	int length = count;
	cout << count;
	this->phoneNum = arr[length - 1];
	this->address = arr[length - 2];
	this->age = stof(arr[length - 3]);
	for (int i = 1; i < length - 3; i++)
	{
		this->customerName += arr[i];
		this->customerName += ' ';
	}
	this->customerName = this->customerName.substr(0, customerName.length() - 1);
	this->customerId = arr[0];
}

