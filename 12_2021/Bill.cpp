#include "Bill.h"
#include "UnitPrice.h"
#include <cstring>
using namespace std;

Bill::Bill()
{
	this->meterNumber = 0;
	nameBill = " ";
	prevMeter = 0;
	nextMeter = 1;
	this->next = NULL;
	this->unit = nextMeter - prevMeter;
	this->price = 0;
}
Bill::Bill(int idMeter, string name, int prevUnit, int afterUnit, Date beginDate, Date endDate, string MKH) : meterNumber(idMeter), nameBill(name), prevMeter(prevUnit), nextMeter(afterUnit), beginDate(beginDate), endDate(endDate), customerId(MKH)
{

	this->next = NULL;
	this->unit = nextMeter - prevMeter;
	this->price = 0;
}
Bill::~Bill() {}
Bill::Bill(const Bill &bill)
{
	this->meterNumber = bill.meterNumber;
	this->nameBill = bill.nameBill;
	this->prevMeter = bill.prevMeter;
	this->nextMeter = bill.nextMeter;
	this->beginDate = bill.beginDate;
	this->endDate = bill.endDate;
	this->unit = bill.unit;
	this->price = bill.price;
	this->next = bill.next;
	this->customerId = bill.customerId;
}
ostream &operator<<(ostream &out, const Bill &bill)
{
	out << " "
		<< bill.meterNumber
		<< "|\t" << bill.nameBill
		<< "|\t" << bill.beginDate
		<< "|\t" << bill.endDate
		<< "|\t " << bill.prevMeter
		<< "|\t " << bill.nextMeter
		<< "|\t " << bill.unit
		<< "|\t  " << bill.price
		<< "|\t " << bill.customerId << endl;
	return out;
}
void Bill::copyData(const Bill &bill)
{
	this->customerId = bill.customerId;
	this->nameBill = bill.nameBill;
	this->beginDate = bill.beginDate;
	this->endDate = bill.endDate;
	this->prevMeter = bill.prevMeter;
	this->nextMeter = bill.nextMeter;
	this->unit = bill.unit;
	this->price = bill.price;
}
void Bill::enterData()
{
	bool check = true;
	string nameBill;
	do
	{
		cin.ignore(32767, '\n');
		cout << "Name of bill: ";
		getline(cin, nameBill);
		if (nameBill == "" || nameBill == "\n")
		{
			check = false;
			cout << "enter again!";
		}
		else
		{
			check = true;
		}

	} while (!check);
	this->nameBill = nameBill;
	Date date1;
	do
	{
		cin.ignore(32767, '\n');
		cout << "The Begin Date: ";
		int DD, MM, YY;
		cout << "Enter day:";
		cin >> DD;
		cout << "Enter month: ";
		cin >> MM;
		cout << "Enter year: ";
		cin >> YY;
		date1.setDate(DD, MM, YY);
		this->beginDate = date1;
	} while (!check);
	do
	{
		cout << "The End Date: ";
		Date date2;
		date2 = date1 += 30;
		this->endDate = date2;
		cout << endDate << endl;
	} while (!check);
	do
	{
		cout << "Enter the last unit: ";
		cin >> this->prevMeter;
		if (this->prevMeter <= 0)
		{
			cout << "Enter again !" << endl;
			check = false;
		}
		else
		{
			check = true;
		}
	} while (!check);
	do
	{
		cout << "Enter the next unit: ";
		cin >> this->nextMeter;
	} while (this->nextMeter <= 0 || this->nextMeter < this->prevMeter);
	do
	{
		cout << "Customer id: " << endl;
		cin >> this->customerId;
		if (this->customerId == " " || this->customerId == "\n")
		{
			cout << "Enter again !" << endl;
			check = false;
		}
		else
		{
			check = true;
		}
	} while (!check);
	this->unit = nextMeter - prevMeter;
	this->price = 0;
	this->next = NULL;
}
void Bill::fromString(string str)
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

	this->prevMeter = stof(arr[length - 5]);
	this->nextMeter = stof(arr[length - 4]);
	string date1 = arr[length - 3];
	string number;
	string numstr[3];
	int count1 = 0;
	for (int i = 0; i <= date1.size(); i++)
	{
		if ((date1[i] != '/') && (i != date1.size()))
			number += date1[i];
		else
		{
			numstr[count1] = number;
			count1++;
			number = "";
		}
	}
	/*
	* 	for (int i = 0; i < 3; i++)
	{
		std::cout << numstr[i] << " ";
	}
	*/

	int DD = stof(numstr[0]);
	int MM = stof(numstr[1]);
	int YY = stof(numstr[2]);
	this->beginDate.setDate(DD, MM, YY);

	string date2 = arr[length - 2];
	count1 = 0;
	for (int i = 0; i <= date2.size(); i++)
	{
		if ((date2[i] != '/') && (i != date2.size()))
			number += date2[i];
		else
		{
			numstr[count1] = number;
			count1++;
			number = "";
		}
	}
	DD = stof(numstr[0]);
	MM = stof(numstr[1]);
	YY = stof(numstr[2]);
	this->endDate.setDate(DD, MM, YY);
	this->customerId = arr[length - 1];
	this->meterNumber = stof(arr[0]);

	for (int i = 1; i < length - 5; i++)
	{
		this->nameBill += arr[i];
		this->nameBill += ' ';
	}
	this->nameBill = this->nameBill.substr(0, nameBill.length() - 1);
	this->unit = this->nextMeter - this->prevMeter;
	this->month = beginDate.getMonth();
}
void Bill::readDataIF(ifstream &input)
{
	int MKH;
	input >> MKH;

	string billName;
	input >> billName;

	int prevUnit;
	input >> prevUnit;

	int afterUnit;
	input >> afterUnit;

	string beginDate;
	input >> beginDate;

	string endDate;
	input >> endDate;
}
void Bill::setPrice(double price)
{
	this->price = price;
}
void Bill::setMeterNumber(int meterNumber)
{
	this->meterNumber = meterNumber;
}
void Bill::setPrevMeter(int prevMeter)
{
	this->prevMeter = prevMeter;
}
void Bill::setNextMeter(int nextMeter)
{
	this->nextMeter = nextMeter;
}
void Bill::setCustomerid(string id)
{
	this->customerId = id;
}