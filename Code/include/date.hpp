#ifndef __Date__
#define __Date__

#include "time.hpp"
#include <sstream>
#include <iomanip>

class Date
{
public:
    //constructor
    Date();
    //getter
    int getYear() const;
    int getMonth() const;
    int getDay() const;
    Times getTime() const;

    //setter
    void setYear(int year);
    void setMonth(int month);
    void setDay(int day);
    void setTime(const Times& time);

    //operator compare date and time
    bool operator ==(const Date& date) const;
    bool operator <(const Date& date) const; 
    bool operator >(const Date& date) const;
    bool operator <=(const Date& date) const;
    bool operator >=(const Date& date) const;
    bool operator !=(const Date& date) const;

    //Compare two dates and return -1, 0 or 1
    //return -1 when the instance is earlier than the otherDate
    //return 0 when the instance and otherDate are equals that means it is the same date 
    //return 1 when the instance is later than the second date  
    int CompareDates(const Date& otherDate) const;

    //Move the date by days ahead
    Date& operator +=(int days);

    //Write the corresponding month of the date by creating a string 
    std::string ToLongDate(); // Corrected here

private:
    int _year;
    int _month;
    int _day; 
    Times theTime;
    //Determines if the year is a leap year
    //To check if a year is a leap year, we need to follow these steps:
    //If the year is divisible by 4 but not by hundred, it is not a leap year
    //If it is divisible by 4 and 100, it must be divisible by 400 to be a leap year
    //If it is divisible by 4, 100 and 400, it is a leap year
    bool IsLeapYear() const;

    //return the number of days in a month
    int DaysInMonth() const; 

    friend std::ostream& operator <<(std::ostream& os, const Date& date);
    friend std::istream& operator >>(std::istream& is, Date& date);
};

#endif

