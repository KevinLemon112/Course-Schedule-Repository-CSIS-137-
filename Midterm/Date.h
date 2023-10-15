// Kevin Babakhani, David Shahi, Katarina Pesic
// CSIS 137 - Fall 2021 online course
// Midterm Project
// 10/11/2021
// class Date

#ifndef DATE_H
#define DATE_H
#include <iostream>
using namespace std;

class Date
{
    friend ostream& operator<<(ostream&, const Date&);
    friend istream& operator>>(istream&, Date&);
private:
    int month; //1-12
    int day; //1-31 depending on month
    int year; //any year

    //utility function to check if day is proper for month and year
    int checkDay(int) const;

public:
    Date(int = 1, int = 1, int = 1990);
    void setDate(int, int, int);
    Date& setMonth(int);
    Date& setDay(int);
    Date& setYear(int);
    int getMonth() const;
    int getDay() const;
    int getYear() const;
    bool operator==(const Date&) const;
    bool operator!=(const Date&) const;
    bool operator>(const Date&) const;
    bool operator<(const Date&) const;
    bool operator<=(const Date&) const;
    bool operator>=(const Date&) const;
};
#endif

