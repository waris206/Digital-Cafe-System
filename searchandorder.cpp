#include "searchandorder.h"
#include "color.h"
// ye search ka fucntion ha jo stock se read kar ke search kare ga
void StockandDisplay::search()
{
    loadstock_from_file(); // ye function doosri class ka read karne ke liye stock
    max = 30;
    markGreen();
    cout << "searching for an item in the stock" << endl;
    resetColor();
    item_name = new char[max];
    markMagenta();
    cout << "enter an item name" << endl;
    cin.ignore();
    cin.getline(item_name, max);
     
    resetColor();
    int index = -1;
    for (int i = 0; i < 10; i++)
    {
        if (strcmp(item_name, name[i]) == 0) // ye bohot basic condtion ha name match karne ke liye
        {
            index = i;

            break;
        }
    }

    if (index != -1)
    {
        markYellow();
        cout << "item is found successfully !!" << endl;
        resetColor();
    }
    else
    {
        markRed();
        cout << "Item not found." << endl;
        resetColor();
    }
}
// ye function ha .. jo student se pooch kar order ko done karwa dega
void StockandDisplay::takeOrder()
{
    loadstock_from_file();
    totalBill = 0;
    // here we will take order from user okay...
    itemName = new char[20];

    do
    {
        
        markCyan();
        cout << "Enter the name of the item you want to order: ";
    
        cin.getline(itemName, 20);
         
        
        resetColor();
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
            markBlue();
            
            cout << "Enter the quantity you want to order: ";
            cin >> quantities;
            resetColor();
            if (quantities <= quantity[index])
            {
                quantity[index] -= quantities;
                selectedItem = index;
                trans = new transaction(name, selectedItem, quantities, price);

                // here i just compose this class compeltely

                // Update the total bill
                totalBill += quantities * price[index];

                // Save the changes to the file
                updatestock();
                // Ask if the user wants to order more
                char orderMore;
                markYellow();
                cout << "Do you want to order more (y/n)? ";
                cin >> orderMore;
                resetColor();
                if (orderMore != 'y' && orderMore != 'Y')
                {
                    break;
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
            cout << "Item not found.\n";
            
            resetColor();
            continue;
        }
    } while (true);

    // Display the final bill
    markYellow();
    cout << "\t\t\t\t\n+-----------------------+\n";
    cout << "\t\t|      Final Bill           |\n";
    cout << "\t\t+-----------------------    +\n";
    cout << "\t\t     Amount : " << totalBill << endl;
    cout << "\t\t+---------------------------+\n";
    cout << "\t\t|   Thanks for ordering!    |\n";
    cout << "\t\t+---------------------------+\n";
    resetColor();
}
// distrcutor h jo sab char* ko delete kar rhai..
StockandDisplay ::~StockandDisplay()
{
    delete[] name;
    delete[] price;
    delete[] quantity;
    delete[] trans;
}
// setter fucntion hain ye

void StockandDisplay::setItemName(const char *itemName)
{
    // Allocate memory for item_name
    item_name = new char[max];
    // Copy the itemName to item_name
    strcpy(item_name, itemName);
}

// Getter function for item_name
const char *StockandDisplay::getItemName() const
{
    return item_name;
}

// Overloading the assignment operator
StockandDisplay &StockandDisplay::operator=(const StockandDisplay &other)
{

    // Delete existing data
    delete[] item_name;
    // Allocate memory for item_name
    item_name = new char[strlen(other.item_name) + 1];
    // Copy the data from other to this
    strcpy(item_name, other.item_name);

    return *this;
}

// Overloading the equality operator
bool StockandDisplay::operator==(const StockandDisplay &other) const
{
    // Compare the item_name strings
    return (strcmp(item_name, other.item_name) == 0);
}

// Overloading the inequality operator
bool StockandDisplay::operator!=(const StockandDisplay &other) const
{
    // Utilize the equality operator
    return (strcmp(item_name, other.item_name) != 0);
}

// Overloading the subscript operator
char StockandDisplay::operator[](int index) const
{
    // Check if the index is valid
    if (index > 0)
    {
        // Return the character at the specified index
        return item_name[index];
    }
    else
    {
        // If the index is out of bounds, return null character
        return '\0';
    }
}
bool StockandDisplay::operator!()
{
    if (item_name == NULL)
    {
        return true;
    }
    else
        return false;
}
ostream &operator<<(std::ostream &abc, const StockandDisplay &obj)
{
    markYellow();
    abc << "Item Name: " << obj.itemName << endl;
    abc << "Selected Item: " << obj.selectedItem << endl;
    abc << "Quantities: " << obj.quantities << endl;
    abc << "Total Bill: " << obj.totalBill << endl;
    resetColor();
    // You can add more information if needed

    return abc;
}