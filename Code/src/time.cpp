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

