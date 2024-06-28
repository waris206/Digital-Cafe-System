#ifndef STOCKANDDISPLAY_H
#define STOCKANDDISPLAY_H
#include "transaction.h"
#include "stock.h"
#include <cstring>
#include <limits>

class StockandDisplay : public stock
{
private:
  char *item_name;
  int max;
  char *itemName;
  int quantities;
  int selectedItem;
  double totalBill;
  transaction *trans;
  // this class will work as it can search an item from stock ..and second thing it can do as it can take order and then preoceed them also
  // ye clas aik to search kar rha ha second..order ko be le leta ha
public:
  void search();
  void takeOrder();
  ~StockandDisplay();
  // Setter function for item_name
  void setItemName(const char *itemName);

  // Getter function for item_name
  const char *getItemName() const;

  // Operator overloading
  StockandDisplay &operator=(const StockandDisplay &other);
  bool operator==(const StockandDisplay &other) const;
  bool operator!=(const StockandDisplay &other) const;
  char operator[](int index) const;
  bool operator!();
  friend ostream &operator<<(ostream &, const StockandDisplay &);
};

#endif