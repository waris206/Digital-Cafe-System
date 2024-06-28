
#include "base.h"
#include "onlineorder.h"
#include "color.h"
onlineOrder::onlineOrder()
{
    viewAndRespondToOrders();
}
// ye function ha jis se admin ya employee online -order ko process kr rha ha
void onlineOrder::viewAndRespondToOrders()
{
    markGreen();
    cout << "view and respond to orders" << endl;
    resetColor();
    ifstream ordersFile("orders.txt");
    if (ordersFile.fail())
    {
        markRed();
        cout << "Error opening orders file.\n";
        resetColor();
        return;
    }
    // iss liye kia ha iss ke bina sahi se work nahi kar rha tha..ig cursor last me point kar rah tha
    // is seekg se wo start par point kare ga ab
    ordersFile.seekg(0, ios::beg);

    itemName = new char[30];
    scheduledTime = new char[30];
    while (ordersFile >> itemName >> quantities >> scheduledTime)
    {
        markCyan();

        cout << "Order: " << itemName << " - Quantity: " << quantities << " - Scheduled Time: " << scheduledTime << "\n";
        resetColor();
        markBlue();
        cout << "Proceed with processing this order? (y/n): ";
        resetColor();
        char confirmation;
        markYellow();
        cin >> confirmation;
        resetColor();
        if (confirmation == 'y')
        {
            // respondToOrder(itemName, quantities, scheduledTime);
        }
        else
        {
            ofstream file;
            file.open("notification.dat", ios::app);
            if (file.fail())
            {
                markRed();
                cout << "error in file" << endl;
                resetColor();
            }
            else
            {
                char a[] = "your order can't be proceed";
                file << endl;
                file.write(a, strlen(a));
                file.close();
            }
        }

        ordersFile.close(); // Close the file

        // Truncate the orders file after processing all orders
        ofstream truncateFile("orders.txt", ios::trunc);
        truncateFile.close();
    }
}

 

 
// distructor h ye
onlineOrder::~onlineOrder()
{
    delete[] itemName;
    delete[] scheduledTime;
    itemName = nullptr;
    scheduledTime = nullptr;
}
// Setter methods hain
void onlineOrder::setItemName(const char *itemName)
{
    this->itemName = new char[strlen(itemName) + 1];
    strcpy(this->itemName, itemName);
}

void onlineOrder::setQuantities(int quantities)
{
    this->quantities = quantities;
}

void onlineOrder::setScheduledTime(const char *scheduledTime)
{
    this->scheduledTime = new char[strlen(scheduledTime) + 1];
    strcpy(this->scheduledTime, scheduledTime);
}

// Getter methods implementation ha idar
const char *onlineOrder::getItemName() const
{
    return itemName;
}

int onlineOrder::getQuantities() const
{
    return quantities;
}

const char *onlineOrder::getScheduledTime() const
{
    return scheduledTime;
}

// Overloaded insertion operator implementation
ostream &operator<<(ostream &os, const onlineOrder &order)
{
    markBlue();
    os << "Item Name: " << order.getItemName() << ", Quantities: " << order.getQuantities() << ", Scheduled Time: " << order.getScheduledTime();
    resetColor();
    return os;
}
// operator overloading k kuch function hain
bool onlineOrder ::operator!()
{
    if (quantities > 0)
    {
        return true;
    }
    else
    {
        return false;
    }
}

bool onlineOrder::operator==(const onlineOrder &obj)
{

    return (strcmp(itemName, obj.itemName) == 0 &&
            quantities == obj.quantities &&
            strcmp(scheduledTime, obj.scheduledTime) == 0);
}
bool onlineOrder::operator!=(const onlineOrder &obj)
{

    return (strcmp(itemName, obj.itemName) != 0 &&
            quantities != obj.quantities &&
            strcmp(scheduledTime, obj.scheduledTime) != 0);
}