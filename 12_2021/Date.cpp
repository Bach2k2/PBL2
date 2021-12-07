#include "Date.h"
int Date::days[] = { 31,28,31,30,31,30,31,31,30,31,30,31 };
Date::Date(int D, int M, int Y)
{
	setDate(D, M, Y);
}
void Date::setDate(int DD, int MM, int YY) {
	
	this->month = (MM>=1&&MM<=12)?MM:1;
	this->year = (YY >= 1900 && YY <= 2100) ? YY : 1900;
	if (month == 2 && isLeapYear(YY))
	{
		this->day = 29;
	}
	this->day = (DD >= 1 && DD <= days[month - 1]) ? DD : 1;
}
int Date::isLeapYear(int year)
{
	if (year % 400 == 0 || (year % 100 != 0 && year % 4 == 0))
		return 1;
	else return 0;
}
int Date::endOfMonth(int D)
{
	if (month == 2 && isLeapYear(year))
		return D == 29;
	else return D == days[month - 1];
}
void Date::increaseDay()
{
	if (month == 12 && endOfMonth(day))
	{
		this->day = 1;
			this->month = 1;
			this->year++;
	}
	else
	{
		if (endOfMonth(day))
		{
			this->day = 1;
			this->month++;
		}
		else
		{
			this->day++;
		}
	}
}
//prefix
Date Date::operator ++()
{
	increaseDay();
	return *this;
}
Date Date::operator++(int i)
{
	Date date=*this;
	increaseDay();
	return date;
}
const Date& Date::operator+=(int DD)
{
	if (day + DD > days[month - 1])
	{
		int remain = day + DD - days[month - 1];
		this->day = remain;
		if (month == 12)
		{
			month = 1;
			year++;
		}
		else month++;
	}
	else
	{
		day += DD;
	}
	return *this;
}
ostream& operator<<(ostream& out, const Date& date)
{
	out << date.day << "/" << date.month << "/" << date.year;
	return out;
}
int Date::getMonth()
{
	return this->month;
}
