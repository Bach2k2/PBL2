#include <iostream>
#include "BillService.h"
#include "UnitPrice.h"
using namespace std;
int main()
{
    UnitPrice unitPrice;
    BillService qli;
    Bill *bill = new Bill(2, "John", 3, 4, "love", "ling");
    qli.add(bill);
    qli.add();
    qli.display();
    qli.remove();
    qli.display();
}