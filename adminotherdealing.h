#ifndef ADMINDEALING_H
#define ADMINDEALING_H
// direct compose hogee 
class adminotherdealing
{
private:
  char *complaint1;
  char **name;
  char **password;
  int max_size;
  int max_employees;

public:
  void seecomplaint();
  void writenotification();
  void reademployees();
  void displayemployees();
  void addemployees();
  void removeemployees();
  void bestseller();
  void tipemployee();
  void confirmreservation();
  ~adminotherdealing();
  void setComplaint(const char *newComplaint);
  void setName(int index, const char *newName);
  void setPassword(int index, const char *newPassword);

  // Getter methods
  const char *getComplaint() const;
  const char *getName(int index) const;
  const char *getPassword(int index) const;
  bool operator!();

  // Operator overloading
  bool operator==(const adminotherdealing &other) const;
};
#endif
