// Kevin Babakhani, David Shahi, Katarina Pesic
// CSIS 137 - Fall 2021 online course
// Midterm Project
// 10/11/2021
// class Time

#ifndef TIME_H
#define TIME_H
#include <iostream>
using namespace std;

class Time
{
    friend ostream& operator<<(ostream&, const Time&);
    friend istream& operator>>(istream&, Time&);
private:
    int hour;  //0-23 (24 hour clock format)
    int minute; //0-59s
    string ampm; //added member variable to use in istream operator
public:
    //default constructor
    Time(int = 0, int = 0, string = "pm");

    //set functions - not const since they modify private data
    //The & return type enables cascading
    Time& setTime(int, int, string);
    Time& setHour(int);
    Time& setMinute(int);
    Time standardToUniversal(Time standardTime);
    double operator-(const Time&);
    void setAMorPM(string);
    string getAMorPM() const;

    //get functions - (normally always declared const)
    int getHour() const;
    int getMinute() const;
    //print functions - (normally always declared const since they do not modify private members, merely inspect
    void printUniversal() const;
    void printStandard()const;
};

#endif
