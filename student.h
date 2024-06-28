#ifndef STUDENT_H
#define STUDENT_H
#include"base.h"
#include"searchandorder.h"
#include"complaint.h"
class student : public Base , public StockandDisplay {
  private:
   char *user;
   char *passcode;
   int choice;
   int studentChoice, choice1;
   int maxlength;
  public:
  
   student();
   void login();
   void studentdisplay();
   void giveAndScheduleOrder();
   void tips();
   complaint *cp;
   transaction *trans;
   ~student();
   void reservation();
   const char* getuser() const;
   const char* getPasscode() const;
 friend ostream& operator<<(ostream& abc , const student&obj);
 friend istream& operator>>(istream& abc,student &obj);
};
#endif
