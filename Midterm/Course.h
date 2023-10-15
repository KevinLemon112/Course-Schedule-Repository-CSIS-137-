// Kevin Babakhani, David Shahi, Katarina Pesic
// CSIS 137 - Fall 2021 online course
// Midterm Project
// 10/11/2021
// class Course

#ifndef course_H
#define course_H
#include "Date.h"
#include "Time.h"
#include <iostream>
#include <string>

using namespace std;

class Course {
    friend ostream& operator<<(ostream&, const Course&);
private:
    string courseNum;
    string courseName;
    string courseMeet;
    double numUnits;
    Date startD;
    Date endD;
    Time startT;
    Time endT;
public:

    Course(string = "CSIS 137", string = "Advanced C++", string = "T", double = 4.0, Date startDate = Date(), Date endDate = Date(), Time startTime = Time(), Time endTime = Time());
    ~Course();

    void setCourseNum(string);
    void setCourseName(string);
    void setCourseMeet(string);
    void setNumUnits(double);
    void setStartDate(int,int,int);
    void setEndDate(int,int,int);
    void setStartTime(int, int, string);
    void setEndTime(int, int, string);

    string getCourseNum()const;
    string getCourseName()const;
    string getCourseMeet()const;
    double getNumUnits()const;
    Date getStartDate()const;
    Date getEndDate()const;
    Time getStartTime()const;
    Time getEndTime()const;

    double calcDailyDuration(Time, Time)const;
};
#endif
