#include <iostream>
#include "BillService.h"
#include "UnitPrice.h"
#include "CustomerService.h"
using namespace std;
int main()
{
	string path;
	cout << "Nhap duong dan";
	cin >> path;
	UnitPrice unitPrice;
	BillService qli;
	qli.readFile(path);
	qli.display();
	system("pause");
	Bill* bill = new Bill(17818223, "thuyTien", 50, 60, "Trung", "Truong","KH001");
	qli.add(bill);
	Bill* bill1 = new Bill(2838021, "Son Thuy", 100, 120, "20/10", "1/12","KH002");
	qli.add(bill1);
	system("pause");
	qli.add();
	qli.display();
	CustomerService qliKH;
	Customer *cus1 = new Customer ("KH001", "Le Van Hai",18, "son tra", " 0976812333");
	Customer* cus2 = new Customer("KH002", "Le Van Hai1", 19, "son tra", " 0976812333");
	qliKH.enqueue(cus1);
	qliKH.enqueue(cus2);
	qliKH.display();
	int MKH;
	cout << "Nhap ma kh: " << endl;
	cin >> MKH;
	system("pause");
	qliKH.dequeue();
	qliKH.display();
//	qli.display();
}