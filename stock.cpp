#include "stock.h"
#include "color.h"
int num_products = 10;
// sab se imp class ha ye
// constructor ke andar sab ko initlize kar rhae
stock::stock()
{

    name = new char *[num_products];
    quantity = new int[num_products];
    price = new double[num_products];
    total = new double[num_products];

    // Initialize each name pointer to nullptr
    for (int i = 0; i < num_products; ++i)
    {
        name[i] = new char[100];
    }
}
// ye fucntion ha jo stock ko read kare ga file se mtlb
void stock::loadstock_from_file()
{
    ifstream infile;
    infile.open("stock.txt", ios::in);
    if (infile.fail())
    {
        markRed();
        cerr << "File not found!" << endl;
        resetColor();
        return;
    }
    else
    {

        int i = 0;
        while (i < num_products && infile >> name[i])
        {
            infile >> quantity[i] >> price[i] >> total[i];
            ++i;
        }

        // Update num_products based on the actual number of items read
        num_items = i;
        infile.close();

        sortstock(); // ye function sab stock ko sort kardega
    }
}

// ye fucntion sare stock ko display karta ha
void stock::displaystock()
{
    markGreen();
    cout << "Stock Details:" << endl;
    resetColor();
    markRed();
    cout << "--------------------------------------------------------------------------------" << endl;
    resetColor();
    markYellow();
    cout << "Name\t\tQuantity\tPrice\t\tTotal Price" << endl;
    resetColor();
    markRed();
    cout << "--------------------------------------------------------------------------------" << endl;
    resetColor();
    for (int i = 0; i < num_products; ++i)
    {
        cout << name[i] << "\t\t" << quantity[i] << "\t\t" << price[i] << "\t\t" << total[i] << endl;
    }
    markRed();
    cout << "--------------------------------------------------------------------------------" << endl;
    resetColor();
}
// ye quantity ki basis par sare stock ko sort karta ha
void stock::sortstock()
{
    for (int i = 0; i < num_items - 1; ++i)
    {
        for (int j = 0; j < num_items - i - 1; ++j)
        {
            if (quantity[j] > quantity[j + 1])
            {
                // Swap name
                markGreen();
                char *tempName = name[j];
                name[j] = name[j + 1];
                name[j + 1] = tempName;
                resetColor();
                // Swap quantity
                markBlue();
                int tempQuantity = quantity[j];
                quantity[j] = quantity[j + 1];
                quantity[j + 1] = tempQuantity;
                resetColor();
                // Swap price
                double tempPrice = price[j];
                price[j] = price[j + 1];
                price[j + 1] = tempPrice;

                // Swap total
                double tempTotal = total[j];
                total[j] = total[j + 1];
                total[j + 1] = tempTotal;
            }
        }
    }
    updatestock();
}
// define update stock so
// ye fucntion ab write karta sort ke bad
void stock::updatestock()
{
    ofstream outfile;
    outfile.open("stock.txt");

    for (int i = 0; i < num_products; ++i)
    {
        outfile << name[i] << " " << quantity[i] << " " << price[i] << " " << total[i] << endl;
    }

    outfile.close();
    displaystock();
}
stock ::~stock()
{
    for (int i = 0; i < num_products; ++i)
    {
        delete[] name[i];
    }
    delete[] price;
    delete[] quantity;

    delete[] total;
}
// getter fucntion hain kuch
const char *stock::getName(int index)
{
    // Get name of item at index
    return name[index];
}

int stock::getQuantity(int index)
{
    // Get quantity of item at index
    return quantity[index];
}

double stock::getPrice(int index)
{
    // Get price of item at index
    return price[index];
}

double stock::getTotal(int index)
{
    // Get total price of item at index
    return total[index];
}
// setter fucntion hain kuch
void stock::setName(int index, const char *itemName)
{
    // Set name of item at index
    strcpy(name[index], itemName);
}

void stock::setQuantity(int index, int itemQuantity)
{
    // Set quantity of item at index
    quantity[index] = itemQuantity;
}

void stock::setPrice(int index, double itemPrice)
{
    // Set price of item at index
    price[index] = itemPrice;
}
// operator overloading be ha kuch
bool stock::operator!()
{
    if (num_items == 0)
    {
        return true;
    }
    else
        return false;
}

stock &stock::operator=(const stock &other)
{

    // Perform deep copy of member variables
    // First deallocate existing memory
    for (int i = 0; i < num_products; ++i)
    {
        delete[] name[i];
    }
    delete[] name;
    delete[] quantity;
    delete[] price;
    delete[] total;

    // Now allocate new memory and copy data
    num_items = other.num_items;
    name = new char *[num_items];
    quantity = new int[num_items];
    price = new double[num_items];
    total = new double[num_items];

    for (int i = 0; i < num_items; ++i)
    {
        name[i] = new char[strlen(other.name[i]) + 1];
        strcpy(name[i], other.name[i]);
        quantity[i] = other.quantity[i];
        price[i] = other.price[i];
        total[i] = other.total[i];
    }

    return *this;
}

stock::stock(const stock &other)
{
    num_items = other.num_items;
    name = new char *[num_products];
    quantity = new int[num_products];
    price = new double[num_products];
    total = new double[num_products];

    // Perform deep copy of data from other to this object
    for (int i = 0; i < num_items; ++i)
    {
        // Allocate memory for name and copy content
        name[i] = new char[strlen(other.name[i]) + 1];
        strcpy(name[i], other.name[i]);
        // Copy other member variables directly
        quantity[i] = other.quantity[i];
        price[i] = other.price[i];
        total[i] = other.total[i];
    }
}

stock &stock::operator++()
{
    for (int i = 0; i < num_items; ++i)
    {
        ++quantity[i];
        total[i] = quantity[i] * price[i];
    }
    return *this;
}

stock &stock::operator--()
{
    for (int i = 0; i < num_items; ++i)
    {
        --quantity[i];
        total[i] = quantity[i] * price[i];
    }
    return *this;
}

stock stock::operator+(const stock &other)
{
    stock result;

    for (int i = 0; i < num_items; ++i)
    {
        result.name[i] = name[i];
        result.quantity[i] = quantity[i] + other.quantity[i];
        result.price[i] = price[i];
        result.total[i] = result.quantity[i] * result.price[i];
    }

    return result;
}

stock stock::operator-(const stock &other)
{
    stock result;

    for (int i = 0; i < num_items; ++i)
    {
        result.name[i] = name[i];
        result.quantity[i] = quantity[i] - other.quantity[i];
        result.price[i] = price[i];
        result.total[i] = result.quantity[i] * result.price[i];
    }

    return result;
}

bool operator==(const stock &a, const stock &b)
{
    for (int i = 0; i < num_products; i++)
    {
        if (strcpy(a.name[i], b.name[i]) == 0 &&
            a.quantity[i] == b.quantity[i] &&
            a.price[i] == b.price[i] &&
            a.total[i] == b.total[i])

            return true;
        else
            return false;
    }
}

bool operator!=(const stock &a, const stock &b)
{
    for (int i = 0; i < num_products; i++)
    {
        if (strcpy(a.name[i], b.name[i]) == 0 &&
            a.quantity[i] == b.quantity[i] &&
            a.price[i] == b.price[i] &&
            a.total[i] == b.total[i])

            return false;
        else
            return true;
    }
}

double stock::operator[](int index)
{
    if (index > 0)
    {
        return total[index];
    }
    else
    {
        return 1.0;
    }
}
// ye sare sotkc ko read kar k stats find karte hain
void stock::stats()
{
    int check = 10;

    ifstream stockFile("stock.txt");
    if (stockFile.fail())
    {
        markRed();
        cout << "Error opening stock file.\n";
        resetColor();
        return; // or handle the error as needed
    }

    for (int i = 0; i < 10; ++i)
    {
        stockFile >> name[i] >> quantity[i] >> price[i] >> total[i];
    }

    // Calculate Statistics
    int totalQuantity = 0;
    double totalAmount = 0.0;

    for (int i = 0; i < check; ++i)
    {
        totalQuantity += quantity[i];
        totalAmount += total[i];
    }

    double averageQuantity = static_cast<double>(totalQuantity) / check;
    // used haere static commom waja ha ke quantiy to ab points me hone se rahi..to ise iss me lene ke liye use kia
    double averageAmount = static_cast<double>(totalAmount) / check;
    stockFile.close();

    // Print or display the statistics
    cout << "\033[1;36mTotal Quantity: \033[0m" << totalQuantity << endl;
    cout << "\033[1;36mTotal Amount: \033[0m" << totalAmount << endl;
    cout << "\033[1;36mAverage Quantity per Item: \033[0m" << averageQuantity << endl;
    cout << "\033[1;36mAverage Amount per Item: \033[0m" << averageAmount << endl;
}
