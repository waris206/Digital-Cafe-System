#ifndef STOCK_H
#define STOCK_H
// make class names stock
#include <iostream>
#include <fstream>
#include <cstring>
using namespace std;

class stock
{
protected:
  char **name;
  int *quantity;
  double *price;
  double *total;
  int num_items;

public:
  stock();
  void loadstock_from_file();
  void displaystock();

  void sortstock();
  void updatestock();
  void stats();

  ~stock();
  const char *getName(int);
  int getQuantity(int);
  double getPrice(int);
  double getTotal(int);
  void setName(int index, const char *itemName);
  void setQuantity(int index, int itemQuantity);
  void setPrice(int index, double itemPrice);
  friend ostream &operator<<(ostream &, stock &);
  friend istream &operator>>(istream &, stock &);
  bool operator!();
  stock &operator=(const stock &);
  stock(const stock &);
  stock &operator++();
  stock &operator--();
  stock operator+(const stock &);
  stock operator-(const stock &);
  friend bool operator==(const stock &, const stock &);
  friend bool operator!=(const stock &, const stock &);

  double operator[](int);
};

#endif