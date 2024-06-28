#include <iostream>
#include <fstream>
#include "student.h"
#include "color.h" // Assuming color.h contains the color functions definitions
using namespace std;

student::student()
{
    login();
}
// login fucntion ha students ke liye be
void student::login()
{
    fstream file;
    file.open("student.txt");
    if (file.fail())
    {
        markRed();
        cout << "File does not exist." << endl;
        resetColor();
        return;
    }
    else
    {
        
    

    const int maximum = 2;
    char **usernames = new char *[maximum];
    char **passwords = new char *[maximum];
    for (int i = 0; i < maximum; i++)
    {
        usernames[i] = new char[20];
        passwords[i] = new char[20];
    }

    int current = 0;
    while (current < maximum && file.getline(usernames[current], 20, '*') && file.getline(passwords[current], 20))
    {
        current++;
    }
    file.close();

    if (current == 0)
    {
        markRed();
        cout << "No credentials found in the file." << endl;
        resetColor();
        return;
    }

    user = new char[20];     // Allocate memory for name
    passcode = new char[20]; // Allocate memory for password

    bool logged = false;
    do
    {
        logged = false;

        markYellow();
        cout << "Enter username: ";
        resetColor();
        cin >> user;

        markYellow();
        cout << "Enter password: ";
        resetColor();
        cin >> passcode;

        for (int i = 0; i < current; ++i)
        {
            if (strcmp(user, usernames[i]) == 0 && strcmp(passcode, passwords[i]) == 0)
            {
                logged = true;
                showstudent();
                markGreen();
                cout << "Welcome " << "!!! " << endl;
                resetColor();
                studentdisplay();
                break;
            }
        }

        if (!logged)
        {
            markRed();
            cout << "Invalid username or password." << endl;
            cout << "Do you want to try again? Press 1 for yes and 0 for no: ";
            resetColor();
            cin >> choice;
            if (choice == 0)
                exit(0);
        }
    } while (!logged && choice != 0);

    // Deallocate memory
    delete[] user;
    delete[] passcode;

    for (int i = 0; i < maximum; i++)
    {
        delete[] usernames[i];
        delete[] passwords[i];
    }
    delete[] usernames;
    delete[] passwords;
}}
// also ye aik display ka function ha students powers
void student::studentdisplay()
{
    do
    {
        markYellow();
        cout << "------------------------------------------" << endl;
        cout << "|              Menu Options              |" << endl;
        cout << "|----------------------------------------|" << endl;
        cout << "| 1. Search and Order Food               |" << endl;
        cout << "| 2. Give Complaint                      |" << endl;
        cout << "| 3. Search Items                        |" << endl;
        cout << "| 4. Give and Schedule Order             |" << endl;
        cout << "| 5. See Notifications                   |" << endl;
        cout << "| 6.  Reservations                       |" << endl;
        cout << "| 7. Exit                                |" << endl;
        cout << "------------------------------------------" << endl;
        resetColor();
        cout << "Enter your choice: ";
        cin >> studentChoice;
        switch (studentChoice)
        {
        case 1:
            takeOrder();
            break;

        case 2:
            cp = new complaint;
            cp->setComplaint();
            break;

        case 3:
            search();
            break;

        case 4:
            giveAndScheduleOrder();
            break;

        case 5:
            cp = new complaint;
            cp->seenotification();
            break;
        case 6:
            reservation();
            break;
        case 7:
            markRed();
            cout << "Exiting Student Portal\n";
            resetColor();
            exit(-1);
            break;

        default:
            markRed();
            cout << "Invalid choice. Please try again.\n";
            cout << "Do you want to choose again?\nPress 1 for yes and 0 for no: ";
            resetColor();
            cin >> choice1;
            break;
        }
    } while (choice1 != 0 && studentChoice != 6);
}
// student jab  onlinr order day to is ka fucntion ha
void student::giveAndScheduleOrder()
{
    maxlength = 30;
    ofstream ordersFile("orders.txt", ios::app);
    if (!ordersFile.fail())
    {
        char *itemName;
        itemName = new char[30];
        int quantities;
        int selectedItem;
        double totalBill = 0.0;
        char scheduled[30];
        // Display the stock before entering the loop
        loadstock_from_file();

        do
        {
            // Get item name
            markYellow();
            cout << "Enter the name of the item you want to order: " << endl;

            cin.getline(itemName, maxlength);
            cout << itemName;

            resetColor();
            // Search for the item in the stock
            int index = -1;
            for (int i = 0; i < 10; ++i)
            {
                if (strcmp(name[i], itemName) == 0)
                {
                    index = i;
                    break;
                }
            }

            if (index != -1)
            {
                // Get order quantity
                markYellow();
                cout << "\nEnter the quantity you want to order: ";
                resetColor();
                cin >> quantities;
                cin.ignore();
                markCyan();
                cout << "tell us about the time also (service 24/7?) " << endl;
                resetColor();
                markYellow();
                cin.getline(scheduled, maxlength);
                resetColor();

                if (quantities <= quantity[index])
                {
                    // Display order details and ask for confirmation
                    markYellow();
                    cout << "\t\tOrder Details:\n";
                    cout << "\t\tItem: " << itemName << "\n";
                    cout << "\t\tQuantity: " << quantities << "\n";
                    cout << "\t\tTotal Price: " << quantities * price[index] << "\n";
                    resetColor();

                    char confirmOrder;
                    markYellow();
                    cout << "Do you want to confirm the order (y/n)? ";
                    resetColor();
                    cin >> confirmOrder;

                    if (confirmOrder == 'y' || confirmOrder == 'Y')
                    {
                        // Update stock and save the changes to the file
                        quantity[index] -= quantities;
                        selectedItem = index;
                        trans = new transaction(name, selectedItem, quantities, price);
                        totalBill += quantities * price[index];
                        updatestock();

                        markYellow();
                        cout << "------------------------------------------" << endl;
                        cout << "|              Final Bill                |" << endl;
                        cout << "|----------------------------------------|" << endl;
                        cout << "| Total Amount: " << totalBill << "      |" << endl;
                        cout << "| Thanks for online ordering!            |" << endl;
                        cout << "| Order placed successfully!             |" << endl;
                        cout << "------------------------------------------" << endl;
                        resetColor();

                        // Save the order details to the file
                        ordersFile << itemName << " " << quantities << " " << scheduled << "\n";

                        // Ask if the user wants to order more
                        char orderMore;
                        markYellow();
                        cout << "Do you want to order more (y/n)? ";
                        resetColor();
                        cin >> orderMore;

                        if (orderMore != 'y' && orderMore != 'Y')
                        {
                            break;
                        }
                    }
                    else
                    {
                        markRed();
                        cout << "Order canceled.\n";
                        resetColor();
                    }
                }
                else
                {
                    markRed();
                    cout << "Not enough stock available for the order.\n";
                    resetColor();
                }
            }
            else
            {
                markRed();
                cout << "Item not found in the stock. Please enter a valid item name." << endl;

                resetColor();
            }

        } while (true);
         tips();
        ordersFile.close();
    }
    else
    {
        markRed();
        cout << "Error opening orders file.\n";
        resetColor();
    }
}
// for cout <<
ostream &operator<<(ostream &abc, const student &obj)
{
    markYellow();
    abc << "user name is " << obj.getuser() << endl;
    resetColor();
    return abc;
}

student::~student()
{
    if (trans != NULL)
    {
        delete trans;
    }
    if (cp != NULL)
    {
        delete cp;
    }
    delete[] user;
    delete[] passcode;
}

const char *student::getuser() const
{
    return user;
}

const char *student::getPasscode() const
{
    return passcode;
}

istream &operator>>(istream &abc, student &obj)
{
    markYellow();
    cout << "enter username" << endl;
    resetColor();
    char *uuser;
    uuser = new char[100];
    abc.getline(uuser, 100);
    delete[] uuser;
    return abc;
}
// aik extra function bonus ke liye ha
void student::reservation()
{
    int table = 0;
    char confirm = 'n';

    do
    {
        markCyan();
        cout << "Enter the table number you want to reserve: " << endl;
        cin >> table;
        resetColor();
        if (table > 0 && table < 20)
        {
            markMagenta();
            cout << "Are you sure you want to reserve this table? (y/n)" << endl;
            cin >> confirm;
            resetColor();

            if (confirm == 'y' || confirm == 'Y')
            {
                markGreen();
                cout << "Table reserved" << endl;
                resetColor();
                ofstream file;
                file.open("reservation.dat", ios::binary | ios::app); // Open in append mode

                if (file.fail())
                {
                    markRed();
                    cout << "File is not opened" << endl;
                    resetColor();
                }
                else
                {

                    file.write(reinterpret_cast<char *>(&table), sizeof(int));
                    file << endl;
                    file.close();
                }
            }
            else
            {
                markRed();
                cout << "Table reservation is cancelled" << endl;

                resetColor();
            }
        }
        else
        {
            markRed();
            cout << "Invalid table number. Table reservation is cancelled." << endl;
            resetColor();
        }

        // Clear input buffer
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        markBlue();
        cout << "Do you want to reserve more tables? (y/n)" << endl;
        cin >> confirm;
        resetColor();
        // Clear input buffer
        cin.ignore(numeric_limits<streamsize>::max(), '\n');

    } while (confirm == 'y' || confirm == 'Y');
}
void student::tips() {
    markMagenta();
    cout << "Do you want to give a tip to the employee?" << endl;
    resetColor();
    markYellow();
    cout << "1. Yes" << endl;
    cout << "2. No" << endl;

    int choice;
    cin >> choice;
     resetColor();
    if (choice == 1) {
        markGreen();
        cout << "Enter tip amount: ";
        int tips;
        cin >> tips;
        resetColor();
        if (tips >= 0) {
            ofstream tipFile("tip.txt", ios::app); // Using ofstream for writing to file
            if (tipFile.fail()) {
                markRed();
                cout << "Error: Failed to open tip file." << endl;
                resetColor();
            } else {
                tipFile << tips ;
                tipFile<<endl;
                tipFile.close();
                markCyan();
                cout << "Tip given successfully." << endl;
                resetColor();
            }
        } else {
            markRed();
            cout << "Invalid tip amount. Tip can't be less than 0." << endl;
            resetColor();
        }
    } else if (choice == 2) {
        markYellow();
        cout << "Thank you for your order." << endl;
        resetColor();
    } else {
        markRed();
        cout << "Invalid option." << endl;
        resetColor();
    }
}
