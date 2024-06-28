#include "complaint.h"
#include "color.h"
// constructor ke andar initlize kar rha
complaint::complaint()
{
    max_size = 100;
    register_complaint = new char[max_size];
}
// ye student ka fucntio ha jidar wo admin se bat kar ke koi complaint de sakta ha
void complaint::setComplaint()
{
    if (register_complaint == NULL)
    {
        markRed();
        cout << "Error: Memory not allocated" << endl;
        resetColor();
        exit(0);
    }
    else
        markMagenta();
    cout << "enter your complaint (on any issue ) ?" << endl;
    resetColor();
    cin.ignore();
    ofstream complaintfile; // binary file handling how ha idar
    complaintfile.open("complaint.dat", ios::binary);
    markGreen();
    cin.getline(register_complaint, max_size);
    
    resetColor();
    complaintfile.write(register_complaint, strlen(register_complaint));
    complaintfile.close();
    markCyan();
    cout << "complaint Register Succesfully" << endl;
    resetColor();
    markBlue();
    cout << "we will respond shortly " << endl;
    resetColor();
    complaintfile.close();
}
// getter function hain
char *complaint::getComplaint()
{
    return register_complaint;
}
// ar iss fucntion me student admin ki taraf se kia hoa koi message dekh pae ga
void complaint::seenotification()
{
    ifstream file("notification.dat");
    notification = new char[100];
    if (file.fail())
    {
        markRed();
        cout << "Error: File not found" << endl;
        resetColor();
        return;
    }

    // Read and display the file contents
    while (file.getline(notification, 100))
    {
        markYellow();
        cout << notification << " ";
    }
    resetColor();
    cout << endl;

    // Close the file
    file.close();

    // Open the file in truncation mode to clear its contents
    ofstream clear("notification.dat", ios::trunc);
    clear.close();
}
complaint::~complaint()
{
    if (register_complaint != NULL)
    {
        delete[] register_complaint;
    }
    register_complaint = NULL;
    delete[] notification;
    notification = NULL;
}
// setter function ha
void complaint::setComplaint(const char *newComplaint)
{
    if (register_complaint != NULL)
    {
        delete[] register_complaint;
    }
    max_size = strlen(newComplaint) + 1;      // Update max_size
    register_complaint = new char[max_size];  // Allocate memory for the new complaint
    strcpy(register_complaint, newComplaint); // Copy the new complaint
}

// Getter function ha
const char *complaint::getComplaint() const
{
    return register_complaint;
}
// kuch operator overloading ke function hain
bool complaint::operator!()
{
    if (register_complaint == NULL)
    {
        return true;
    }
    else
    {
        return false;
    }
}
// Assignment operator overloading for the complaint class
complaint &complaint::operator=(const complaint &other)
{
    // Avoid self-assignment
    // Deallocate existing memory
    delete[] register_complaint;
    delete[] notification;

    // Copy the complaint from the other object
    max_size = other.max_size;
    register_complaint = new char[max_size];
    strcpy(register_complaint, other.register_complaint);

    // Copy the notification from the other object
    notification = new char[max_size];
    strcpy(notification, other.notification);

    return *this;
}
