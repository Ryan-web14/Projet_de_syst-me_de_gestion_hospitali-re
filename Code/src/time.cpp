#include "time.hpp"

//constructor bu default 
Times::Times()
{
    _hours = 0;
    _minutes = 1;
}

Times::Times(int hours, int minutes)
{
  _hours = hours;
  _minutes = minutes;
}

//getters and setters
//setter for hours and minutes 
void Times::setHours(int hours){_hours = hours;};
void Times::setMinutes(int minutes){_minutes = minutes;};

//getter for hours and minutes
int Times::getHours() const{return _hours;};
int Times::getMinutes() const {return _minutes;};

//advance the time by hours 
void Times::AddHours(int hours)
{
  _hours += hours;
  SimplifyTimes();
}

void Times::SubtractHours(int hours)
{
  _hours -= hours;
  SimplifyTimes();
}

int Times::TimesDiff(const Times& nextTime) const
{
 int mins;

 if(*this > nextTime)
 {
  if(_minutes > nextTime.getMinutes())
  {
    mins = _minutes - nextTime.getMinutes();
    mins += (_hours - nextTime.getHours()) * 60;
  }
  else
  {
    mins = (_minutes + 60) - nextTime.getMinutes();
    mins += (_hours - 1 - nextTime.getHours()) * 60;
  }
  return mins;
 }
 else 
   return -1;
}

//operator
bool Times::operator ==(const Times& tm) const
{
  return(_hours == tm._hours && _minutes == tm._minutes);
}

bool Times::operator !=(const Times& tm) const
{
  return(_hours != tm.getHours() || _minutes != tm.getMinutes());
}

bool Times::operator <(const Times& tm) const
{
  if(_hours < tm.getHours())
    return true;
  else if(_hours == tm.getHours())
  {
    if(_minutes < tm.getMinutes())
      return true;
    else
      return false;
  }
  else
    return false;
} 

bool Times::operator >(const Times& tm) const 
{
  if(_hours > tm.getHours())
  {
    return true;
  }
  else if(_hours < tm.getHours ())
  {
    return false;
  }
  else
  {
    if(_minutes > tm.getMinutes())
      return true;
    else
      return false;
  }
}

bool Times::operator <=(const Times& tm) const 
{
  if(*this < tm || *this == tm)
    return true;
  else 
    return false;
}

bool Times::operator >=(const Times& tm) const
{
  if(*this > tm || *this == tm)
    return true;
  else
    return false;
}

//move the time forward by minutes
Times Times::operator +=(int min)
{
 _minutes += min;
 SimplifyTimes();
 return *this;
}

//move the time backward by minutes
Times Times::operator-=(int min)
{
  _minutes -= min;
  SimplifyTimes();
  return *this;
}

//Simplify the time so it stays in the 24 hours format
void Times::SimplifyTimes()
{
 if(_minutes >= 60)
 {
  _minutes -= 60;
  _hours += 1;
 }
 if(_hours > 23)
 {
  _hours -= 24;
 }
 if(_minutes < 0)
 {
  _minutes += 60;
  _hours -= 1;
 }
}

//overloading of the ostream operator
//Display the time in the 24 hours format
std::ostream& operator <<(std::ostream& os,const Times& tm)
{
  os << tm.getHours() << ":" << std::setw(2) << std::setfill('0') <<tm.getMinutes();
  return os;
}

std::istream& operator >>(std::istream& is, Times& tm)
{
  int minutes, hours;
  char colon;
 
  is >> hours >> colon >> minutes;
  tm.setHours(hours);
  tm.setMinutes(minutes);
  return is;
}