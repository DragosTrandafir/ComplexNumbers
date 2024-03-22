#include<iostream>
using namespace std;

#pragma once
class Date
{
public:
	Date();
	Date(unsigned short pyear, unsigned short pmonth, unsigned short pday);
	~Date();

	unsigned short get_year() const;
	unsigned short get_month() const;
	unsigned short get_day() const;

	void set_date(unsigned short year, unsigned short month, unsigned short day);

	friend ostream& operator<<(ostream& os, const Date& d);
	friend bool operator==(const Date& d1, const Date& d2);
	friend bool operator!=(const Date& d1, const Date& d2);
	friend bool operator<(const Date& d1, const Date& d2);
	friend bool operator<=(const Date& d1, const Date& d2);
	friend bool operator>(const Date& d1, const Date& d2);
	friend bool operator>=(const Date& d1, const Date& d2);

private:
	unsigned short year;
	unsigned short month;
	unsigned short day;
};

