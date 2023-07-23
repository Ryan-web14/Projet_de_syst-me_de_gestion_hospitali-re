#include "date.hpp"

//Constructor
Date::Date()
{
    _year = 0;
    _month = 0;
    _day = 0;
}

//getter and setter
//getter for year, month and day
int Date::getYear() const{return _year;};
int Date::getMonth() const{return _month;};
int Date::getDay() const{return _day;};

//setter for year, month and day
void Date::setYear(int year){_year = year;};
void Date::setMonth(int month){_month = month;};
void Date::setDay(int day){_day = day;};

//operator compare date and time
