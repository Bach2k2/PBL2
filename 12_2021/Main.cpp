#include <iostream>
#include "BillService.h"
#include "UnitPrice.h"
#include "CustomerService.h"
using namespace std;
BillService qli;
CustomerService qliKH;
void displayBillMenu();
void displayCustomerMenu();
void displayMainMenu();
int main()
{
	UnitPrice unitPrice;

	string path;
	cout << "Nhap duong dan file bill  -- Nhap bill.txt" << endl;
	cin >> path;
	qli.readFile(path);

	string path2;
	cout << "Nhap duong dan file customer  -- Nhap customer.txt" << endl;
	cin >> path2;
	qliKH.readDataInFile(path2);
	qli.display();
	displayMainMenu();
}
void displayBillMenu()
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
		cout << "\n\t\t\t|7. Calculate price all bill\t\t\t\t|";
		cout << "\n\t\t\t|0. Back to main menu         \t\t\t\t|";

		cout << "\n\t\t\t|-----------------------------------------------|";
		cout << "\n\n\t\t\tEnter your choice: ";
		cin >> choice;
		switch (choice)
		{
		case 1:
		{
			system("cls");
			cout << "\nFUNCTION: ADD A NEW BILL"<<endl;
			Bill* bill = new Bill();
			bill->enterData();
			qli.add(bill);
			system("pause");
			break;
		}
		case 2:
		{
			system("cls");
			cout << "\nFUNCTION: UPDATE A BILL IN LIST";
			cout << "\nEnter the Id's bill to update: ";

			system("pause");
			break;
		}
		case 3:
		{
			system("cls");
			cout << "\nFUNCTION: SEARCH A BILL IN LIST WITH ID";
			cout << "\nEnter the Id's bill to print: ";
			qli.search();
			system("pause");
			break;
		}
		case 4:
		{
			system("cls");
			cout << "\nFUNCTION: DELETE A BILL IN LIST WITH ID";
			cout << "\nEnter the Id's bill to delete: ";

			cout << "Xoa thanh cong" << endl;
			system("pause");
			break;
		}
		case 5:
		{
			system("cls");
			qli.display();
			system("pause");
			break;
		}
		case 6:
		{
			//  cout << "\nSave data successful" << endl;
			system("pause");
			break;
		}
		case 7:
		{
			cout << "Calculate price" << endl;
			qli.calculatePrice();
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
void displayCustomerMenu()
{
	int choice;
	do
	{
		system("cls");
		cout << "\n\n";
		cout << "\n\t\t\t|----------------------Menu---------------------|";
		cout << "\n\t\t\t|1. Add a new customer \t\t\t\t|";
		cout << "\n\t\t\t|2. Update a customer\t\t\t\t|";
		cout << "\n\t\t\t|3. Search a customer\t\t\t\t|";
		cout << "\n\t\t\t|4. Remove a customer\t\t\t\t|";
		cout << "\n\t\t\t|5. Display all customer\t\t\t\t|";
		cout << "\n\t\t\t|6. Write to File\t\t\t\t|";
		cout << "\n\t\t\t|0. Back to main menu        \t\t\t\t|";
		cout << "\n\t\t\t|-----------------------------------------------|";
		cout << "\n\n\t\t\tEnter your choice: ";
		cin >> choice;
		switch (choice)
		{
		case 1:
		{
			system("cls");
			cout << "\nFUNCTION: ADD A NEW Customer" << endl;
			qliKH.enqueue();
			system("pause");
			break;
		}
		case 2:
		{
			system("cls");
			cout << "\nFUNCTION: UPDATE A BILL IN LIST" << endl;
			cout << "\nEnter the Id's bill to update: ";
			system("pause");
			break;
		}
		case 3:
		{
			system("cls");
			cout << "\nFUNCTION: SEARCH A BILL IN LIST WITH ID" << endl;
			cout << "\nEnter the Id's bill to print: ";
			system("pause");
			break;
		}
		case 4:
		{
			system("cls");
			cout << "\nFUNCTION: DELETE A BILL IN LIST WITH ID" << endl;
			cout << "\nEnter the Id's bill to delete: ";

			cout << "Xoa thanh cong" << endl;
			system("pause");
			break;
		}
		case 5:
		{
			system("cls");
			qliKH.display();
			system("pause");
			break;
		}
		case 6:
		{
			//  cout << "\nSave data successful" << endl;
			system("pause");
			break;
		}
		case 0:
			cout << "\n\t\t\t---------Back to menu----------" << endl;
			system("pause");
			break;
		default:
			cout << "inproper choice, enter again!";
			break;
		}
	} while (choice != 0);
}
void displayMainMenu()
{
	int choice;
	do
	{
		system("cls");
		cout << "\n\n";
		cout << "\n\t\t\t|----------------------Main Menu----------------|";
		cout << "\n\t\t\t|1. Manage the bill list \t\t\t\t|";
		cout << "\n\t\t\t|2. Manage the customer list:\t\t\t\t|";
		cout << "\n\t\t\t|0. Exit\t\t\t\t\t|";
		cout << "\n\t\t\t|-----------------------------------------------|";
		cout << "\n\n\t\t\tEnter your choice: ";
		cin >> choice;
		switch (choice)
		{
		case 1: { displayBillMenu();
			break;
		}
		case 2:
		{
			displayCustomerMenu();
			break;
		}
		case 0:
		{
			cout << "Good bye" << endl;
			break;
		}
		default:
		{
			cout << "Lua chon sai!" << endl;
		}
		}
	} while (choice != 0);
}
