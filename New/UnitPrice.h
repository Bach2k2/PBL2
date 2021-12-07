#include<iostream>
using namespace std;
class UnitPrice
{
	/*
	* //Bậc 1: 1.678 - Từ 0- 50 kWh
	//Bậc 2: 1.734 - Từ 51-100 kWh
	//Bậc 3: 2.014 - Từ 101-200 kWh
	//Bậc 4: 2.536 - Từ 201-300 kWh
	//Bậc 5: 2.834 - Từ 301-400 kWh
	//Bậc 6: 2.927 - Từ 401 kwh trở lên
	*/
	
private:
	int unit;
	double price;
public:
	double rank[6] = { 1.678, 1.734,2.014,2.536,2.834,2.927 };
public:
	// Khi khởi tạo một bill sẽ sinh ra đối tiện unitprice;
	UnitPrice(int = 0);
	~UnitPrice();
	int getUnit();
	void setUnit(int value);
	void calculate();
	void calculate2();
	double getPrice();
	void showUnitPrice();
};
