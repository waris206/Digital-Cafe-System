#include "employee.h"
#include "color.h"

Employee::Employee()
{
    snd = new StockandDisplay;
    if (!snd)
    {
        markRed();
        cerr << "Failed to allocate memory for snd." << endl;
        resetColor();
        return;
    }
    login();
}
// login fnction ha employee ke liye
void Employee::login()
{
    fstream file;
    file.open("employeecredential.txt");
    if (file.fail())
    {
        markRed();
        cout << "File does not exist." << endl;
        resetColor();
        return;
    }
    else
    {
        // file read karni ha iss me ham ne
        const int maximum = 5;
        char **usernames = new char *[maximum];
        char **passwords = new char *[maximum];
        for (int i = 0; i < maximum; i++)
        {
            usernames[i] = new char[20];
            passwords[i] = new char[20];
        }

        int current = 0;
        while (current < maximum && file.getline(usernames[current], 20, '$') && file.getline(passwords[current], 20))
        {
            current++;
        }
        file.close();

        if (current == 0)
        {
            markYellow();
            cout << "No credentials found in the file." << endl;
            resetColor();
            return;
        }

        name = new char[20];     // Allocate memory for name
        password = new char[20]; // Allocate memory for password

        bool logged = false;
        do
        {
            logged = false;
            markCyan();
            // nam pooch rahe employee se be
            cout << "Enter username: ";
            cin >> name;
            resetColor();
            markGreen();
            cout << "Enter password: ";
            cin >> password;
            resetColor();
            for (int i = 0; i < current; ++i)
            {
                if (strcmp(name, usernames[i]) == 0 && strcmp(password, passwords[i]) == 0) // check kar rhae agar equal hon
                {
                    logged = true;
                    showemployee(); // this show logo of our company
                    cout << endl
                         << endl;
                    markBlue();
                    cout << " Employee # " << i + 1 << "!" << endl;
                    resetColor();
                    ofstream file;
                    file.open("temp.txt", ios::app);
                    if (file.fail())
                    {
                        markRed();
                        cout << "file not opened" << endl;
                        resetColor();
                    }
                    else
                        file << i + 1 << endl;

                    // Call the employee menu
                    display();
                    break;
                }
            }

            if (!logged)
            {
                markRed();
                cout << "Invalid username or password." << endl;
                cout << "Do you want to try again? Press 1 for yes and 0 for no: ";
                resetColor();
                markYellow();
                cin >> choice;
                resetColor();
            }
        } while (!logged && choice != 0);

        // Deallocate memory
        delete[] name;
        delete[] password;

        for (int i = 0; i < maximum; i++)
        {
            delete[] usernames[i];
            delete[] passwords[i];
        }
        delete[] usernames;
        delete[] passwords;
    }
}
// login ke bad ye display ha jo sara control kare ga code
void Employee ::display()
{
    do
    {
        markYellow();
        cout << "\t _____________________________________________________________\n";
        cout << "\t|                                                             |\n";
        cout << "\t|                 Employee Menu                               |\n";
        cout << "\t|_____________________________________________________________|\n";
        cout << "\t|                                                             |\n";
        cout << "\t| 1. Order                                                    |\n";
        cout << "\t| 2. Search items                                             |\n";
        cout << "\t| 3. View online orders                                       |\n";
        cout << "\t| 4. Bonus Salary                                             |\n";
        cout << "\t|_____________________________________________________________|\n";
        resetColor();
        markMagenta();
        cout << "\tEnter your choice number: ";

        cin >> employeeChoice;
        resetColor();

        switch (employeeChoice)
        {
        case 1:

            snd->takeOrder();
            break;

        case 2:
            snd->search();
            break;

        case 3:
            viewAndRespondToOrders();
            break;
        case 4:
           bonussalary();
         break;
        default:
            markRed();
            cout << "invalid input" << endl;
            cout << "do you want to exit employee portal" << endl;
            resetColor();
            markCyan();
            cout << "press 1 for re-enter and 0 for exit" << endl;
            cin >> choice;
            resetColor();
            break;
            if (choice == 0)
            {
                exit(-1);
            }
        }
    } while (choice != 0);
}

Employee::~Employee()
{
    delete snd;
    delete[] name;
    delete[] password;
}

 void Employee::bonussalary(){

    // idar just file read karni ha bas 
     ifstream file;
     file.open("bestseller.txt");
    if (file.fail())
    {
       cout << "error in file openeing"<<endl;
    }
     else 
     {
        markCyan();
         char input[200];
        while (file.getline(input,200))
        {
            cout <<input <<endl;
        }
        
     }
     resetColor();
    file.close();
    //  ab ise sath trucn be kardo
     // Truncate the file
    fstream file2;
    file2.open("bestseller.txt", ios::out | ios::trunc);
    if (file2.fail()) {
        cout << "Error truncating file" << endl;
    }
    file2.close();
}