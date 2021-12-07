#include "ElectricBill.h"

class BillManage
{
public:
    ElectricBill* head;   // current
    ElectricBill* tail;   // current
    int numNodes; // number of Bills
public:
    BillManage();
    void addBill(ElectricBill *);   
    void searchBill(int);
    void updateBill(int);
    ElectricBill& getBill(int);
    void displayList();
    void removeBill(int);
    void saveDataInFile(string);

};

