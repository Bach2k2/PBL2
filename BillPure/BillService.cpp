#include "BillService.h"
#include <cstring>
using namespace std;
int BillService::numNodes = 0;
BillService::BillService()
{
    this->pHead = NULL;
    this->pTail = NULL;
}
BillService::~BillService()
{
    delete pHead;
    delete pTail;
}
void BillService::add()
{
    int MKH;
    do
    {
        cout << "Customer id:: ";
        cin >> MKH;
        system("pause");
    } while (MKH <= 0);

    string name;
    do
    {
        cout << "Name of bill: ";
        getline(cin, name);
        if (name == "" || name == "\n")
            cout << "enter again!";
    } while (name == "" || name == "\n");

    string beginDate;
    do
    {
        cout << "The Begin Date: ";
        cin >> beginDate;
    } while (beginDate == " " || beginDate == "\n");

    string endDate;
    do
    {
        cout << "The End Date: ";
        cin >> endDate;
    } while (endDate == " " || endDate == "\n");
    int prevUnit;
    do
    {
        cout << "Enter the last unit: ";
        cin >> prevUnit;
    } while (prevUnit <= 0);
    int afterUnit;
    do
    {
        cout << "Enter the next unit: ";
        cin >> afterUnit;
    } while (afterUnit <= 0);
    int unit = afterUnit - prevUnit;
    Bill *bill = new Bill(MKH, name, prevUnit, afterUnit, beginDate, endDate);
    if (pHead == NULL)
    {
        pHead = pTail = bill;
    }
    else
    {
        pTail->next = bill;
        pTail = bill;
    }
    numNodes;
}
void BillService::add(Bill *bill)
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
    numNodes++;
}
void BillService::search()
{
    cout << "Enter the name or id";
    string input;
    getline(cin, input);
    Bill *bill = pHead;
    while (bill != NULL)
    {
        if ((bill->nameBill).find(input) != string::npos)
        {
            cout << "Found!" << endl;
            cout << bill->nameBill << " " << bill->idMeter;
            break;
        }
        else
        {
            bill = bill->next;
        }
    }
}
void BillService::display()
{
    Bill *bill = pHead;
    while (bill != NULL)
    {
        cout << *bill;
        bill = bill->next;
    }
}
bool BillService::isEmpty()
{
    if (pHead == NULL)
        return true;
    else
    {
        return false;
    }
}
void BillService::remove()
{
    bool check = false;
    cout << "DO YOU WANT TO DELETE?";
    int choice;
    cout << "Enter 1 to delete,0 to exit";
    cin >> choice;
    check = choice;
    if (check)
    {
        if (isEmpty())
        {
            cout << "Your list is empty.";
        }
        else
        {
            string name;
            do
            {
                cout << "Enter name of bill to delete";
                getline(cin, name);
            } while (name == "" || name == "\n");
            Bill *bill = pHead;
            Bill *temp;
            while (bill != NULL && strcmp(bill->nameBill.c_str(), name.c_str()) != 0)
            {
                temp = bill;
                bill = bill->next;
            }
            if (temp != NULL)
            {
                temp->next = bill->next;
                delete bill;
            }
            else
            {
                pHead = bill->next;
                delete bill;
            }
        }
    }
}