#ifndef ONLINEORDER_H
#define ONLINEORDER_H
#include "stock.h"
// here  i willl talk about some thing online ortder
class onlineOrder : public stock
{
private:
  int max_products;
  char *itemName;
  int quantities;
  char *scheduledTime;
  int num_products;

public:
  onlineOrder(); // constructor
  void viewAndRespondToOrders();
  
  ~onlineOrder();
  bool operator!();
  friend ostream &operator<<(ostream &, const onlineOrder &);
  // Setter methods
  void setItemName(const char *itemName);
  void setQuantities(int quantities);
  void setScheduledTime(const char *scheduledTime);

  // Getter methods
  const char *getItemName() const;
  int getQuantities() const;
  const char *getScheduledTime() const;
  // operator overloading 
  bool operator==(const onlineOrder &);
  bool operator!=(const onlineOrder &);
};

#endif
