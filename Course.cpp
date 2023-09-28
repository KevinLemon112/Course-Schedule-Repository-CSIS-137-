// Kevin Babakhani, David Shahi, Katarina Pesic
// CSIS 137 - Fall 2021 online course
// Midterm Project
// 10/11/2021
//class Course

#include "Course.h"
#include "Time.h"
#include <iomanip>
#include <iostream>

using namespace std;

Course::Course(string num, string name, string dayMeet, double unit, Date startDate, Date endDate, Time startTime, Time endTime)
{
    courseNum = num;
    courseName = name;
    courseMeet = dayMeet;
    numUnits = unit;
    startD = startDate;
    endD = endDate;
    startT = startTime;
    endT = endTime;
}
Course::~Course()
{
    cout << "Course has been deleted." << endl;
}
void Course::setCourseNum(string num)
{
    courseNum = num;
}
void Course::setCourseName(string name)
{
    courseName = name;
}
void Course::setCourseMeet(string meet)
{
    courseMeet = meet;
}
void Course::setNumUnits(double u)
{
    numUnits = u;
}
void Course::setStartDate(int m, int d, int y)
{
    startD.setDay(d);
    startD.setMonth(m);
    startD.setYear(y);
}
void Course::setEndDate(int m, int d, int y)
{
    endD.setDay(d);
    endD.setMonth(m);
    endD.setYear(y);
}
void Course::setStartTime(int h, int m, string AMPM)
{
    startT.setHour(h);
    startT.setMinute(m);
    startT.setAMorPM(AMPM);
}
void Course::setEndTime(int h , int m, string AMPM)
{
    endT.setHour(h);
    endT.setMinute(m);
    endT.setAMorPM(AMPM);
}
string Course::getCourseNum()const
{
    return courseNum;
}
string Course::getCourseName()const
{
    return courseName;
}
string Course::getCourseMeet()const
{
    return courseMeet;
}
double Course::getNumUnits()const
{
    return numUnits;
}
Date Course::getStartDate()const
{
    return startD;
}
Date Course::getEndDate()const
{
    return endD;
}
Time Course::getStartTime()const
{
    return startT;
}
Time Course::getEndTime()const
{
    return endT;
}
ostream& operator<<(ostream& output, const Course& theCourse)
{
    output << fixed << setprecision(2)
        << "Course Info:" << "\t" << theCourse.courseNum << " -- " << theCourse.courseName
        << "\n# of Units: " << "\t" << theCourse.numUnits
        << "\nCourse Dates: " << "\t" << theCourse.startD << " - " << theCourse.endD
        << "\nMeeting Days: " << "\t" << theCourse.courseMeet
        << "\nMeeting Time: " << "\t" << theCourse.startT << " - " << theCourse.endT
        << "\nDaily Duration: " << theCourse.calcDailyDuration(theCourse.getStartTime(), theCourse.getEndTime()) << " hours\n" << endl;
    return output;
}
double Course::calcDailyDuration(Time start, Time end) const
{
    double hours = 0;
    hours = end - start;

    return hours;
}
