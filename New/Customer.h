#pragma once
#include <iostream>
using namespace std;
class Customer
{
public:
	string MKH;
	int age;
	string customerName;
	string phoneNum;
	string address;
	public:

	Customer *next;

public:
	Customer(string="", string = "", int = 0, string = "", string = "");
	Customer(const Customer &);
	~Customer();
	friend ostream &operator<<(ostream &, Customer &);
	void fromString(string);
	// get va set
	void setData();
};
