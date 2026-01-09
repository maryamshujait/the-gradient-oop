#include "Student.h"

Student::Student(int i, string n, float s, float m) : User(i, n)
{
    similarity = s;
    marks = m;
}

float Student::getSimilarity()
{
    return similarity;
}

float Student::getMarks()
{
    return marks;
}
