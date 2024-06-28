#include "stockhandlebyadmin.h"
#include "color.h"
#include <iostream>
#include <fstream>
#include <limits>
#include <cstdlib>
#include <ctime>
using namespace std;

StockHandleByAdmin::StockHandleByAdmin()
{
    markYellow();
    cout << "-----------------------------" << endl;
    cout << "|       STOCK MANAGEMENT     |" << endl;
    cout << "------------------------------" << endl;
    cout << "| 1. Add new item stock      |" << endl;
    cout << "| 2. Remove the stock        |" << endl;
    cout << "| 3. Update stock            |" << endl;
    cout << "| 4. Exit                    |" << endl;
    cout << "-----------------------------" << endl;
    resetColor();
    markGreen();
    cout << "Enter your choice: ";
    resetColor();
    do
    {
        cin >> input;
        switch (input)
        {
        case 1:

            addstock();
            break;
        case 2:
            removestock();
            break;
        case 3:
            orderItems();
            break;
        case 4:
            exit(-1);
            break;
        default:
            markRed();
            cout << "Sorry! Invalid input." << endl;
            cout << "Do you want to try again?" << endl;
            resetColor();
            markMagenta();
            cout << "Press 0 for exit or any other key to do any one of these functions: ";
            cin >> input;
            resetColor();
           

            break;
        }
    } while (true);
}
// stock me kuch add karne ke liye ye function ha
void StockHandleByAdmin::addstock()
{
    num_items = 10;
    fstream file;
    file.open("stock.txt", ios::app | ios ::in);
    int i = 0;
    if (file.fail())
    {
        markRed();
        cout << "file is not opened succesfuly" << endl;
        resetColor();
    }
    else
        while (i < num_items && file >> name[i])
        {
            file >> price[i];
            file >> quantity[i];
            file >> total[i];
            i++;
        }

    if (i == num_items)
    {
        markGreen();
        cout << "stock is full..can't add more items" << endl;
        resetColor();
        StockHandleByAdmin();
    }
    else
    {
        markBlue();
        cout << "enter the name of the item: ";
        cin.ignore();
        cin.getline(name[i], 100);
        resetColor();
        markCyan();
        cout << "enter the price of the item: ";
        cin >> price[i];
        resetColor();
        markGreen();
        cout << "enter the quantity of the item: ";
        cin >> quantity[i];
        resetColor();
        total[i] = price[i] * quantity[i];
        num_items++;
        file.close();
        markYellow();
        cout << "now add in file also" << endl;
        resetColor();
        ofstream file1;
        file1.open("stock.txt", ios::app);
        file1 << name[i] << " " << quantity[i] << " " << price[i] << " " << total[i] << endl;
        file1.close();
        StockHandleByAdmin();
    }
}
// ar kuch remove karna ka fucntion ye ha
void StockHandleByAdmin::removestock()
{
    ifstream file("stock.txt");
    num_products = 10;
    if (file.fail())
    {
        markRed();
        cout << "Error opening stock file." << endl;
        resetColor();
        exit(-1);
    }

    loadstock_from_file();

    char itemName[100];
    markYellow();
    cout << "Enter the name of the item to be removed: ";
    cin.ignore(); // Ignore the newline character
    cin.getline(itemName, 100);
    resetColor();
    int index = -1;
    for (int i = 0; i < num_products; ++i)
    {
        if (strcmp(name[i], itemName) == 0)
        {
            index = i;
            break;
        }
    }

    if (index != -1 && name[index][0] != '\0')
    {
        // Mark the slot as empty
        name[index][0] = '\0';
        quantity[index] = 0;
        price[index] = 0.0;
        total[index] = 0.0;
        markRed();
        cout << "Item removed successfully!" << endl;
        resetColor();
        // Save the changes to the file
        ofstream outfile("stock.txt");
        if (outfile.fail())
        {
            markRed();
            cout << "Error opening stock file." << endl;
            resetColor();
            exit(-1);
        }
        for (int i = 0; i < num_products; ++i)
        {
            if (name[i][0] != '\0')
            {
                outfile << name[i] << " " << quantity[i] << " " << price[i] << " " << total[i] << endl;
            }
        }
        outfile.close();
        StockHandleByAdmin();
    }
    else
    {
        markRed();
        cout << "Item not found." << endl;
        resetColor();
    }
}
// getter fucntion hain kuch
int StockHandleByAdmin ::getNumItems()
{
    return num_items;
}
// operator overloading...
ostream &operator<<(ostream &abc, const StockHandleByAdmin &stock)
{
    for (int i = 0; i < stock.num_items; ++i)
    {
        markYellow();
        abc << "Item " << i + 1 << ": " << stock.name[i] << ", Quantity: " << stock.quantity[i] << ", Price: " << stock.price[i] << ", Total: " << stock.total[i] << endl;
        resetColor();
    }
    return abc;
}
double StockHandleByAdmin::operator[](int index)
{
    if (index > 0)
    {
        return total[index];
    }
    else
        markRed();
    cout << "invalid input man !" << endl;
    resetColor();
    return 1.0;
}
bool StockHandleByAdmin::operator!()
{
    if (num_items == 0)
    {
        return true;
    }
    else
    {
        return false;
    }
}
// iss function se wo stock ke liye new items order kar rha ha
void StockHandleByAdmin::orderItems()
{
    // Open the file to read the stock data
    ifstream file("stock.txt");
    if (file.fail())
    {
        markRed();
        cout << "Failed to open stock file." << endl;
        resetColor();
        return;
    }

    // Arrays to store stock data
    const int max_products = 10; // Assuming a maximum of 10 products

    // Read stock data from the file
    int num_products = 0;
    while (num_products < max_products && file >> name[num_products] >> quantity[num_products] >> price[num_products] >> total[num_products])
    {
        num_products++;
    }
    file.close();

    srand(time(nullptr)); // Seed the random number generator

    while (true)
    {
        // Randomly decrease the stock quantities
        for (int i = 0; i < num_products; ++i)
        {
            int decrease = rand() % 15 + 1; // Random decrease in the range [1, 15]
            quantity[i] -= decrease;

            // Ensure quantity doesn't go below 0
            if (quantity[i] < 0)
            {
                quantity[i] = 0;
            }
        }

        // Display stock with color coding
        markGreen();
        cout << "Stock Details:" << endl;
        resetColor();
        markCyan();
        cout << "--------------------------------------------------------------------------------" << endl;
        resetColor();
        markBlue();
        cout << "Name\t\tQuantity\tPrice\t\tTotal Price" << endl;
        resetColor();
        markCyan();
        cout << "--------------------------------------------------------------------------------" << endl;
        resetColor();

        for (int i = 0; i < num_products; ++i)
        {
            // Color coding based on quantity
            if (quantity[i] <= 0)
            {
                cout << "\033[1;33m"; // Yellow
            }
            else if (quantity[i] <= 15)
            {
                cout << "\033[1;31m"; // Red
            }

            // Print stock details
            cout << name[i] << "\t\t" << quantity[i] << "\t\t" << price[i] << "\t\t" << total[i] << endl;

            // Reset color
            cout << "\033[0m";
        }

        cout << "--------------------------------------------------------------------------------" << endl;

        // Ask whether to increase quantity or not
        char choice;
        markMagenta();
        cout << "Do you want to increase the quantity of any item? (y/n): ";
        resetColor();
        cin >> choice;

        if (choice == 'n' || choice == 'N')
        {
            StockHandleByAdmin(); // Exit the loop if admin doesn't want to increase quantity
        }
        else if (choice != 'y' && choice != 'Y')
        {
            markRed();
            cout << "Invalid choice. Please enter 'y' or 'n'." << endl;
            resetColor();
            continue; // Ask again if input is invalid
        }
        markGreen();
        cout << "How many items do you want to buy? ";
        int numItems;
        cin >> numItems;
        resetColor();

        for (int i = 0; i < numItems; ++i)
        {
            markBlue();
            cout << "Enter the name of item " << i + 1 << ": ";
            string itemName;
            cin >> itemName;
            resetColor();
            // Find the index of the item
            int index = -1;
            for (int j = 0; j < num_products; ++j)
            {
                if (name[j] == itemName)
                {
                    index = j;
                    break;
                }
            }

            if (index != -1)
            {
                // Order quantity
                int orderQuantity;
                markYellow();
                cout << "Enter the quantity to order for " << itemName << ": ";
                cin >> orderQuantity;
                resetColor();
                // Update stock quantity
                quantity[index] += orderQuantity;
                markCyan();
                cout << "Order placed successfully for " << itemName << ". New quantity: " << quantity[index] << endl;
                resetColor();
                updatestock();
            }
            else
            {
                markRed();
                cout << "Item not found in stock: " << itemName << ". Order failed." << endl;
                resetColor();
            }
        }
    }

    // Save updated stock to file
    ofstream outfile("stock.txt");
    if (!outfile.is_open())
    {
        markRed();
        cout << "Failed to open stock file for writing." << endl;
        resetColor();
    }

    for (int i = 0; i < num_products; ++i)
    {
        outfile << name[i] << " " << quantity[i] << " " << price[i] << " " << total[i] << endl;
    }
    outfile.close();
}
