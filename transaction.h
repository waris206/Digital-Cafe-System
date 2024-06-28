#ifndef TRANSACTION_H
#define TRANSACTION_H

#include"onlineorder.h"


class transaction {
    private:
     char **item;
     int quantity;
     double *price;
     double *total;
     int selected;
     
    public:
       transaction();
        transaction(char ** , int ,int,double*);
        ~transaction();
        void setItem(char **);
        void setQuantity(int);
        void setPrice(double *);
        void setTotal(double *);
        void setSelected(int);

        char ** getItem();
        int getQuantity();
        double * getPrice();
        double * getTotal();
        int getSelected();

        
};
#endif // TRANSACTION_H