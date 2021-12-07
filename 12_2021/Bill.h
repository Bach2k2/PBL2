#include"Date.h"
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
	Date beginDate;
	Date endDate;
	double price;
	
public:
	Bill* next;
	Bill();
	Bill(int, string, int, int, Date, Date, string);
	~Bill();
	void copyData(const Bill&);
	void enterData();
	friend ostream& operator<<(ostream&, const Bill&);
	void readDataIF(ifstream&);
	void fromString(string str);
	// Get price;
	void setPrice(double);
};

