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

int Times::TimesDiff(const Times& tm) const
{
 
}