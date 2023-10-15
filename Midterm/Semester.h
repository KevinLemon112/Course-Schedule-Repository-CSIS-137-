// Kevin Babakhani, David Shahi, Katarina Pesic
// CSIS 137 - Fall 2021 online course
// Midterm Project
// 10/11/2021
// class Semester

#ifndef Semester_H
#define Semester_H
#include "Date.h"
#include <iostream>
#include <string>

using namespace std;

class Semester {

    friend ostream& operator<<(ostream&, const Semester&);
    friend istream& operator>>(istream&, Semester&);

private:
    string semName;
    Date startSem;
    Date endSem;
public:
    Semester(string = "Fall 2021", Date start = Date(), Date end = Date());

    void setSemesterName(string);
    void setSemesterStart(Date);
    void setSemesterEnd(Date);

    string getSemesterName()const;
    Date getSemesterStart()const;
    Date getSemesterEnd()const;

};
#endif
