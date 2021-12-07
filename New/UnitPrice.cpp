#include <iostream>
using namespace std;
#include "UnitPrice.h"
UnitPrice::UnitPrice(int unit)
{
	this->unit = unit;
	this->price = 0.0;
}
UnitPrice::~UnitPrice()
{
}
int UnitPrice::getUnit()
{
	return this->unit;
}
void UnitPrice::setUnit(int unit)
{
	this->unit = unit;
}
double UnitPrice::getPrice()
{
	return this->price;
}
void UnitPrice::calculate()
{

	if (this->unit <= 50)
	{
		this->price = (double)(this->unit) * rank[0];
	}
	else if (this->unit <= 100)
	{
		this->price = ((double)(this->unit) - 50) * rank[1] + 50 * rank[0];
	}
	else if (this->unit <= 200)
	{
		this->price = ((double)(this->unit) - 100) * rank[2] + 50 * rank[1] + 50 * rank[0];
	}
	else if (this->unit <= 300)
	{
		this->price = ((double)this->unit - 100) * rank[3] + 100 * rank[2] + 50 * rank[1] + 50 * rank[0];
	}
	else if (this->unit <= 400)
	{
		this->price = ((double)this->unit - 100) * rank[4] + 100 * rank[3] + 100 * rank[2] + 50 * rank[1] + 50 * rank[0];
	}
	else
	{
		this->price = ((double)this->unit - 100) * rank[5] + 100 * rank[4] + 100 * rank[3] + 100 * rank[2] + 50 * rank[1] + 50 * rank[0];
	}
}
void UnitPrice::calculate2()
{
	if (unit - 50.0 >= 0)
	{
		this->price += 50 * rank[0];
		unit = unit - 50;
	}
	if (unit - 50 >= 0)
	{
		this->price += 50 * rank[1];
		unit = unit - 50;
	}
	if (unit - 100 >= 0)
	{
		this->price += 100 * rank[2];
		unit = unit - 100;
	}
	if (unit - 100 >= 0)
	{
		this->price += unit * rank[3];
		unit = unit - 100;
	}
	if (unit - 100 >= 0)
	{
		this->price += unit * rank[4];
		unit = unit - 100;
	}
	if (unit - 100 >= 0)
	{
		this->price += unit * rank[5];
	}
}
void UnitPrice::showUnitPrice()
{
	cout<< "Bậc 1: 1.678 - Từ 0 - 50 kWh"
		<<"\nBậc 2: 1.734 - Từ 51 - 100 kWh"
		<<"\nBậc 3 : 2.014 - Từ 101 - 200 kWh"
		<<"\nBậc 4 : 2.536 - Từ 201 - 300 kWh"
		<<"\nBậc 5 : 2.834 - Từ 301 - 400 kWh"
		<<"\nBậc 6 : 2.927 - Từ 401 kwh trở lên"<<endl;
}