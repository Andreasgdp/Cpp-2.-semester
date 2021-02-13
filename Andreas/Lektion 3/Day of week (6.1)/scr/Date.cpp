#include "../Headers/Date.h"
#include <cmath>

Date::Date()
{
}

Date::Date(int year, int month, int day)
{
	mYear = year;
	mMonth = month;
	mDay = day;
}

void Date::setYear(int year)
{
	mYear = year;
}

void Date::setMonth(int month)
{
	mMonth = month;
}

void Date::setDay(int day)
{
	mDay = day;
}

int Date::getDayOfWeek()
{
	int w = 0;
	int d = mDay;

	int m = mMonth - 2;
	if (m <= 0)
	{
		m = m + 12;
	}

	int y = mYear % 100;
	int c = mYear / 100;

	w = fmod(d + floor(2.6 * m - 0.2) + y + floor(y / 4) + floor(c / 4) - 2 * c, 7);
	if (w < 0)
	{
		w += 7;
	}

	return w;
}
