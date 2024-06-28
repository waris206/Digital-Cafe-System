#ifndef COMPLAINT_H
#define COMPLAINT_H

#include "admin.h"

class complaint {
private:
    char *register_complaint;
    int max_size;
    char *notification;
public:
    complaint();
    void setComplaint();
    char* getComplaint();
    void seenotification();
    ~complaint();
    bool operator!();
     void setComplaint(const char* newComplaint);

    // Getter method to get the complaint
    const char* getComplaint() const;
    complaint& operator=(const complaint&);
};

#endif
