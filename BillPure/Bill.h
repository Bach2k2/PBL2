#pragma once
#include<string>
using namespace std;
class Bill
{
public:
	static int increment;
	int MKH;
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
	Bill();
	Bill(int, string,int,int,string,string);
	~Bill();
	friend ostream& operator<<(ostream&, const Bill&);
};

