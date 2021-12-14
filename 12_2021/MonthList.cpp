#include "MonthList.h"
MonthList::MonthList()
{
	pHead = NULL;
	pTail = NULL;
	month = 0;
	year = 1900;
}
MonthList::~MonthList()
{}
void MonthList::setMonthAndYear(int month, int year)
{
	this->month = month;
	this->year = year;
}
void MonthList::add(Bill* bill)
{
	if (pHead == NULL)
	{
		pHead = pTail = bill;
	}
	else
	{
		pTail->next = bill;
		pTail = bill;
	}
}
void MonthList::readFile(string path)
{
	ifstream file(path, ios::in);
	if (file.is_open())
	{
		string line;
		while (getline(file, line))
		{
			Bill* bill = new Bill();
			bill->fromString(line);
			if (bill->getMonth() == this->month)
			{
				add(bill);
				cout << "1";
			}
		}
		cout << "data added successfully" << endl;
		file.close();
	}
	else
	{
		cout << "Not success" << endl;
	}
}
void MonthList::displayByMonth()
{
	Bill* bill = pHead;
	cout << "In danh sách ra theo tháng " << this->month << endl;
	if (pHead == NULL)
	{
		cout << "Danh sach rong" << endl;
	}
	else
	{
		while (bill != NULL)
		{
			cout << *bill;
			bill = bill->next;
		}
	}
}
void MonthList::printToFile(string path)
{
	Bill* bill = pHead;
	ofstream file(path);
	if (file.is_open())
	{
		while (bill != NULL)
		{
			file << *bill;
			bill = bill->next;
		}
		cout << "Save file successfully " << endl;
	}
	else
	{
		cout << "Save file unsuccessfully " << endl;
	}
}