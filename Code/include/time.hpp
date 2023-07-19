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

private:
int _hours;
int _minutes;

void SimplifyTime(); // simplify the type of the time so it can fit the 24 hours format
};






#endif