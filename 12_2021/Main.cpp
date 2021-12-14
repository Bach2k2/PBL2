#include <iostream>
#include "BillService.h"
#include "UnitPrice.h"
#include "CustomerService.h"
#include "MonthList.h"
using namespace std;
BillService qli;
CustomerService qliKH;
void displayBillMenu();
void displayCustomerMenu();
void displayMainMenu();
string path;
int main()
{
	UnitPrice unitPrice;
	cout << "Nhap duong dan file bill  -- Nhap bill.txt" << endl;
	cin >> path;
	qli.readFile(path);
	cout << "Calculate price" << endl;
	qli.calculatePrice();
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
		cout << "\n\t\t\t|1. Them moi mot hoa don  \t\t\t\t|";
		cout << "\n\t\t\t|2. Cap nhat thong tin mot hoa don\t\t\t\t|";
		cout << "\n\t\t\t|3. Tim kiem mot hoa don\t\t\t\t|";
		cout << "\n\t\t\t|4. Xoa di mot hoa don\t\t\t\t|";
		cout << "\n\t\t\t|5. Hien thi het tat ca hoa don\t\t\t\t|";
		cout << "\n\t\t\t|6. In vao file tat ca hoa don\t\t\t\t|";
		cout << "\n\t\t\t|7. Quan ly hoa don theo tung thang  \t\t\t|";
		cout << "\n\t\t\t|0. Back to main menu \t\t\t|";
		cout << "\n\t\t\t|-----------------------------------------------|";
		cout << "\n\n\t\t\tNhap lua chon: ";
		cin >> choice;
		switch (choice)
		{
		case 1:
		{
			system("cls");
			cout << "\nCHUC NANG: THEM MOI MOT HOA DON" << endl;
			Bill *bill = new Bill();
			bill->enterData();
			qli.add(bill);
			cout << "Calculate price" << endl;
			qli.calculatePrice();
			system("pause");
			break;
		}
		case 2:
		{
			system("cls");
			cout << "\nCHUC NANG: CAP NHAT THONG TIN MOT HOA DON"<<endl;
			cout << "\nNhap so cong to cua hoa don: ";
			qli.update();
			system("pause");
			break;
		}
		case 3:
		{
			system("cls");
			cout << "\nCHUC NANG: TIM KIEM THONG TIN MOT HOA DON"<<endl;
			cout << "\nNhap so cong to cua hoa don: ";
			qli.search();
			system("pause");
			break;
		}
		case 4:
		{
			system("cls");
			cout << "\nCHUC NANG: XOA MOT HOA DON";
			cout << "\nNhap so cong to cua hoa don can xoa: ";
			qli.remove();
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
			MonthList *qLiTheoThang = new MonthList();
			cout << "Quan ly danh sach cua hoa don theo thang" << endl;
			int MM, yy;
			cout << "Nhap thang: " << endl;
			cin >> MM;
			cout << "Nhap nam: " << endl;
			cin >> yy;
			qLiTheoThang->setMonthAndYear(MM, yy);
			qLiTheoThang->readFile(path);
			system("pause");
			qLiTheoThang->displayByMonth();
			cout << "Muon luu vao file ko?" << endl;
			qLiTheoThang->displayByMonth();
			int check = 0;
			cout << "Nhan 1 de co";
			cin >> check;
			if (check == 1)
			{
				string ofPath;
				cout << " Nhap duong dan: " << endl;
				cin >> ofPath;
				qLiTheoThang->printToFile(ofPath);
				system("pause");
			}
			delete qLiTheoThang;
			break;
		}
		case 0:
			cout << "\n\t\t\t------------------------Goodbye----------------------------------"<< endl;
			break;
		default:
			cout << "Lua chon khong hop le"<<endl;
			cout<<"Moi nhap lai lua chon: "<<endl;
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
		cout << "\n\t\t\t|1. Them moi khach hang \t\t\t\t|";
		cout << "\n\t\t\t|2. Cap nhat thong tin khach hang\t\t\t\t|";
		cout << "\n\t\t\t|3. Tim kiem mot khach hang\t\t\t\t|";
		cout << "\n\t\t\t|4. Xoa di mot khach hang\t\t\t\t|";
		cout << "\n\t\t\t|5. In danh sach cua tat ca khach hang\t\t\t\t|";
		cout << "\n\t\t\t|6. Dua du lieu vao file\t\t\t\t|";
		cout << "\n\t\t\t|0. Tro ve menu chinh   \t\t\t\t|";
		cout << "\n\t\t\t|-----------------------------------------------|";
		cout << "\n\n\t\t\tEnter your choice: ";
		cin >> choice;
		switch (choice)
		{
		case 1:
		{
			system("cls");
			cout << "\nCHUC NANG: THEM KHACH HANG " << endl;
			qliKH.enqueue();
			system("pause");
			break;
		}
		case 2:
		{
			system("cls");
			cout << "\nCHUC NANG: THAY DOI THONG TIN CUA KHACH HANG " << endl;
			cout << "\nNhap so cong to cua khach hang:";
			system("pause");
			break;
		}
		case 3:
		{
			system("cls");
			cout << "\nCHUC NANG: TIM KIEM KHACH HANG " << endl;
			cout << "\nNhap so cong to cua khach hang:";
			system("pause");
			break;
		}
		case 4:
		{
			system("cls");
			cout << "\nCHUC NANG: XOA KHACH HANG" << endl;
			cout << "\nNhap so cong to cua khach hang:";
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
		case 1:
		{
			displayBillMenu();
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
