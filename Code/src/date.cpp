#include "date.hpp"

//Constructor
Date::Date()
{
    _year = 0;
    _month = 0;
    _day = 0;
}

Date::Date(int year, int month, int day)
{
    if (year < 0 || month < 1 || month > 12 || day < 1 || day > DaysInMonth(month)) 
    {
        throw std::invalid_argument("Invalid date");
    }
    _year = year;
    _month = month;
    _day = day;
}
//getter and setter
//getter for year, month and day
void Date::setYear(int year) {
    if (year < 0) throw std::invalid_argument("Invalid year");
    _year = year;
}

void Date::setMonth(int month) {
    if (month < 1 || month > 12) throw std::invalid_argument("Invalid month");
    _month = month;
}

void Date::setDay(int day) {
    if (day < 1 || day > DaysInMonth(_month, _year)) throw std::invalid_argument("Invalid day");
    _day = day;
}
Times Date::getTime() const {return theTime;};

//setter for year, month and day
void Date::setYear(int year){_year = year;};
void Date::setMonth(int month){_month = month;};
void Date::setDay(int day){_day = day;};

void Date::setTime(const Times& time){theTime = time;};

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

// bool Date::operator<(const Date& date ) const
// {
//  int result = CompareDates(date);
//  if(result == -1)
//  {
//    return true;
//  }
//  else if(result == 1)
//  {
//    return false;
//  }
//  else if(theTime < date.getTime())
//  {
//    return true;
//  }
//  else 
//    return false;
// }

//More efficient and maintainable version of the above
bool Date::operator<(const Date& otherDate) const 
{
 if (_year < otherDate.getYear())
   return true;

 if (_year > otherDate.getYear())
   return false;

 if (_month < otherDate.getMonth())
   return true;

 if (_month > otherDate.getMonth())
   return false;

 if (_day < otherDate.getDay())
   return true;

 if (_day > otherDate.getDay())
   return false;

 return theTime < otherDate.getTime();
}

// bool Date::operator>(const Date& date) const
// {
//  int result = CompareDates(date);
//  if(result == 1)
//  {
//    return true;
//  }
//  else if(result == -1)
//  {
//    return false;
//  }
//  else if(theTime > date.getTime())
//  {
//    return true;
//  }
//  else 
//    return false;
// }

//More efficient and maintainable version of the above
bool Date::operator>(const Date& otherDate) const 
{
    if (_year > otherDate.getYear())
        return true;

    if (_year < otherDate.getYear())
        return false;

    if (_month > otherDate.getMonth())
        return true;

    if (_month < otherDate.getMonth())
        return false;

    if (_day > otherDate.getDay())
        return true;

    if (_day < otherDate.getDay())
        return false;

    return theTime > otherDate.getTime();
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
    _day += days;
    while (_day > DaysInMonth(_month)) 
    {
        _day -= DaysInMonth(_month);
        _month++;
        if (_month > 12) 
        {
            _month = 1;
            _year++;
        }
    }
    return *this;
}

 std::string Date::ConvertIntToString(int integer) const
{
   std::string s;
   std::stringstream conv;
   conv << integer;
   s = conv.str();
   return s;
}


std::string Date::ToLongDate() const 
{
   std::string day;
   std::string year;
   std::string longDate;

   day = ConvertIntToString(_day);
   year = ConvertIntToString(_year);

   longDate = year + " ";

   switch(_month)
   {
      case 1 : longDate += "Janvier";
               break;
      case 2 : longDate += "Fevrier";
               break;
      case 3 : longDate += "Mars";
               break;
      case 4 : longDate += "Avril";
               break;
      case 5 : longDate += "Mai";
               break;
      case 6 : longDate += "Juin";
               break;
      case 7 : longDate += "Juillet";
               break;
      case 8 : longDate += "Aout";
               break;
      case 9 : longDate += "Septembre";
               break;
      case 10 : longDate += "Octobre";
               break;
      case 11 : longDate += "Novembre";
               break;
      case 12 : longDate += "Decembre";
               break;
   }

   longDate = longDate + " " + day;

   return longDate;
}

bool Date::IsLeapYear() const
{
   if(_year % 4 == 0 && _year % 100 != 0)
   {
      return true;
   }
   else if(_year % 4 == 0 && _year % 100 == 0 && _year % 400 == 0)
   {
      return true;
   }
   else 
      return false;
}

bool Date::IsLeapYear(int year) const
{
   if(year % 4 == 0 && year % 100 != 0)
   {
      return true;
   }
   else if(year % 4 == 0 && year % 100 == 0 && year % 400 == 0)
   {
      return true;
   }
   else 
      return false;
}

int Date::DaysInMonth(int month) const
{
   switch(month)
   {
      case 1 : return 31;
               break;
      case 2 : return IsLeapYear() ? 29 : 28;
               break;
      case 3 : return 31;
               break;
      case 4 : return 30;
               break;
      case 5 : return 31;
               break;
      case 6 : return 30;
               break;
      case 7 : return 31;
               break;
      case 8 : return 31;
               break;
      case 9 : return 30;
               break;
      case 10 : return 31;
               break;
      case 11 : return 30;
               break;
      case 12 : return 31;
               break;
      default: 
            throw std::invalid_argument("Invalid month");
   }
}

int Date::DaysInMonth(int month, int year) const
{
   switch(month)
   {
      case 1 : return 31;
               break;
      case 2 : return IsLeapYear(year) ? 29 : 28;
               break;
      case 3 : return 31;
               break;
      case 4 : return 30;
               break;
      case 5 : return 31;
               break;
      case 6 : return 30;
               break;
      case 7 : return 31;
               break;
      case 8 : return 31;
               break;
      case 9 : return 30;
               break;
      case 10 : return 31;
               break;
      case 11 : return 30;
               break;
      case 12 : return 31;
               break;
      default: 
            throw std::invalid_argument("Invalid month");
   }
}

std::ostream& operator<<(std::ostream& os, const Date& date)
{
   os << date.getDay() <<"/" << date.getMonth() << "/" << date.getYear() << " " << date.getTime();
   return os;
}

std::istream& operator >>(std::istream& is, Date& date) {
    int month, year, day;
    char slash;
    is >> day >> slash >> month >> slash >> year;
    if (year < 0 || month < 1 || month > 12 || day < 1 || day > date.DaysInMonth(month, year)) {
        is.setstate(std::ios::failbit); // et the failbit
        return is;
    }
    date.setDay(day);
    date.setMonth(month);
    date.setYear(year);
    return is;
}

void Date::DisplayDate() const 
{
   std::cout << this->ToLongDate() << " " << this->getTime() << std::endl;
}