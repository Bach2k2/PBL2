#include "BillManage.h"
#include <iostream>
#include <fstream>
using namespace std;
void menu(BillManage manager);
int main()
{

    BillManage manager;
    ElectricBill *bill1=new ElectricBill("TienDienThang4", "1/04/2020", "30/04/2020", 12, "Le Van Ha1", "Thanh Khe", "0903219882", 100);
    ElectricBill *bill2=new ElectricBill("TienDienThang4", "1/04/2020", "30/04/2020", 13, "Le Van Ha", "Thanh Khe", "0903219880", 110);
    ElectricBill *bill3=new ElectricBill("TienDienThang4", "1/04/2020", "30/04/2020", 18, "Le Van Hau", "Thanh Khe", "0903214462", 120);
    manager.addBill(bill1);
    manager.addBill(bill2);
    manager.addBill(bill3);

    string path;
    // cin.ignore();
    cout << "Enter the path of file: ";
    getline(cin, path);
    ifstream input(path);
    cout << "Path already enter: " << path << endl;
    if (input.is_open())
    {
        cout << "Open successfully" << endl;
        system("pause");
        
        while(!input.eof())
        {
            ElectricBill* bill = new ElectricBill();
            bill->setByFile(input);
            manager.addBill(bill);
        } 
        menu(manager);
        input.close();
    }
    else
    {
        cout << "fail to open" << endl;
    }
}

void menu(BillManage manager)
{
    int choice;
    do
    {
        system("cls");
        cout << "\n\n";
        cout << "\n\t\t\t|----------------------Menu---------------------|";
        cout << "\n\t\t\t|1. Add a new bill \t\t\t\t|";
        cout << "\n\t\t\t|2. Update a bill\t\t\t\t|";
        cout << "\n\t\t\t|3. Search a bill\t\t\t\t|";
        cout << "\n\t\t\t|4. Remove a bill\t\t\t\t|";
        cout << "\n\t\t\t|5. Display all bill\t\t\t\t|";
        cout << "\n\t\t\t|6. Write to File\t\t\t\t|";
        cout << "\n\t\t\t|0. Exit         \t\t\t\t|";
        cout << "\n\t\t\t|-----------------------------------------------|";
        cout << "\n\n\t\t\tEnter your choice: ";
        cin >> choice;
        switch (choice)
        {
        case 1:
        {
            system("cls");
            cout << "\nFUNCTION: ADD A NEW BILL";
            cout << "\nthe bill's name: ";

            string billName;
            cin.ignore();
            getline(cin,billName);
       
            cout << "the bill's beginDate:";
            string beginDate;
            //cin.ignore();
            getline(cin,beginDate);
           
            cout << "the bill's endDate:";
            string endDate;
            //cin.ignore();
            getline(cin, endDate);
            
            cout << "the customer's ID: ";
            int customerId;
            cin >> customerId;
                        
            cout << "customer 's name: ";
            string customerName;
            cin.ignore();
            getline(cin, customerName);
            
            cout << "the customer address: ";
            string address;
           // cin.ignore();
            getline(cin, address);
            
            cout << "the customer's phone number: ";
            string phoneNum;
           // cin.ignore();
            getline(cin, phoneNum);
           
            cout << "the bill 's unit: ";
            int unit;
            cin >> unit;
            
            ElectricBill *bill=new ElectricBill(billName, beginDate, endDate, customerId, customerName, address, phoneNum, unit);
            manager.addBill(bill);
            bill->showInfo();
            cout << "\nBill's already added";
            system("pause");
            break;
        }
        case 2:
        {
            system("cls");
            cout << "\nFUNCTION: UPDATE A BILL IN LIST";
            cout << "\nEnter the Id's bill to update: ";
            int id;
            cin >> id;
            manager.updateBill(id);
            system("pause");
            break;
        }
        case 3:
        {
            system("cls");
            cout << "\nFUNCTION: SEARCH A BILL IN LIST WITH ID";
            cout << "\nEnter the Id's bill to print: ";
            int id;
            cin >> id;
            manager.searchBill(id);
            system("pause");
            break;
        }
        case 4:
        {
            system("cls");
            cout << "\nFUNCTION: DELETE A BILL IN LIST WITH ID";
            cout << "\nEnter the Id's bill to delete: ";
            int id;
            cin >> id;
            manager.removeBill(id);
            cout << "Xoa thanh cong" << endl;
            system("pause");
            break;
        }
        case 5:
        {
            system("cls");
            manager.displayList();
            system("pause");
            break;
        }
        case 6:
        {
            manager.saveDataInFile("Output.txt");
            cout << "\nSave data successful" << endl;
            system("pause");
            break;
        }
        case 0:
            cout << "\n\t\t\t---------Goodbye----------";
            break;
        default:
            cout << "inproper choice, enter again!";
            break;
        }
    } while (choice != 0);
}