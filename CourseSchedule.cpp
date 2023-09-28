// Kevin Babakhani, David Shahi, Katarina Pesic
// CSIS 137 - Fall 2021 online course
// Midterm Project
// 10/11/2021
//class CourseSchedule

#include <iostream>
#include "CourseSchedule.h"
#include "Time.h"
#include "Course.h"
#include "Semester.h"
#include "Date.h"
#include <string>

using namespace std;

int num = 0;

CourseSchedule::CourseSchedule(string n, Semester sem, int maxCourse)
{
    maxSize = maxCourse;
    n = " ";
    numCourses = 0;
    coursePointer = new Course[maxSize];
    sem = Semester();
}

CourseSchedule::~CourseSchedule()
{
    delete[] coursePointer;
}

void CourseSchedule::setName(string n)
{
    name = n;
}

void CourseSchedule::setSemester(Semester theSemester)
{
    sem = theSemester;
}
void CourseSchedule::setNumCourses(int numC)
{
    numCourses = numC;
}

string CourseSchedule::getName()const
{
    return name;
}

Semester CourseSchedule::getSemester() const
{
    return sem;
}

int CourseSchedule::getNumCourses() const
{
    return numCourses;
}

bool CourseSchedule::checkDates(Semester theSemester, Date startingDate, Date endingDate) //Not perfect. Does not work in some cases. We tried our best
{
    if (startingDate < theSemester.getSemesterStart())
    {
        cout << "Starting date of the class comes before the start of the semester. Enter a valid date." << endl;
        cin >> startingDate;
        sem.setSemesterStart(startingDate);

        return true;
    }
    else if (endingDate > theSemester.getSemesterEnd())
    {
        cout << "Ending date of the class comes after the end of the semester. Enter a valid date." << endl;
        cin >> endingDate;
        sem.setSemesterStart(endingDate);

        return true;
    }
    else if (startingDate > theSemester.getSemesterEnd())
    {
        cout << "Starting date of the class comes after the end of the semester. Enter a valid date." << endl;
        cin >> startingDate;
        sem.setSemesterStart(startingDate);

        return true;
    }
    else if (endingDate < theSemester.getSemesterStart())
    {
        cout << "Ending date of the class comes before the start of the semester. Enter a valid date." << endl;
        cin >> endingDate;
        sem.setSemesterStart(endingDate);

        return true;
    }
    else
    {
        return false;
    }
}

void CourseSchedule::addCourse(Course add)
{
   if (checkDates(sem, add.getStartDate(), add.getEndDate()) == false){
     coursePointer[num] = add;
     numCourses++;
     num++;
   }
}

void CourseSchedule::removeCourse(Course remove, int num2)
{
    if (checkDates(sem, remove.getStartDate(), remove.getEndDate()) == false){
        coursePointer[num2 - 1] = remove;
        numCourses--;
    }
}

ostream& operator<<(ostream& output, const CourseSchedule& theCourse)
{
    output << "CLASS SCHEDULE\n----------------------- \nName: " << theCourse.getName()
        << "\nSemester: " << theCourse.getSemester()
        << "\nNumber of Classes: " << theCourse.getNumCourses()
        << "\n----------------------------------------\n";
        for (int i = 0; i < theCourse.getNumCourses(); i++)
        {
            output << *(theCourse.coursePointer + i);
        }
    return output;
}
