#include<iostream>
#include<cstring>
#include"base.h"
using namespace std;
// simple logic ha constructor me aik fucntion call kia ha
// jisse bad me override kar diya jae ga 
Base ::Base(){
    login();
}
 void Base ::login(){
    // idar ham just welcmome karain ge user ko ++ 
    cout<<"Welcome to the system"<<endl;
 }
