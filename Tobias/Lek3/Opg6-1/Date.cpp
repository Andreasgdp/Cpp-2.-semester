#include "Date.h"

#include <math.h>


Date::Date()
{

}

Date::Date(int year , int month , int day)
{
    _year = year;
    _month = month;
    _day = day;
}

void Date::setYear(int year){
    _year = year;
}
void Date::setMonth(int month){
    _month = month;
}
void Date::setDay(int day){
    _day = day;
}

int Date::getDayOfWeek(){
    int w = 0;
    int d = _day;

    int m = _month -2;
    if (m <= 0){
        m += 12;
    }

    if (_month == 1 or 2){
        _year -= 1;
    }

    int y = _year % 100;
    int c = _year / 100;

    w = fmod(d + floor(2.6 * m - 0.2) + y + floor(y / 4) + floor(c / 4) - 2 * c, 7);

    if (w < 0){
        w += 7;
    }
    return w;
}
