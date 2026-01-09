#include <iostream>
#include <vector>
#include <string>
#include <windows.h>

#include "User.h"
#include "Teacher.h"
#include "Student.h"
#include "PlagiarismChecker.h"
#include "ReportFileHandler.h"
#include "Colors.h"

using namespace std;

int main()
{

    // OBJECTS & VARIABLES DECLARED EXACTLY LIKE YOUR ORIGINAL LOGIC EXPECTS
    Teacher t1("Sir Adnan", 1, "Object Oriented Programming");
    vector<Student> students;
    ReportFileHandler fileHandler;
    string assignmentText;
    int menuChoice;

    // HEADER PRINT (COLORS UNTOUCHED)
    setColor(11);
    cout << "\n==============================================\n";
    cout << "                PROJECT: GRADIENT              \n";
    cout << "==============================================\n\n";
    resetColor();

    // TEACHER INFO (UNTOUCHED)
    setColor(7);
    cout << "User Name: " << t1.getName() << endl;
    cout << "User ID  : " << t1.getId() << endl;
    t1.displayRole();
    resetColor();

    while (true)
    {

        // MENU HEADER (YOUR COLOR STAYS SAME)
        setColor(14);
        cout << "\n******** MAIN MENU ********\n";
        resetColor();

        // MENU OPTIONS (NOT CHANGED)
        setColor(7);
        cout << "1. Add Students\n"
             << "2. Enter Assignments\n"
             << "3. Check Plagiarism\n"
             << "4. Student Query\n"
             << "5. Exit\n"
             << "----------------------------\n";
        resetColor();

        // CHOICE INPUT (NOT CHANGED)
        setColor(7);
        cout << "Enter choice: ";
        resetColor();

        cin >> menuChoice;
        cin.ignore();

        if (menuChoice == 1)
        {
            string stuName, idStr;
            int stuID;
            int studentNumber = 1;

            cout << "\nEnter Students one by one (type END to stop):\n";

            for (;;)
            {
                setColor(13);
                cout << "\n----- Enter Student " << studentNumber << " Name: -----\n";
                resetColor();
                getline(cin, stuName);
                if (stuName == "END")
                    break;

                setColor(13);
                cout << "----- Enter Student " << studentNumber << " ID: -----\n";
                resetColor();
                getline(cin, idStr);
                if (idStr == "END")
                    break;

                stuID = stoi(idStr);
                students.push_back(Student(stuID, stuName));

                setColor(10);
                cout << "\nStudent added successfully!\n";
                resetColor();

                studentNumber++;
            }
        }

        else if (menuChoice == 2)
        {
            string line;
            int assignmentNumber = 1;
            assignmentText.clear();

            for (;;)
            {
                setColor(13);
                cout << "\n----- Enter Assignment " << assignmentNumber << ": -----\n";
                resetColor();
                getline(cin, line);
                if (line == "END")
                    break;
                assignmentText += line + " ";
                assignmentNumber++;
            }

            setColor(10);
            cout << "All assignments saved.\n";
            resetColor();
        }

        else if (menuChoice == 3)
        {
            float similarity = PlagiarismChecker::calculateSimilarity(assignmentText, assignmentText);
            float marks = PlagiarismChecker::assignMarks(similarity);

            for (auto &s : students)
            {
                s.setResult(similarity, marks);
                fileHandler.saveResult(s);
            }

            setColor(10);
            cout << "Plagiarism Checked. Results Saved.\n";
            resetColor();
        }

        else if (menuChoice == 4)
        {
            int studentID;
            cout << "Enter Student ID: ";
            cin >> studentID;
            cin.ignore();

            fileHandler.queryStudent(studentID);

            float claimMarks;
            cout << "\nEnter marks you think you deserve: ";
            cin >> claimMarks;
            cin.ignore();

            fileHandler.resolveMarkComplaint(studentID, claimMarks);
        }

        else if (menuChoice == 5)
        {
            setColor(12);
            cout << "Exiting program...\n";
            resetColor();
            break;
        }

        else
        {
            setColor(12);
            cout << "Invalid choice!\n";
            resetColor();
        }
    }

    return 0;
}