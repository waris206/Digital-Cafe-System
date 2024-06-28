#ifndef STOCKHANDLEBYADMIN_H
#define STOCKHANDLEBYADMIN_H
#include "stock.h"
#include<iostream>
using namespace std;
class StockHandleByAdmin : public stock {
    private:
    int input;
     int num_products ;
   // this class is inherit so it have all function of stock class also 
   // main reason ha iss class ko banane ki
   // ke kuch function the add ar remove ke jo sirf admin kar sakta
   // ar ine me inherit nai karna chahta tha
   public: // extra features
   StockHandleByAdmin();
   void  addstock();
   void removestock();
   int getNumItems();
   friend ostream&operator<<(ostream&abc ,const StockHandleByAdmin &stock);
   double  operator[](int index);
   bool operator!();
   void orderItems();

     
   
};

#endif
