#include "admin.h"
#include "stock.h"
#include "onlineorder.h"
#include <iostream>
#include <fstream>
#include <cstring>
#include <limits>
#include "color.h"
// void stockshow();
//  definition  ha constructor ki 
admin::admin()
{
    stockobject = new stock;
    if (!stockobject)
    {
        markRed();
        cerr << "Failed to allocate memory for stockobject." << endl;
        resetColor();
        exit(-1);
    }

    login();
}
/*here ---- idar fucntion ha login ke liye -----------*/
void admin ::login()
{
    const int MAX_LENGTH = 20; // Maximum length for username and password
    char check_username[MAX_LENGTH];
    char check_passcode[MAX_LENGTH];

    // Open the file to read credentials
    ifstream loginFile("credential.txt");
    if (loginFile.fail()) // error dekhne ke liye 
    {
        markRed();
        cout << "File is not opened" << endl;
        resetColor();
        exit(-1);
    }
    else
    {
        // ye file se read karain gain 
        loginFile.getline(check_username, MAX_LENGTH, '\n');
        loginFile.getline(check_passcode, MAX_LENGTH);
        loginFile.close();
         // size ko find karne ke liye aesa kia 
        size = strlen(check_username) + 1;
        size1 = strlen(check_passcode) + 1;
        username = new char[size + 1];
        passcode = new char[size1];
        // now check if it is match or not so
        int choice;
        bool loggedIn = false;

        do
        {
            loggedIn = false;
            // Prompt for username ke nam enter kare 
            markCyan();
            cout << "\nEnter username: ";
            cin >> username;
            resetColor();
            cin.ignore();

            // Prompt for password 
            markMagenta();
            cout << "\nEnter password: ";
            cin >> passcode;
            resetColor();
            
            cout << endl;

            // now check ke sahi be ha ke nahi ha 
            if (strncmp(username, check_username, MAX_LENGTH) == 0 && strncmp(passcode, check_passcode, MAX_LENGTH) == 0)
            {

                loggedIn = true;
                showadmin();
                cout << endl
                     << endl;
                display();
            }
            else
            {
                markRed();
                cout << "Sorry! Invalid username or password." << endl;
                cout << "Do you want to try again?" << endl;
                cout << "Press 0 for exit or any other key to re-enter credentials: ";
                resetColor();
                cin >> choice;
                if (choice == 0)
                    exit(0);
                // Clear karna zarori ha cin.ignore jo ye wala ha proper aik \n ko ignore karta ha 
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
            }
        } while (!loggedIn && choice != 0);
    }
}

// display ka fucntion jis me sare function hain aage 
void admin::display()
{
    int choice;
    do
    {
        markCyan(); // Applying cyan color 

        cout << "\t \t*************************************************\n";
        cout << "\t \t*               Admin Menu                     *\n";
        cout << "\t \t*************************************************\n\n";
        resetColor(); // Resetting color
        markGreen();
        cout << "----------------------------------------------------------" << endl;
        cout << "|   1-->  Stock display                                    |" << endl;
        cout << "----------------------------------------------------------" << endl;
        cout << "|   2-->  Remove  stock OR New items order                 |" << endl;
        cout << "----------------------------------------------------------" << endl;
        cout << "|   3--> Delete credential of employees/students           |" << endl;
        cout << "----------------------------------------------------------" << endl;
        cout << "|   4--> Display Best Seller Employee                      |" << endl;
        cout << "----------------------------------------------------------" << endl;
        cout << "|   5--> Notifications                                     |" << endl;
        cout << "----------------------------------------------------------" << endl;
        cout << "|   6--> online orders                                     |" << endl;
        cout << "----------------------------------------------------------" << endl;
        cout << "|   7--> Complaints                                        |" << endl;
        cout << "----------------------------------------------------------" << endl;
        cout << "|   8--> Stats                                             |" << endl;
        cout << "----------------------------------------------------------" << endl;
        cout << "|   9--> Reservation                                       |" << endl;
        cout << "----------------------------------------------------------" << endl;
         
        cout << "|   10--> Tip managment                                    |" << endl;
        cout << "----------------------------------------------------------" << endl;
        cout << "|   11--> Exit                                             |" << endl;
        cout << "----------------------------------------------------------" << endl;
        resetColor();
        markYellow();
        cout << "Enter your choice: ";

        cin >> choice;
        resetColor();
        switch (choice)
        {
        case 1:
            markYellow(); // yellow color kia hoa 
            cout << "\nStock display : " << endl;
            resetColor(); // Resetting color
            stockobject->loadstock_from_file();
            
            break;
        case 2:
            markYellow(); // Applying yellow color 
            cout << "\n Remove  stock or order new items" << endl;
            resetColor(); // Resetting color
            powers = new StockHandleByAdmin;
            break;
        case 3:
            markYellow(); // Applying yellow color 
            cout << "\nDelete credential of employees/students" << endl;
            resetColor(); // Resetting color
            deal = new adminotherdealing;
            deal->reademployees();
            break;
        case 4:
            markYellow(); // Applying yellow color 
            cout << "\nDisplay Best Seller Employee" << endl;
            resetColor(); // Resetting color
            deal = new adminotherdealing;
            deal->bestseller();
            break;
        case 5:
            markYellow(); // Applying yellow color 
            cout << "\nNotifications" << endl;
            resetColor(); // Resetting color
            deal = new adminotherdealing;
            deal->writenotification();
            break;
        case 6:
            markYellow(); // Applying yellow color 
            cout << "\nonline orders " << endl;
            resetColor(); // Resetting color
            online = new onlineOrder;
            if (!online)
            {
                cerr << "Failed to allocate memory for online." << endl;
                exit(-1);
            }
            online->viewAndRespondToOrders();
            break;
        case 7:
            markYellow(); // Applying yellow color 
            cout << "\ncomplaints: \n";
            resetColor(); // Resetting color
            deal = new adminotherdealing;
            deal->seecomplaint();
            break;
        case 8:
            markYellow(); // Applying yellow color 
            cout << "\nstats :" << endl;
            resetColor(); // Resetting color
            stockobject->stats();
            break;
            case 9:
            deal = new adminotherdealing;
             deal->confirmreservation();
           
            break;
             case 10:
               deal= new adminotherdealing;
               deal->tipemployee();

             break;
        case 11:
            markRed(); // Applying yellow color 
            cout << "\nExiting admin menu." << endl;
            resetColor(); // Resetting color
            exit(-1);
            break; 
        default:
            markRed(); // Applying red color to error message
            cout << "\nInvalid choice. Please try again." << endl;
            resetColor(); // Resetting color
            break;
        }
    } while (true);
}

bool admin::operator!()
{
    if (username == NULL)
    {
        return false;
    }
    else
        return true;
}
admin::~admin()
{
    // ye distrcutor ha jo sab ko delete kar rha..to save memeory leakage also 
    if (username != NULL)
    {
        delete[] username;
        username = NULL;
    }
    if (passcode != NULL)
    {
        delete[] passcode;
        passcode = NULL;
    }
    delete[] powers;
    delete[] deal;
    delete[] stockobject;
    delete[] online;
}
