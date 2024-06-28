#include <iostream>
#include "admin.h"
#include "employee.h"
#include "base.h"
#include "student.h"
#include "color.h"
#include "stockhandlebyadmin.h"
#include "complaint.h"
#include "adminotherdealing.h"
#include <windows.h>
using namespace std;

// Declaration of the function ar in ke andar basically ham base class
// ke pointer se start kara rah epolymorphism ko achive karne ke liye

void adminfunction();
void employeefunction();
void studentfunction();

int main()
{
    int choice, choice_for_while;
      show(); // this show logo of our company

    markYellow();
    cout << "---------------------------" << endl;
    cout << "|  Press 1 for Admin       |" << endl;
    cout << "|  Press 2 for Employee    |" << endl;
    cout << "|  Press 3 for Student     |" << endl;
    cout << "|  Press 0 to Exit         |" << endl;
    cout << "---------------------------" << endl;
    resetColor();
    markBlue();
    cout << "Enter the corresponding number: ";
    resetColor();
    do
    {
        cin >> choice;
        switch (choice)
        {
        case 1:
            adminfunction();
            break;
        case 2:
            employeefunction();
            break;
        case 3:
            studentfunction();
            break;
        default:
            markRed();
            cout << "Invalid input ";
            cout << "do you want to try again ? " << endl;
            resetColor();
            markGreen();
            cout << "press 0 for exit or press any key to continue" << endl;
            resetColor();
            cin >> choice_for_while;
            break;
        }
    } while (choice_for_while != 0);

    return 0;
}

// Definition of the function
void adminfunction()
{
    Base *b = nullptr;
    admin ad;
    b = &ad;
}
void employeefunction()
{
    Base *b = nullptr;
    Employee emp;
    b = &emp;
}
void studentfunction()
{
    Base *b = nullptr;
    student stu;
    b = &stu;
}
