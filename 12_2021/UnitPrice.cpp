#include <iostream>
using namespace std;
#include "UnitPrice.h"
UnitPrice::UnitPrice(int unit)
{
	this->unitRank = new int[7];
	for (int i = 0; i < 6; i++)
	{
		this->unitRank[i] = 0;
	}
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
	this->price *= 1000;
}
void UnitPrice::calculate2()
{
	// Neu chi dien bac 1
	if (unit - 50 <= 0)
	{
		unitRank[0] = unit;
	} else
	//Neu chi dien bac 2:
	if (unit - 100 <= 0)
	{
		unitRank[0] = 50;
		unitRank[1] = unit - 50;
	}else
		//Neu chi dien bac 3:
	if (unit - 200 <= 0)
	{
		unitRank[0] = 50;
		unitRank[1] = 50;
		unitRank[2] = unit - 100;
	}else
		//Neu chi dien bac 4:
	if (unit - 300 <= 0)
	{
		unitRank[0] = 50;
		unitRank[1] = 50;
		unitRank[2] = 100;
		unitRank[3] = unit - 200;
	}else
		//Neu chi dien bac 5:
	if (unit - 400 <= 0)
	{
		unitRank[0] = 50;
		unitRank[1] = 50;
		unitRank[2] = 100;
		unitRank[3] = 100;
		unitRank[4] = unit - 300;
	}
	//Neu chi dien bac 6:
	else
	{
		unitRank[0] = 50;
		unitRank[1] = 50;
		unitRank[2] = 100;
		unitRank[3] = 100;
		unitRank[4] = 100;
		unitRank[5] = unit - 400;
	}
	for (int i = 0; i < 6; i++)
	{
		this->price += unitRank[i] * priceRank[i];
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