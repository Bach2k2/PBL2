#pragma once
#include <iostream>
#include<string>
#include <fstream>
using namespace std;
class Bill
{
public:
	string MKH;
	int idMeter;
	int prevMeter;
	int afterMeter;
	int unit;
	string nameBill;
	string beginDate;
	string endDate;
	int price;
	
public:
	Bill* next;
	Bill(int=0, string="", int=0, int=0, string="", string="",string="");
	~Bill();
	void setData(const Bill&);
	void enterData();
	friend ostream& operator<<(ostream&, const Bill&);
	void readDataIF(ifstream&);
	void fromString(string str);
	
};

