#ifndef __TIMEs__
#define __TIMEs__

#include <iostream>
#include <iomanip>
class Times
{
public:
//constructor 
Times();
Times(int hours, int minutes);

//getter and setter

//getter for the hours and minutes

int getHours() const;
int getMinutes() const;
Times getTimes() const;

//setter for hours and minutes
void setHours(int hours);
void setMinutes(int minutes);
void setTimes(const Times& tm);

//Method
void AddHours(int hours); //use to add hours to the times
void SubtractHours(int hours);

 //int TimesDiff(const Times& tm) const; //return the difference between two times in minutes

//operator overloading

bool operator ==(const Times& tm) const;
bool operator !=(const Times& tm) const;
bool operator <(const Times& tm) const;
bool operator >(const Times& tm) const;
bool operator <=(const Times& tm) const;
bool operator >=(const Times& tm) const;

//With this operator we advance the times by minute
Times operator +=(int min);

//with this operator we diminish the times
Times operator -=(int min);

//Display the date in the format hh:mm (hours:minutes)
friend std::ostream& operator <<(std::ostream& os, const Times& tm);
//Read the date in the format hh:mm (hours:minutes)
friend std::istream& operator >>(std::istream& is, Times& tm);


private:
int _hours;
int _minutes;
void SimplifyTimes(); // simplify the type of the times so it can fit the 24 hours format

};


#endif