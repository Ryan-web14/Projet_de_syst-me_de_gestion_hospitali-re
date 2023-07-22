#ifndef __DATE__
#define __DATE__

#include <iostream>
#include "time.hpp"
class Date
{

public:
//constructor
//set month to one and year to 2023
Date();

//getter and setter 
//getter
int getYear() const;
int getMonth() const;
int getDay() const;


private:
int _year;
int _month;
int _day; 
}


#endif