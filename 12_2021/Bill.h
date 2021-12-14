#include"Date.h"
#include <iostream>
#include<string>
#include <fstream>
using namespace std;
class Bill
{
private:
	string customerId;
	int meterNumber;
	int prevMeter;
	int nextMeter;
	int unit;
	string nameBill;
	Date beginDate;
	Date endDate;
	double price;
	int month;
	
public:
	Bill* next;
	Bill();
	Bill(int, string, int, int, Date, Date, string);
	Bill(const Bill&);
	~Bill();
	void copyData(const Bill&);
	void enterData();
	friend ostream& operator<<(ostream&, const Bill&);
	void readDataIF(ifstream&); 
	void fromString(string str);// Tách dữ liệu  
	// get and set
	// Get price;
	void setPrice(double);
	void setCustomerid(string);
	void setMeterNumber(int);
	void setPrevMeter(int);
	void setNextMeter(int);
	string getCustomerId(){return customerId;}
	int getMeterNumber(){return meterNumber;}
	int getPrevMeter(){return prevMeter;}
	int getNextMeter(){ return nextMeter;}
	int getUnit(){ return unit;}
	int getMonth(){return this->month;}
	Date& getBeginDate(){return beginDate;}
	Date& getEndDate(){return endDate;}
	double getPrice(){return price;}
};



