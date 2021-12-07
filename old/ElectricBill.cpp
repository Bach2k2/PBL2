#include "ElectricBill.h"
#include<string>
#include<fstream>
static int s_generationId = 100;
ElectricBill::ElectricBill()
{
    setBillId();
    this->customerId = 1;
    this->billName = "";
    this->unit = 0;
    this->endDate = "";
    this->cost = 0;
}
ElectricBill::ElectricBill(string billName, string beginDate,string endDate, int customerId,string customerName,string address,string phone,int unit)
    :billName(billName),beginDate(beginDate),endDate(endDate),customerId(customerId),customerName(customerName),address(address),phoneNumber(phone),unit(unit)
{
    setBillId();
    calculateCost();
}

//set
void ElectricBill::setBillId()
{
    this->billId = s_generationId++;
}
void ElectricBill::setBillName(string name)
{
    this->billName = name;
}
void ElectricBill::setBeginDate(string date)
{
    this->beginDate = date;
}
void ElectricBill::setEndDate(string date)
{
    this->endDate = date;
}

void ElectricBill::setCustomerId(int id)
{
    this->customerId = id;
}
void ElectricBill::setCustomerName(string name)
{
    this->customerName = name;
}
void ElectricBill::setCustomerAddress(string address)
{
    this->address = address;
}
void ElectricBill::setPhoneNumber(string phoneNum)
{
    this->phoneNumber = phoneNum;
}

void ElectricBill::setUnit(int number)
{
    this->unit = number;
    calculateCost();
}

void ElectricBill::printToFile(ofstream& o)
{
    o << billId << " \t \t| ";
    o << billName << " \t \t|";
    o << beginDate << " \t \t|";
    o << endDate << " \t \t|";
    o << customerId << "\t \t|";
    o << customerName << "\t \t|";
    o << address << "\t \t|";
    o << phoneNumber << "\t \t|";
    o << unit << "\t \t|";
    o << cost<<endl;
}
// Nhập bằng file:
void ElectricBill::setByFile(ifstream &input)
{
    string billName;
    input>>billName;
    setBillName(billName);

    string beginDate;
    input >> beginDate;
    setBeginDate(beginDate);

    string endDate;
    input >> endDate;
    setEndDate(endDate);

    int customerId;
    input >> customerId;
    setCustomerId(customerId);

    string customerName;
    input >> customerName;
    setCustomerName(customerName);

    string address;
    input >>address;
    setCustomerAddress(address);

    string phoneNum;
    input >>phoneNum;
    setPhoneNumber(phoneNum);

    int unit;
    input >> unit;
    setUnit(unit); 
}
   

    //get
int ElectricBill::getBillId()
{
    return this->billId;
}
int ElectricBill::getUnit()
{
    return unit;
}
string ElectricBill::getBillName()
{
    return billName;
}
double ElectricBill::getCost()
{
    return cost;
}
string ElectricBill::getBeginDate()
{
    return beginDate;
}


void ElectricBill::calculateCost()
{
    if (unit > 400)
        this->cost = (unit - 400.0) * 2.976 + 100 * 2.834 + 100 * 2.536 + 100 * 2.014 + 50 * 1.734 + 50 * 1.678;
    else if (unit > 300)
        this->cost = (unit - 300.0) * 2.834 + 100 * 2.536 + 100 * 2.014 + 50 * 1.734 + 50 * 1.678;
    else if (unit > 200)
        this->cost = (unit - 200.0) * 2.536 + 100 * 2.014 + 50 * 1.734 + 50 * 1.678;
    else if (unit > 100)
        this->cost = (unit - 100.0) * 2.014 + 50 * 1.734 + 50 * 1.678;
    else if (unit > 50)
        this->cost = (unit - 50.0) * 1.734 + 50 * 1.678;
    else
        this->cost = unit * 1.678;
    this->cost *= 1000.0;
    // Tax:
    double tax = this->cost * 0.1;
    this->cost += tax;
}

void ElectricBill::showInfo()
{
    cout<< "\nBill has id:  " << this->billId;
    cout << " ,name " << this->billName;
    cout << "\n from:  " << this->beginDate;
    cout<<" to:  " <<this->endDate;
    cout<< "\nCustomer Name "<< this->customerName;
    cout<<", Address: " << this->address;
    cout<< ", Phone: "<< this->phoneNumber;
    cout<< "\n Electric unit: " <<this->unit;
    cout<< ", cost : " << this->cost;
    cout << "\n-------------------------------------";
}




/*
void ElectricBill::readString(string str, bool fromDB)
{
    string arr[20];
    int k=0;
    string word;
    for (int i = 0; i <= str.length(); i++)
    {
        if (str[i] == ' ' || i == str.length())
        {
            arr[k++] = word;
            word = "";
        }
        else
        {
            word += str[i];
        }
    }
}

 */




// ElectricBill bill;
// string name;
// getline(cin, name);
// bill.setBillName(name);
// cout << bill.billName << endl;

