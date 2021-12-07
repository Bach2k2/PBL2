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
	Bill* bill = new Bill();
	int id;
	bool check = true;
	do {
		cout << "Enter the Id Meter：";
		cin >> id;
		cout << id;
		if (contain(id))
		{
			check = false;
			cout << "enter again!";
		}
		else {
			check = true;
			cout << "Thanks";
		}
		cout << check;
	} while (!check);
	bill->idMeter = id;
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
void BillService::add(Bill* bill)
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
	Bill* bill = pHead;
	while (bill != NULL)
	{
		if ((bill->idMeter == input))
		{
			cout << "Found!" << endl;
			CustomerService* service = new CustomerService();
			service->showInfoByMkh(bill->MKH);
			cout << "Hoa don thang " << bill->beginDate.getMonth() << endl;
			cout << "Bat dau tu " << bill->beginDate << " den " << bill->endDate;
			cout << "Tong so tien can thanh toan : " << bill->price << " dong";
			break;
		}
		bill = bill->next;
	}
}
void BillService::display()
{
	cout << "\t\t\t\tBill List\t\t\t\t\t" << endl;
	cout << "ID\t|Name\t|t Begin Date \t| End Date\t|Previous Unit\t| Last Unit \t|Unit \t|Price\t|Customer's ID" << endl;
	Bill* bill = pHead;
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
//còn lỗi
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
			try {
				string name;
				do
				{
					cin.ignore();
					cout << "Enter name of bill to delete";
					getline(cin, name);
				} while (name == "" || name == "\n");
				Bill* after = pHead;
				Bill* before = after;
				while (after != NULL && strcmp(after->nameBill.c_str(), name.c_str()) != 0)
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
			catch (char* e)
			{
				cout << e;
			}
			catch (...)
			{
				cout << "Khong tim thay con tro can xoa";
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
	Bill* temp = pHead;
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
			Bill* bill = new Bill();
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
	Bill* bill = pHead;
	bool idStatus = false;
	while (bill != NULL)
	{
		if (bill->idMeter == id) {
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
	Bill* bill = pHead;
	while (bill != NULL)
	{
		unitprice.setUnit(bill->unit);
		unitprice.calculate();
		double price = unitprice.getPrice();
		bill->setPrice(price);
		bill = bill->next;
	}
}
