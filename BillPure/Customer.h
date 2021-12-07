#pragma once
#include <iostream>
using namespace std;
class Customer {
	public:
		int MKH;
		static int increment;
		int age;
		string customerName;
		string phoneNum;
		string address;
		Customer* next;
public:

	Customer();
	~Customer();
	Customer(int,string,string,string);
	Customer(const Customer&);
	//get va set
	};

