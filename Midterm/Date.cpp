// Kevin Babakhani, David Shahi, Katarina Pesic
// CSIS 137 - Fall 2021 online course
// Midterm Project
// 10/11/2021
// class Date

#include <iostream>
#include "Date.h"
#include <string>

using namespace std;

//constructor validates month and calls utility function to validate day
Date::Date(int mn, int dy, int yr)
{
    setDate(mn, dy, yr);
}
Date& Date::setMonth(int m)
{
    month = (m >= 1 && m <= 12) ? m : 1;
    return *this;
}
Date& Date::setDay(int d)
{
    day = (d >= 1 && d <= 31) ? d : 1;
    return *this;
}
Date& Date::setYear(int y)
{
    year = (y >= 1 && y <= 2021) ? y : 2021;
    return *this;
}
void Date::setDate(int mn, int dy, int yr)
{
    if (mn > 0 && mn <= 12)
    {
        month = mn;
    }
    else
    {
        month = 1;
    }
    dy = 1;
    year = yr;  //could also validate year

    checkDay(dy);  //to validate the day
}
int Date::getMonth() const
{
    return month;
}
int Date::getDay() const
{
    return day;
}
int Date::getYear() const
{
    return year;
}
//PRIVATE COST UTILITY FUNCTION
int Date::checkDay(int testDay) const
{
    static const int daysPerMonth[12] = { 31,28,31,30,31,30,31,31,30,31,30,31 };

    if (testDay > 0 && testDay <= daysPerMonth[month])
    {
        return testDay;
    }
    
    if (month == 2 && testDay == 29 && (year % 400 == 0 || (year % 4 == 0 && year % 100 != 0)))     //determine whether testDay is valid for a specific month
    {
        return testDay;
    }
    
    cout << "Invalid Day. " << testDay << " was set to 1" << endl;
    testDay = 1;
    return testDay;
}

ostream& operator<<(ostream& output, const Date& theDate)
{
    output << theDate.getMonth() << "/" << theDate.getDay() << "/" << theDate.getYear();
    return output;
}

istream& operator>>(istream& input, Date& theDate)
{
    cout << "What is the month? (as a number)" << endl;
    input >> theDate.month;

    input.ignore();

    cout << "What is the day? (as a number)" << endl;
    input >> theDate.day;
    theDate.day = theDate.checkDay(theDate.day);

    input.ignore();

    cout << "What is the year? (as a number)" << endl;
    input >> theDate.year;

    return input;
}
bool Date::operator==(const Date& theDate) const
{
    if ((theDate.month == month) && (theDate.day == day) && (theDate.year == year))
    {
        return true;
    }

    else
    {
        return false;
    }
}
bool Date::operator!=(const Date& theDate) const
{
    if ((theDate.month == month) && (theDate.day == day) && (theDate.year == year))
    {
        return false;
    }

    else
    {
        return true;
    }
}
bool Date::operator<(const Date & theDate) const
{
    if (year < theDate.year)
    {
        return true;
    }

    else if ((year == theDate.year) && (month < theDate.month))
    {
        return true;
    }

    else if ((year == theDate.year) && (month == theDate.month) && (day < theDate.day))
    {
        return true;
    }

    else
    {
        return false;
    }
}
bool Date::operator>(const Date & theDate) const
{
    if (year > theDate.year)
    {
        return true;
    }

    else if ((year == theDate.year) && (month > theDate.month))
    {
        return true;
    }

    else if ((year == theDate.year) && (month == theDate.month) && (day > theDate.day))
    {
        return true;
    }

    else
    {
        return false;
    }
}
bool Date::operator<=(const Date & theDate) const
{
    if (year < theDate.year)
    {
        return true;
    }

    else if ((year == theDate.year) && (month < theDate.month))
    {
        return true;
    }

    else if ((year == theDate.year) && (month == theDate.month) && (day < theDate.day))
    {
        return true;
    }

    else if ((theDate.month == month) && (theDate.day == day) && (theDate.year == year))
    {
        return true;
    }

    else
    {
        return false;
    }
}
bool Date::operator>=(const Date & theDate) const
{
    if (year > theDate.year)
    {
        return true;
    }

    else if ((year == theDate.year) && (month > theDate.month))
    {
        return true;
    }

    else if ((year == theDate.year) && (month == theDate.month) && (day > theDate.day))
    {
        return true;
    }

    else if ((theDate.month == month) && (theDate.day == day) && (theDate.year == year))
    {
        return true;
    }

    else
    {
        return false;
    }
}
