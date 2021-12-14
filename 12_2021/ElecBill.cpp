#include "ElecBill.h"
ElecBill::ElecBill(Bill &bill, Customer& customer,UnitPrice unitPrice)
{
    this->bill = bill;
    this->customer = customer;
    this->unitPrice = unitPrice;
}
ElecBill::~ElecBill()
{
    delete this->bill;
    delete this->customer;
    delete this->unitPrice;
}
ElecBill::readFile(string path)
{
    ifstream file(path,ios::in);
    if(file.is_open())
    {
        cout<<"Reading";
    }
}

