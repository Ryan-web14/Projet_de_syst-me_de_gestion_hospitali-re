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

   longDate = day + " ";

   switch(_month)
   {
      case 1 : longDate += "January";
               break;
      case 2 : longDate += "February";
               break;
      case 3 : longDate += "March";
               break;
      case 4 : longDate += "April";
               break;
      case 5 : longDate += "May";
               break;
      case 6 : longDate += "June";
               break;
      case 7 : longDate += "July";
               break;
      case 8 : longDate += "August";
               break;
      case 9 : longDate += "September";
               break;
      case 10 : longDate += "October";
               break;
      case 11 : longDate += "November";
               break;
      case 12 : longDate += "December";
               break;
   }

   longDate = longDate + " " + year;

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

int Date::DaysInMonth() const
{
   switch(_month)
   {
      case 1 : return 31;
               break;
      case 2 : if(IsLeapYear())
               {
                  return 29;
               }
               else 
                  return 28;
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
             return 30;
   }
}

std::ostream& operator<<(std::ostream& os, const Date& date)
{
   os << date.getDay() <<"/" << date.getMonth() << "/" << date.getYear() << " " << date.getTime();
   return os;
}

std::istream& operator >>(std::istream& is,Date& date)
{
   int month;
   int year;
   int day;
   char slash;
   is>>day>>slash>>month>>slash>>year;
   date.setDay(day);
   date.setMonth(month);
   date.setYear(year);
   return is;
}

void Date::DisplayDate() const 
{
   std::cout << this->ToLongDate() << " " << this->getTime() << std::endl;
}