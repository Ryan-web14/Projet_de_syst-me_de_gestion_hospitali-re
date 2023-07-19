#ifndef __TIME__
#define __TIME__

class Time
{
public:
Time() = default;
Time(int hours, int minutes);

//getter and setter

//getter for the hours and minutes

int getHours() const;
int getMinutes() const;
Time getTime() const;

//setter for hours and minutes
void setHours(int hours);
void setMinutes(int minutes);
void setTime(const Time& tm);

//Method
void AddHours(int hours); //use to add hours to the time
void SubtractHours(int hours);

 //int TimeDiff(const Time& tm) const; //return the difference between two time in minutes

//operator overloading

bool operator ==(const Time& tm) const;
bool operator !=(const Time& tm) const;
bool operator <(const Time& tm) const;
bool operator >(const Time& tm) const;
bool operator <=(const Time& tm) const;
bool operator >=(const Time& tm) const;

//With this operator we advance the time by minute
Time operator +=(int min);

//with this operator we diminish the time
Time operator -=(int min);


private:
int _hours;
int _minutes;

void SimplifyTime(); // simplify the type of the time so it can fit the 24 hours format
};

//Display the date in the format hh:mm (hours:minutes)
friend std::ostream& operator <<(std::ostream& os, const Time& tm);
//Read the date in the format hh:mm (hours:minutes)
friend std::istream& operator >>(std::istream& is, Time& tm);





#endif