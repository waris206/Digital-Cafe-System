#include "adminotherdealing.h"
#include "complaint.h"
#include "color.h"
void adminotherdealing::seecomplaint()
{
    // complaint ko dekhne ka function ha
    ifstream file("complaint.dat", ios::binary);
    if (!file)
    {
        markRed();
        cout << "File not found" << endl;
        resetColor();
        return;
    }

    const int max_size = 100;
    char *complaint = new char[max_size];
    // while loop s idar file ko get kar rahe
    while (file.getline(complaint, max_size))
    {
        markYellow();
        cout << "Complaint: " << complaint << endl;
        resetColor();
    }
    file.close();

    ofstream truncation("complaint.dat", ios::out | ios::trunc);
    truncation.close();
}

void adminotherdealing::writenotification()
{
    const int max_size = 100;
    char notification[max_size];
    // idar admin notifcation likh sakte hain
    markCyan();
    cout << "Enter your notification (deals): ";
    resetColor();
    cin.ignore();
    cin.getline(notification, max_size);
    // binary file ko binary mode me open karna parta ha
    ofstream file("notification.dat", ios::binary);
    if (!file)
    {
        markRed();
        cout << "Error: Unable to open file" << endl;
        resetColor();
        return;
    }

    file << notification << endl;
    file.write(notification, strlen(notification));
    file.close();
}
// ye function file se sab employee ko read kar rha ha bas
void adminotherdealing::reademployees()
{
    ifstream file("employeecredential.txt");
    max_employees = 5;
    name = new char *[max_employees];
    password = new char *[max_employees];

    for (int i = 0; i < max_employees; i++)
    {
        name[i] = new char[20];
        password[i] = new char[20];
    }

    int i = 0;
    if (file.fail())
    {
        markRed();
        cout << "Error: Unable to open file" << endl;
        resetColor();
        return;
    }
    else
    {
        while (i < max_employees && file.getline(name[i], 20, '$') && file.getline(password[i], 20))
        {
            i++;
        }
        file.close();
        displayemployees();
    }
}
// read ke bad ine display ye wala function kar rha ha
void adminotherdealing::displayemployees()
{
    markCyan();
    cout << "\t \tEmployee List:\n";
    cout << "----------------------------------\n";
    cout << "Name\tPassword\n";
    cout << "----------------------------------\n";
    resetColor();

    for (int i = 0; i < max_employees; ++i)
    {
        if (name[i][0] != '\0')
        {
            cout << name[i] << "\t" << password[i] << "\n";
        }
    }

    markCyan();
    int option;
    do
    {
        cout << "\t ___________________________________________\n";
        cout << "\t|                                           |\n";
        cout << "\t| do you want to add or remove employees?   |\n";
        cout << "\t|                                           |\n";
        cout << "\t|___________________________________________|\n";
        cout << "\t|                                           |\n";
        cout << "\t| Press 1 to add employees.                 |\n";
        cout << "\t| Press 2 to delete employee credentials.   |\n";
        cout << "\t| Press 0 to exit.                          |\n";
        cout << "\t|___________________________________________|\n";
        cout << "\tEnter your choice: ";
        resetColor();
        cin >> option;

        switch (option)
        {
        case 1:
            addemployees();
            break;
        case 2:
            removeemployees();
            break;
        case 0:
            markRed();
            cout << "Exiting manage employees." << endl;
            resetColor();
            return;
            break;
        default:
            markRed();
            cout << "Invalid option. Please enter again." << endl;
            resetColor();
            break;
        }
    } while (option != 0);
}
// agar admin ko koi employee add karna hato ye fucntion ha..jo file me dekhta ha ke kidar
// name ki plac empty ha idar iss position par add karta ha
void adminotherdealing::addemployees()
{
    int index = -1;
    for (int i = 0; i < max_employees; ++i)
    {
        if (name[i][0] == '\0')
        {
            index = i;
            break;
        }
    }

    if (index != -1)
    {
        markCyan();
        cout << "Enter the name of the new employee: ";
        resetColor();
        cin.ignore();
        cin.getline(name[index], 20);

        markGreen();
        cout << "Enter the password: ";
        resetColor();

        cin.getline(password[index], 20);

        ofstream write("employeecredential.txt", ios::app);
        if (write.fail())
        {
            markRed();
            cout << "file not found" << endl;
            resetColor();
        }
        else
        {
            write << name[index] << "$" << password[index] << endl;
            write.close();
        }
    }
    else
    {
        markRed();
        cout << "Employee list is full. Cannot add more employees.\n";
        resetColor();
    }
}
// ye function ha ke agar admin ko remove karna ha employee ar iss ke bad emppty kar rha iss ka name ko idar se
void adminotherdealing::removeemployees()
{
    char *naam = new char[50];
    markBlue();
    cout << "Enter the name of employee you want to remove: ";
    resetColor();
    cin.ignore();
    cin.getline(naam, 50);

    bool found = false;
    for (int i = 0; i < max_employees; ++i)
    {
        if (strcmp(name[i], naam) == 0)
        {
            name[i][0] = '\0';
            markGreen();
            cout << "Employee removed successfully!\n";
            resetColor();
            found = true;
            break;
        }
    }
    // ye simple condtion ha direct boolean value ko put kar ke check karlo
    if (!found)
    {
        markRed();
        cout << "Employee not found.\n";
        resetColor();
        return;
    }

    ofstream file("employeecredential.txt");
    if (file.fail())
    {
        markRed();
        cout << "file is not opened" << endl;
        resetColor();
    }
    else
    {
        for (int j = 0; j < max_employees; ++j)
        {
            if (name[j][0] != '\0')
            {
                file << name[j] << "$" << password[j] << "\n";
            }
        }
        file.close();
    }
}
// this is logic jidar me best seller find kar rha
// meri logic ye hake .har dafa jab be login ho raha employee side s me ise aik file
// me store kara rha ar time par read kar ke dekh raha ke kis ne order zaida lia
// ar ise iss tarah best seller declare kar rha
void adminotherdealing::bestseller()
{
    ifstream file;
    int *loginCount;
    max_employees = 5;
    markBlue();
    file.open("temp.txt", ios::in);
    resetColor();
    if (file.fail())
    {
        markRed();
        cout << "file is not opened" << endl;
        resetColor();
    }
    else
    {
        markGreen();
        loginCount = new int[max_employees];
        for (int i = 0; i < max_employees; i++)
        {
            loginCount[i] = 0;
        }
        resetColor();
        int employeeNumber = 0;
        while (file >> employeeNumber)
        {
            if (employeeNumber >= 1 && employeeNumber <= max_employees)
            {
                loginCount[employeeNumber - 1]++;
            }
        }

        file.close();
        markBlue();
        int bestSeller = -1;
        int maxCount = 0;
        for (int i = 0; i < max_employees; ++i)
        {
            if (loginCount[i] > maxCount)
            {
                maxCount = loginCount[i];
                bestSeller = i + 1;
            }
        }
        resetColor();
        if (bestSeller != -1)
        {
            markGreen();
            cout << "Best Seller: Employee " << bestSeller << " (Login Count: " << maxCount << ")" << endl;
            resetColor();
        }
        else
        {
            markRed();
            cout << "No login activity found." << endl;
            resetColor();
        }
    }
    delete[] loginCount;
}
// distructor jidar sab deelte kar rha
adminotherdealing::~adminotherdealing()
{
    delete[] complaint1;
    for (int i = 0; i < max_size; i++)
    {
        delete[] name[i];
        delete[] password[i];
    }
    delete[] name;
    delete[] password;
}
// setters dunction hain
void adminotherdealing::setName(int index, const char *newName)
{
    strcpy(name[index], newName);
}

void adminotherdealing::setPassword(int index, const char *newPassword)
{
    strcpy(password[index], newPassword);
}
// getter fucntion hain

const char *adminotherdealing::getComplaint() const
{
    return complaint1;
}

const char *adminotherdealing::getName(int index) const
{
    return name[index];
}

const char *adminotherdealing::getPassword(int index) const
{
    return password[index];
}
// kuch operator overloading ki ha idar
bool adminotherdealing::operator==(const adminotherdealing &other) const
{
    if (strcmp(complaint1, other.complaint1) != 0)
    {
        return false;
    }
    return true;
}

void adminotherdealing::setComplaint(const char *newComplaint)
{
    strcpy(complaint1, newComplaint);
}

bool adminotherdealing::operator!()
{
    if (strcmp(complaint1, "") == 0)
    {
        return true;
    }
    return false;
}
// ye function extra ha for bonus
// is me student ke pas power ha wo online table be reserve kara sakta
// is me proper communation system ha between admin and srudent
void adminotherdealing::confirmreservation()
{
    ifstream file;
    int tableNumber = 0;
    file.open("reservation.dat", ios::binary);

    if (file.fail())
    {
        markRed();
        cout << "Error in file opening" << endl;
        resetColor();
        return; // Exit function if file opening fails
    }

    // Read table numbers until the end of the file
    while (file.read(reinterpret_cast<char *>(&tableNumber), sizeof(int)))
    {
        markCyan();
        cout << "Reserved Table Number: " << tableNumber << endl;
        resetColor();
    }

    char confirm;
    char aa[] = "your reservation is done ";
    char bb[] = "your reservation is canceled";
    markGreen();
    cout << "Do you want to confirm the reservation? (y/n)" << endl;
    resetColor();
    markMagenta();
    cin >> confirm;
    resetColor();
    if (confirm == 'y' || confirm == 'Y')
    {
        ofstream file;
        file.open("notification.dat");

        if (file.fail())
        {
            markRed();
            cout << "Error in file opening" << endl;
            resetColor();
            return; // Exit function if file opening fails
        }

        file.write(reinterpret_cast<char *>(&aa), sizeof(aa));
        file.close();

        // Delete the reservation
        ofstream file1("reservation.dat", ios::trunc);
        file1.close();
    }
    else
    {
        ofstream file1;
        file1.open("notification.dat");

        if (file1.fail())
        {
            markRed();
            cout << "Error in file opening" << endl;
            resetColor();
            return; // Exit function if file opening fails
        }

        file1.write(reinterpret_cast<char *>(&bb), sizeof(bb));
        file1.close();

        // Clear the reservation file
        ofstream file2("reservation.dat", ios::trunc);
        file2.close();
    }

    file.close();
}

void adminotherdealing::tipemployee()
{
    // give best employee all tups okay

    fstream file;
    int inputs;
    int total = 0;

    file.open("tip.txt");
    if (file.fail())
    {
        markRed();
        cout << "error in file openeing " << endl;
        resetColor();
    }

    // Loop until end-of-file is reached
    while (file >> inputs)
    {
        total += inputs;
    }

    if (file.eof())
    {
        markGreen();
        cout << "Total tips: " << total << endl;
        resetColor();
    }
    else
    {
        markRed();
        cout << "Error: Failed to read tip file." << endl;
        resetColor();
    }
    file.close();
    bestseller();
    fstream file1("bestseller.txt", ios::app);
    if (file1.fail())
    {
        markRed();
        cout << "error in file openeing " << endl;
        resetColor();
    }
    else
    {
        // Write the congratulations note
        int number = 0;
        file1 << "Congratulations, ";
        file1 << "Employee ";
        markCyan();
        cout << "Employee number to give it bonus" << endl;
        resetColor();
        cin >> number;
        file1 << number;
        file1 << " Your hard work has paid off. ";
        file1 << "You've earned all the tips as a reward Rs. " << total << " in total. ";
        file1 << "Keep up the great work!" << endl;
    }
}
