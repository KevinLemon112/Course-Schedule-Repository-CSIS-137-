// Kevin Babakhani, David Shahi, Katarina Pesic
// CSIS 137 - Fall 2021 online course
// Midterm Project
// 10/11/2021
// class Time
#include "Time.h"
#include <iostream>
#include <iomanip>
#include <string>
#include <cmath>

using namespace std;

//Constructor function to initialize private data
//remember a constructor is called whenever a new object of
//a class data type is instantiated, if a constructor is not defined the C++ do
//nothing constructor is run, it is better to ALWAYS have your own contructor
//once you have your own constructor the default is no longer available
//Constructors can and should be overloaded
//Constructors cannot be const since they always manipulate private data
Time::Time(int hour, int minute, string AMPM)
{
    setTime(hour, minute, AMPM);
}
/*SET FUNCTIONS: Never const since they need to modify private member data*/

//setTime function now is set up to enable cascading
Time& Time::setTime(int hour, int minute, string AMPM)
{
    setHour(hour);
    setMinute(minute);
    setAMorPM(AMPM);
    return *this;
}
//setHour function is now set up to enable cascading
Time& Time::setHour(int h)
{
    hour = (h >= 0 && h < 24) ? h : 0;  //validates hour, if valid set to h, else set to 0
    return *this;
}
//setMinute function is now set up to enable cascading
Time& Time::setMinute(int m)
{
    minute = (m >= 0 && m < 60) ? m : 0;  //validates minute, if valid set to m, else set to 0
    return *this;
}
/*GET FUNCTIONS:  Do not modify private member data normally always const*/

//get Hour
int Time::getHour() const  //must be const since prototype is const
{
    return hour;
}
//get Minute
int Time::getMinute() const  //must be const since prototype is const
{
    return minute;
}

Time Time::standardToUniversal(Time standard)
{
    Time universal;
    string ampm;

    ampm = standard.getAMorPM();
    int hr = standard.getHour();
    int min = standard.getMinute();

    while (ampm != "am" && ampm != "AM" && ampm != "pm" && ampm != "PM") {
        cout << "Invalid. Try again" << endl;
        cin >> ampm;
        setAMorPM(ampm);
    }
    if (ampm == "pm" || ampm == "PM") {
        hour = hr + 12;
        minute = min;
        universal.setHour(hour);
        universal.setMinute(minute);
    }
    else if (ampm == "am" || ampm == "AM") {
        hour = hr;
        minute = min;
        universal.setHour(hour);
        universal.setMinute(minute);
    }
    return universal;
}
/*PRINT FUNCTIONS:  Normally do not modify private member data so should be const*/

void Time::printUniversal()const  //must be const since prototype is const
{
    cout << "Time converted to universal is : " << setfill('0') << setw(2) << getHour() << ":" << setw(2) << getMinute() << endl;
}
ostream& operator<<(ostream& output, const Time& timeNum)
{
    output << ((timeNum.getHour() == 0 || timeNum.getHour() == 12) ? 12 : timeNum.getHour() % 12) << ":"
           << setfill('0') << setw(2) << timeNum.getMinute() << setw(2) << timeNum.getAMorPM();

    return output;
}
istream& operator>>(istream& input, Time& timeNum)
{
    cout << "At what hour?" << endl;
    input >> timeNum.hour;

    input.ignore();

    cout << "At what minute?" << endl;
    input >> timeNum.minute;

    input.ignore();

    cout << "Is the time AM or PM?" << endl;
    input >> timeNum.ampm;

    return input;
}
double Time::operator-(const Time& timeNum)
{
    double hourNum = 0;
    double minuteNum = 0;
    double min = 0;

    if (((ampm == "am" || ampm == "AM") && (timeNum.ampm == "pm" || timeNum.ampm == "PM")) || ((ampm == "pm" || ampm == "PM") && (timeNum.ampm == "am" || timeNum.ampm == "AM")))
    {
        minuteNum = abs(minute - timeNum.getMinute());
        min = minuteNum / 60.0;
        hourNum = abs(hour - timeNum.getHour() + 12) + min;
    }
    else if (((ampm == "am" || ampm == "AM") && (timeNum.ampm == "am" || timeNum.ampm == "AM")) || ((ampm == "pm" || ampm == "PM") && (timeNum.ampm == "pm" || timeNum.ampm == "PM")))
    {
        minuteNum = abs(minute - timeNum.getMinute());
        min = minuteNum / 60.0;
        hourNum = abs(hour - timeNum.getHour()) + min;
    }

    return hourNum;
}
void Time::printStandard()const  //must be const since prototype is const
{
    cout << ((hour == 0 || hour == 12) ? 12 : hour % 12) << ":"
        << setfill('0') << setw(2) << minute << ":" << setw(2) << (hour < 12 ? "AM" : "PM") << endl;
}
void Time::setAMorPM(string amORpm)
{
    ampm = amORpm;
}
string Time::getAMorPM()const
{
    return ampm;
}
