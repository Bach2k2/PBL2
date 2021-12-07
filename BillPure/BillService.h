#pragma once
#include "Bill.h"
#include "Service.h"
class BillService
{
public:          //BillService
    Bill* pHead; //
    Bill* pTail;
    static int numNodes;
public:
    BillService();
    ~BillService();
    void add();
    void add(Bill* bill);
    void remove();
    void removeAll();
    void update();
    void display();
    void search();
    bool isEmpty();
};

