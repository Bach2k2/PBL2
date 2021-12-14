#include "BillService.h"
#include<iostream>
#include <string>
using namespace std;
class MonthList
{
private:

	int month;
	int year;
	Bill* pHead;
	Bill* pTail;
public:
	
	MonthList();
	~MonthList();
	void setMonthAndYear(int, int);
	void add(Bill*);
	void readFile(string);// Doc file
	void displayByMonth();
	void printToFile(string);// Nhap duong dan de in file
	int getMonth();
	int getYear();
};

