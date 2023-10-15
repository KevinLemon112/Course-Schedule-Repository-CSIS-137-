// Kevin Babakhani, David Shahi, Katarina Pesic
// CSIS 137 - Fall 2021 online course
// Midterm Project
// 10/11/2021
// class Semester

#include "Semester.h"
#include "Date.h"

using namespace std;

Semester::Semester(string name, Date start, Date end)
{
    name = "Fall 2021";
    start.setDate(8, 30, 2021);
    end.setDate(12, 15, 2021);
}
void Semester::setSemesterName(string name)
{
    semName = name;
}
void Semester::setSemesterStart(Date start)
{
    startSem = start;
}
void Semester::setSemesterEnd(Date end)
{
    endSem = end;
}
string Semester::getSemesterName()const
{
    return semName;
}
Date Semester::getSemesterStart()const
{
    return startSem;
}
Date Semester::getSemesterEnd()const
{
    return endSem;
}

ostream& operator<<(ostream& output, const Semester& theSemester)
{
    output << theSemester.getSemesterName() << " (" << theSemester.getSemesterStart() << " - " << theSemester.getSemesterEnd() << ")";

    return output;
}

istream& operator>>(istream& input, Semester& theSemester)
{
    cout << "What is the name of the semester?" << endl;
    getline(input, theSemester.semName);

    cout << "When does the semester start? (MM/DD/YYYY)" << endl;
    input >> theSemester.startSem;

    input.ignore();

    cout << "When does the semester end? (MM/DD/YYYY)" << endl;
    input >> theSemester.endSem;

    while (theSemester.endSem < theSemester.startSem) {

        cout << "The start date and end date are not in sequential order. Please re-enter your dates." << endl;

        cout << "When does the semester start? (MM/DD/YYYY)" << endl;
        input >> theSemester.startSem;

        input.ignore();

        cout << "When does the semester end? (MM/DD/YYYY)" << endl;
        input >> theSemester.endSem;
    }

    return input;
}
