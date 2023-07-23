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
Times Date::getTime() const {return theTime;};

//setter for year, month and day
void Date::setYear(int year){_year = year;};
void Date::setMonth(int month){_month = month;};
void Date::setDay(int day){_day = day;};

//operator compare date and time
bool Date::operator==(const Date& date) const
{
 if(_year == date.getYear() && _month == date.getMonth() && _day == date.getDay())
 {
    return true;
 }
 else 
   return false;
}

bool Date::operator<(const Date& date ) const
{
 int result = CompareDates(date);
 if(result == -1)
 {
   return true;
 }
 else if(result == 1)
 {
   return false;
 }
 else if(theTime < date.getTime())
 {
   return true;
 }
 else 
   return false;
}

bool Date::operator>(const Date& date) const
{
 int result = CompareDates(date);
 if(result == 1)
 {
   return true;
 }
 else if(result == -1)
 {
   return false;
 }
 else if(theTime > date.getTime())
 {
   return true;
 }
 else 
   return false;
}

bool Date::operator <=(const Date& date) const
 {
   if(*this < date || *this == date)
   {
      return true;
   }
   else 
      return false;
 }

bool Date::operator >=(const Date& date) const
{
   if(*this > date || *this == date)
   {
      return true;
   }
   else 
      return false;
}

bool Date::operator !=(const Date& date) const
{
   if(*this == date)
   {
      return false;
   }
   else 
      return true;
}

int Date::CompareDates(const Date& otherDate) const
{
   if(_year < otherDate.getYear())
   {
      return -1;
   }
   else if(_year > otherDate.getYear())
   {
      return 1;
   }
   else if(_month < otherDate.getMonth())
   {
      return -1;
   }
   else if(_month > otherDate.getMonth())
   {
      return 1;
   }
   else if(_day < otherDate.getDay())
   {
      return -1;
   }
   else if(_day > otherDate.getDay())
   {
      return 1;
   }
 
   return 0;
}

Date& Date::operator+=(int days)
{
   days += _day;
   if(days > DaysInMonth())
   {
    _day -= DaysInMonth();
   }
   if(_month < 12)
   {
      _month ++;
   }
   else
   {
      _month = 1;
      _year++;
   }
   return *this;
}
