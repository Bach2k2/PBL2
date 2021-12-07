#include "BillManage.h"
#include <iostream>
#include <fstream>
#include <stdlib.h>
using namespace std;
BillManage::BillManage()
{
    this->head = nullptr;
    this->tail = nullptr;
    this->numNodes = 0;
}
void BillManage::addBill(ElectricBill *bill)
{
    if (this->head == nullptr)
    {
        this->head = this->tail= bill;  
    }
    else
    {
        tail->next = bill;
        tail = bill;
        tail->next = nullptr;
    }
    numNodes++;
}

void BillManage::searchBill(int id)
{
   
    ElectricBill* temp = head;
    while (temp != nullptr)
    {
        if (temp->getBillId() == id)
        {
            cout << "\nYour bill already search: " << endl;;
            temp->showInfo();
            return;
        }
        temp = temp->next;
    }
    if (temp == nullptr) cout << "No any bill have that id";
    return;
}

 ElectricBill& BillManage::getBill(int billId){
     try
     {
         ElectricBill* temp = head;
         while (temp != nullptr)
         {
             if (temp->getBillId() == billId)
                 return *temp;
             temp = temp->next;
         }
     }
     catch (exception e)
     {
         cerr << "Bill ko ton tai " << endl;
     }
    
 }

 void BillManage::updateBill(int billId)
 {
     ElectricBill* temp = &getBill(billId);
     cout << "-----------------Update---------------------";
     cout << "\n1. Edit the billName: ";
     cout << "\n2. Edit the unit: ";
     cout << "\n3. Edit the date on Bill : ";
     cout << "\n0. Exit.";

     int choice;
     do
     {
         cout << "\nYour choice: ";
         cin >> choice;
         switch (choice)
         {
         case 1:
         {
             cout << "Enter new bill's name:";
             string name;
             cin.ignore();
             getline(cin, name);
             temp->setBillName(name);
             break;
         }
         case 2:
         {
             int unit;
             cout << "Enter new bill's unit:";
             cin >> unit;
             temp->setUnit(unit);
             break;
         }

         case 3:
         {
             cout << "Enter new bill's begin date:";
             string begin;
             cin.ignore();
             getline(cin, begin);
             temp->setBeginDate(begin);
             cout << "Enter new bill's end date:";
             string end;
             getline(cin, end);
             temp->setEndDate(end);
             break;
         }
         case 0: break;
         default:
         {
             cout << "Enter another choice";
             break;
         }
         }

     } while (choice != 0);
 }

void BillManage::displayList()
{
    cout << "There are " << numNodes << " bills" << endl;
    ElectricBill* temp = head;
    for(int i=0;i<numNodes;i++)
    {
        temp->showInfo();
        temp = temp->next;
    }
}
void BillManage::removeBill(int id)
{
    if (head == nullptr)
    {
        cout << "No bill is available ";
    }
    else
    {
        if (head->getBillId() == id)
        {
            ElectricBill* temp = head;
            head = temp->next;
        }
        else
        {
            ElectricBill* before = head;
            while (before->next->getBillId() != id)
            {
                before = before->next;
            }
            ElectricBill* after = before->next->next;
            before->next = after;
        }
        numNodes --;
    }

}
void BillManage::saveDataInFile(string path)
{
    ofstream file;
    file.open(path, ios::out);
    if (file.is_open())
    {
        file << "ID | Bill's Name |  BeginDate |  EndDate  \t |Customer's Id\t |Customer's Namet| Address\t | PhoneNumber\t| Unit\t| Cost "<<endl;
        ElectricBill* temp = head;
        while (temp != nullptr)
        {
            temp->printToFile(file);
            file << endl;
            temp = temp->next;
        }
    }
    else
    {
        cout << "Mo ko thanh cong";
    }  
}

