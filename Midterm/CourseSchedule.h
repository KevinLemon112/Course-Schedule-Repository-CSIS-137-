// Kevin Babakhani, David Shahi, Katarina Pesic
// CSIS 137 - Fall 2021 online course
// Midterm Project
// 10/11/2021
// class CourseSchedule

#ifndef CourseSchedule_H
#define CourseSchedule_H
#include "Date.h"
#include "Time.h"
#include "Course.h"
#include "Semester.h"
#include <iostream>
#include <string>

class CourseSchedule {
    friend ostream& operator<<(ostream&, const CourseSchedule&);
private:
    int maxSize;
    string name;
    Semester sem;
    Course* coursePointer;
    int numCourses;
public:
    CourseSchedule(string = " ", Semester sem = Semester(), int = 7); //program would not run if we tried to dynamically allocate the number of courses the student is allowed to take. Error: "Access violation writing location"
    ~CourseSchedule();

    void setName(string);
    void setSemester(Semester);
    void setNumCourses(int);

    string getName() const;
    Semester getSemester() const;
    int getNumCourses() const;
    void addCourse(Course);
    bool checkDates(Semester, Date, Date);
    void removeCourse(Course, int);
};
#endif
