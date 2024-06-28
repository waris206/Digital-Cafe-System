#ifndef ADMIN_H
#define ADMIN_H
#include<iostream>
#include<fstream>
#include<cstring>
#include"base.h"
#include"stock.h"
#include"onlineorder.h"
#include"adminotherdealing.h"
#include"stockhandlebyadmin.h"
using namespace std;
// first class of project 
// iss ko base s inherit kia hoa polymorphsim ko achive karne ke liye
class admin : public Base{
    private:
    int size,size1;
     char *username;
     char *passcode;
     int choice;
     int choice1;
     int choice_for_while;
     // now have call aggragte class
     stock *stockobject;
     onlineOrder *online;
     adminotherdealing *deal;
     StockHandleByAdmin *powers;
     public:
     admin();
     void login();
    void  display();
    
    ~admin();
    bool operator!();
    
    
   // ~admin();
};


#endif
