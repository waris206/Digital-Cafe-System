#ifndef EMPLOYEE_H
#define EMPLOYEE_h
#include "Base.h"
#include "searchandorder.h"
#include "transaction.h"
#include <fstream>
#include <iostream>
#include <cstring>
using namespace std;
// here i will define class of employee credentials
// isse muje multiple inheritance karni pari ha
class Employee : public Base, public onlineOrder
{
private:
   char *name;
   char *password;
   int choice;
   int employeeChoice;
   // here i will aggrate this
   StockandDisplay *snd;

public:
   void login();
   Employee();
   void display();
   void bonussalary();
   ~Employee();
};

#endif