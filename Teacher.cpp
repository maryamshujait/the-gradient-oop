#include "Teacher.h"

Teacher::Teacher(int i, string n) : User(i, n) {}

void Teacher::createAssignment(string title)
{
    cout << "Assignment Created: " << title << endl;
}
