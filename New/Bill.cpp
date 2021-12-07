#include"Bill.h"
#include "UnitPrice.h"
#include <cstring>
using namespace std;
Bill::Bill(int idMeter, string name, int prevUnit, int afterUnit, string beginDate, string endDate, string MKH) :
	idMeter(idMeter), nameBill(name), prevMeter(prevUnit), afterMeter(afterUnit), beginDate(beginDate), endDate(endDate), MKH(MKH)
{

	this->next = NULL;
	this->unit = afterMeter - prevMeter;
	this->price = 0;
}
Bill::~Bill() {}

ostream& operator<<(ostream& out, const Bill& bill)
{
	out << "Bill: "
		<< ", id : " << bill.idMeter
		<< ", name: " << bill.nameBill
		<< ", beginDate: " << bill.beginDate
		<< ", end Date" << bill.endDate
		<< ", previous unit: " << bill.prevMeter
		<< ", after unit: " << bill.afterMeter
		<< ", unit : " << bill.unit
		<< ", Price: " << bill.price
		<< ", MKH: " << bill.MKH << endl;
	return out;
}
void  Bill::setData(const Bill& bill)
{
	this->MKH = bill.MKH;
	this->nameBill = bill.nameBill;
	this->beginDate = bill.beginDate;
	this->endDate = bill.endDate;
	this->prevMeter = bill.prevMeter;
	this->afterMeter = bill.afterMeter;
	this->unit = bill.unit;
	this->price = bill.price;
}
void Bill::enterData()
{
	string nameBill;
	do
	{
		cin.ignore(32767, '\n');
		cout << "Name of bill: ";
		getline(cin, nameBill);
		if (nameBill == "" || nameBill == "\n")
			cout << "enter again!";
	} while (nameBill == "" || nameBill == "\n");
	this->nameBill = nameBill;
	do
	{
		//cin.ignore(32767, '\n');
		cout << "The Begin Date: ";
		cin >> this->beginDate;
	} while (this->beginDate == " " || this->beginDate == "\n");

	do
	{
	//	cin.ignore(32767, '\n');
		cout << "The End Date: ";
		cin >> this->endDate;
	} while (this->endDate == " " || this->endDate == "\n");
	do
	{
		cout << "Enter the last unit: ";
		cin >> this->prevMeter;
	} while (this->prevMeter <= 0);
	do
	{
		cout << "Enter the next unit: ";
		cin >> this->afterMeter;
	} while (this->afterMeter <= 0 || this->afterMeter < this->prevMeter);
	do
	{
		cout << "Customer id: ";
		cin >> this->MKH;
	} while (this->MKH !=" ");
	this->unit = afterMeter - prevMeter;
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
	this->idMeter = stof(arr[0]);
	this->prevMeter = stof(arr[length - 5]);
	this->afterMeter = stof(arr[length - 4]);
	this->beginDate = arr[length - 3];
	this->endDate = arr[length - 2];
	this->MKH = arr[length - 1];
	for (int i = 0; i < length; i++)
	{
		cout << arr[i]<<" ";
	}
	this->nameBill = this->nameBill.substr(0, nameBill.length() - 1);
	for (int i = 1; i < length - 5; i++)
	{
		this->nameBill += arr[i];
		this->nameBill += ' ';
	}
	this->nameBill = this->nameBill.substr(0, nameBill.length() - 1);
}
void Bill::readDataIF(ifstream& input)
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
