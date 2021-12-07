#include"Bill.h"
#include "UnitPrice.h"
using namespace std;
int Bill::increment = 1;
Bill::Bill(int MKH, string name, int prevUnit, int afterUnit, string beginDate, string endDate) :
    MKH(MKH), nameBill(name), prevMeter(prevUnit), afterMeter(afterUnit), beginDate(beginDate), endDate(endDate)
{
    this->idMeter = increment++;
    this->next = NULL;
    this->unit = afterMeter - prevMeter;
    this->price = 0;
}
Bill::~Bill() {}
ostream& operator<<(ostream &out,const Bill& bill)
{
    out << "Bill: "
        << "{ id : " << bill.idMeter
        << ", name: " << bill.nameBill
        << ", begin date: " << bill.beginDate
        << ", end date: " << bill.endDate
        << ", previous unit: " << bill.prevMeter
        << ", after unit: " << bill.afterMeter
        << ", unit : " << bill.unit
        << ", Price: " << bill.price <<"}"<< endl;;
   return out;
}
