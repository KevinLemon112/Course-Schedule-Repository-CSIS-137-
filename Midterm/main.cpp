// Kevin Babakhani, David Shahi, Katarina Pesic
// CSIS 137 - Fall 2021 online course
// Midterm Project
// 10/11/2021

#include <iostream>
#include <iomanip>
#include <string>
#include "CourseSchedule.h"
#include "Time.h"
#include "Course.h"
#include "Semester.h"
#include "Date.h"

using namespace std;

int main()
{
    Semester sem;
    CourseSchedule schedule;
    Time startTime;
    Time endTime;
    Date startDate;
    Date endDate;
    Course course;

    string name;
    int maxClasses = 0;
    int numClasses = 0;
    int num = 0;
    char selection;
    double courseUnits;
    string courseNum;
    string courseName;
    string courseMeet;
    
    cout << "What is your name?" << endl;
    getline(cin, name);

    schedule.setName(name);

    cin >> sem;
    schedule.setSemester(sem);

    cout << "What is the maximum number of classes you are allowed to take " << schedule.getName() << "?" << endl;
    cin >> maxClasses;

    do {
        cout << "\nCOURSE ENTRY MENU FOR: \t" << sem << endl;
        cout << "------------------------------------------------------------------------" << endl;
        cout << "1) Enter a new course" << endl;
        cout << "2) Remove a course" << endl;
        cout << "3) Print a Semester Schedule" << endl;
        cout << "q) Quit the program" << endl;
        cin >> selection;

        if (selection == '1')
        {

            if (numClasses < maxClasses)
            {

                cout << "What is the course number?" << endl;
                cin.ignore();
                getline(cin,courseNum);
                course.setCourseNum(courseNum);

                cout << "What is the name of the course?" << endl;
                getline(cin,courseName);
                course.setCourseName(courseName);

                cout << "What are the meeting days of the course (Ex: Monday and Wednesday is MW)?" << endl;
                getline(cin, courseMeet);
                course.setCourseMeet(courseMeet);

                cout << "How many units is this class?" << endl;
                cin >> courseUnits;
                course.setNumUnits(courseUnits);

                cout << "Please enter the time for when the class starts." << endl;
                cin >> startTime;
                course.setStartTime(startTime.getHour(), startTime.getMinute(), startTime.getAMorPM());

                cout << "Please enter the time for when the class ends." << endl;
                cin >> endTime;
                course.setEndTime(endTime.getHour(), endTime.getMinute(), endTime.getAMorPM());

                cout << "Please enter the date for when the class starts." << endl;
                cin >> startDate;
                course.setStartDate(startDate.getMonth(), startDate.getDay(), startDate.getYear());

                cout << "Please enter the date for when the class ends." << endl;
                cin >> endDate;
                course.setEndDate(endDate.getMonth(), endDate.getDay(), endDate.getYear());

                schedule.checkDates(sem, startDate, endDate);
                schedule.addCourse(course);

                numClasses++;
                schedule.setNumCourses(numClasses);
            }
            
            else if (numClasses >= maxClasses)
            {
                cout << "Max number of classses has been reached." << endl;
            }
        }
        
        else if (selection == '2')
        {

            cout << "What course number do you want removed?" << endl;
            cin >> num;
            cout << "Removing a course." << endl;
            
            schedule.removeCourse(course, num);
        }
        
        else if (selection == '3')
        {
            cout << schedule;
        }
        
        else if (selection == 'q' || selection == 'Q')
        {
            cout << "Thank you for using the program. Enjoy your school year!" << endl;
        }
        
        else
        {
            cout << "Invalid selection." << endl;
        }
    } while (selection != 'q' && selection != 'Q');

    return 0;
}
