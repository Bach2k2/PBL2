#include "BillService.h"
#include "UnitPrice.h"
#include "CustomerService.h"
#include <cstring>
#include <fstream>
using namespace std;
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
	Bill *bill = new Bill();
	int meterNumber;
	bool check = true;
	do
	{
		cout << "Nhap so cong to moi：";
		cin >> meterNumber;
		if (contain(meterNumber))
		{
			check = false;
			cout << "enter again!";
		}
		else
		{
			check = true;
			cout << "Thanks";
		}
	} while (!check);
	bill->setMeterNumber(meterNumber);
	bill->enterData();
	if (pHead == NULL)
	{
		pHead = pTail = bill;
	}
	else
	{
		pTail->next = bill;
		pTail = bill;
	}
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
}
void BillService::search()
{
	cout << "Enter the name or id";
	int input;
	cin.ignore(32767, '\n');
	cin >> input;
	Bill *bill = pHead;
	while (bill != NULL)
	{
		if ((bill->getMeterNumber() == input))
		{
			cout << "Found!" << endl;
			CustomerService *service = new CustomerService();
			service->showInfoByMkh(bill->getCustomerId());
			cout << "Hoa don thang " << bill->getBeginDate().getMonth() << endl;
			cout << "Bat dau tu " << bill->getBeginDate() << " den " << bill->getEndDate();
			cout << "Tong so tien can thanh toan : " << bill->getPrice() << " dong";
			break;
		}
		bill = bill->next;
	}
}
void BillService::display()
{
	cout << "\t\t\t\tBill List\t\t\t\t\t" << endl;
	cout << "ID\t|Name\t|t Begin Date \t| End Date\t|Previous Unit\t| Last Unit \t|Unit \t|Price\t|Customer's ID" << endl;
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
// còn lỗi
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
			cout << "Danh sach cac hoa don trong rong";
		}
		else
		{
			int meterNumber;
			do
			{
				cin.ignore();
				cout << "Nhap so cong to cua hoa don can xoa: " << endl;
				cin >> meterNumber;
			} while (contain(meterNumber));
			Bill *after = pHead;
			Bill *before = after;
			while (after != NULL)
			{
				before = after;
				after = after->next;
			}
			if (after == nullptr)
			{
				throw "Khong tim thay con tro can xoa";
			}
			else
			{
				if (pHead == after)
				{
					pHead = after->next;
				}
				else
				{
					before->next = after->next;
				}
			}
		}
	}
}
void BillService::removeFirst()
{
	if (isEmpty())
	{
		return;
	}
	Bill *temp = pHead;
	pHead = temp->next;
	delete temp;
}
void BillService::readFile(string path)
{
	ifstream file(path, ios::in);
	if (file.is_open())
	{
		string line;
		while (getline(file, line))
		{
			Bill *bill = new Bill();
			bill->fromString(line);
			this->add(bill);
		}
		cout << "data added successfully" << endl;
		file.close();
	}
	else
	{
		cout << "Not success" << endl;
	}
}
bool BillService::contain(int id)
{
	Bill *bill = pHead;
	bool idStatus = false;
	while (bill != NULL)
	{
		if (bill->getMeterNumber() == id)
		{
			idStatus = true;
			break;
		}
		bill = bill->next;
	}
	return idStatus;
}
void BillService::calculatePrice()
{
	UnitPrice unitprice;
	Bill *bill = pHead;
	while (bill != NULL)
	{
		unitprice.setUnit(bill->getUnit());
		unitprice.calculate();
		double price = unitprice.getPrice();
		bill->setPrice(price);
		bill = bill->next;
	}
}
void BillService::MonthManger()
{
	int month, year;
	cout << " Nhap thang , nam" << endl;
	cin >> month >> year;
	Bill *bill = pHead;
	Bill *MonthManger = new Bill();
	while (bill != NULL)
	{
		if (bill->getBeginDate().getMonth() == month)
		{
			if (MonthManger == NULL)
			{
				MonthManger = bill;
			}
			else
			{
				bill->next = MonthManger;
				MonthManger = bill;
			}
		}
		bill = bill->next;
	}
	cout << "Danh sach bill theo thangs:" << endl;
	while (MonthManger != NULL)
	{
		cout << *MonthManger;
		MonthManger = MonthManger->next;
	}
}
void BillService::update()
{
	int idMeter;
	cout << "Nhap id bill can sua" << endl;
	cin >> idMeter;
	Bill *temp = pHead;
	while (temp != NULL && (temp->getMeterNumber() == idMeter))
	{
		temp = temp->next;
	}
	if (temp != NULL)
	{
		cout<<"Da tim thay!"<<endl;
		cout << "\n\t\t\t-----------------Update---------------------";
		cout << "\n1. Thay doi so cong to dien";
		cout << "\n2. Thay doi cac so chi dien cua hoa don ";
		cout << "\n3. Thay doi thoi gian trong hoa don";
		cout << "\n0. Quay lai menu hoa don";
		cout << "\n********************************";
		cout << "\nsLua chon cua ban: " << endl;
		int choice;
		bool check = true;
		do
		{
			cin >> choice;
			switch (choice)
			{
			case 1:
			{
				int new_MeterNumber;
				do
				{
					cout << "Nhap so cong to moi: " << endl;
					cin >> new_MeterNumber;
					if (contain(new_MeterNumber))
					{
						check = false;
						cout << "Moi nhap lai: " << endl;
					}

					else
					{
						check = true;
					}
				} while (!check);
				temp->setMeterNumber(new_MeterNumber);
				cout << "Lua chon cua ban: " << endl;
				break;
			}
			case 2:
			{
				int new_prevMeter, new_nextMeter;
				do
				{
					cout << "Nhap moi so dien truoc: " << endl;
					cin >> new_prevMeter;
					if (new_prevMeter < 0)
					{
						check = false;
						cout << "Moi nhap lai: " << endl;
					}
					else
					{
						check = true;
					}

				} while (!check);
				temp->setPrevMeter(new_prevMeter);
				do
				{
					cout << "Nhap moi so dien sau : " << endl;
					cin >> new_nextMeter;
					if (new_nextMeter < temp->getPrevMeter())
					{
						check = false;
						cout << "Moi nhap lai: " << endl;
					}
					else
					{
						check = true;
					}
				} while (!check);
				temp->setNextMeter(new_nextMeter);
				cout << "Lua chon cua ban: " << endl;
			}
			case 3:
			{
				// begin date:
				cout << "Nhap moi ngay bat dau: " << endl;
				int d1, m1, y1;
				cout << "Nhap nam cua ngay bat dau: " << endl;
				cin >> y1;
				cout << "Nhap thang cua ngay bat dau: " << endl;
				cin >> m1;
				cout << "Nhap ngay cua ngay bat dau: " << endl;
				cin >> d1;
				temp->getBeginDate().setDate(d1, m1, y1);
				// end date
				cout << "Nhap moi ngay ket thuc: " << endl;
				int d2, m2, y2;
				cout << "Nhap nam cua ngay ket thuc: " << endl;
				cin >> y2;
				cout << "Nhap thang cua ngay ket thuc: " << endl;
				cin >> m2;
				cout << "Nhap ngay cua ngay ket thuc:  " << endl;
				cin >> d2;
				temp->getEndDate().setDate(d2, m2, y2);
				cout << "Lua chon cua ban: " << endl;
				break;
			}
			default:
			{
				cout << "Lua chon khong hop le: " << endl;
				cout << "Moi nhap lai :" << endl;
			}
			}
		} while (choice != 0);
	}
}
/********
void BillService::search()
{
	cout << "Searching..." << endl;
	cout << "Nhap id bill can sua" << endl;
	int idMeter;
	int MM;
	cout << "Nhap thang cua can tim kiem " << endl;
	cin >> MM;
	Bill *temp = pHead;
	while (temp != NULL && (temp->getMeterNumber()== idMeter) && (temp->getMonth() == MM))
	{
		temp = temp->next;
	}
	if (temp != NULL)
	{
		cout << *temp;
	}
	else
	{
		cout << "ko tim thay ket qua" << endl;
	}
}
*/