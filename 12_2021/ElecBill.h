#include <iostream>
#include <fstream>
#include <string>
#include "Bill.h"
#include "CustomerService.h"
#include "UnitPrice.h"
class ElecBill
{
    public:
    Bill bill;
    Customer customer;
    UnitPrice unitPrice;
    public:
    ~ElecBill();
    ElecBill(Bill&,Customer&,UnitPrice&);
    ElecBill *next;
    friend ostream& operator<<(ostream&, const ElecBill&);
    readFile(string);
    writeFile(string);

};