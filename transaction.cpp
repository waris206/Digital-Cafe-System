#include"transaction.h"
#include"color.h"
 transaction :: transaction() {

   // here in initlize oll of them
    item= new char *[50];
    for (int i = 0; i < 50; i++)
    {
        item[i] = new char[15];
    }
    
    
    price = new double [40];

    total = new double [40];
    selected = 0;
    quantity=0;
    


 }
 // ye fucntion sirf bill generate karta ha bas 
  transaction::transaction(char **items, int selected, int quantity, double *price) {
    ofstream transactionFile("transactions.txt", ios::app);  

    if (!transactionFile.fail()) {
        transactionFile << "\t\tItem: " << items[selected] << "\n";
        transactionFile << "\t\tQuantity: " << quantity << "\n";
        transactionFile << "\t\tTotal Price: " << quantity * price[selected] << "\n\n";

        // Display the generated transaction on the console
        cout << "\t\t\033[48;5;196m****************************************************\033[0m\n";
         cout << "\t\t\033[48;5;30m**                 digital transaction bill          **\033[0m\n";
         cout << "\t\t\033[48;5;21m****************************************************\033[0m\n\n";

    	cout << "\t\tItem: \033[1;32m" << items[selected] << "\033[0m\n";
         cout << "\t\tQuantity: \033[1;34m" << quantity << "\033[0m\n";
         cout << "\t\tTotal Price: \033[1;33mR.S " << quantity * price[selected] << "\033[0m\n\n";

	cout << "\t\t\033[48;5;196m************ Thanks for Choosing us! ************\033[0m\n";
        cout << "\t\t\033[48;5;30m************ We Wish to See You Again! *********\033[0m\n\n";

        // Display some stars for khubsurti only
        for (int i = 0; i < 50; ++i) {
            cout << "*";
        }
        cout << endl;

        // Close the file
        transactionFile.close();
    } else {
        markRed();
        cout << "Error opening transactions file.\n";
        resetColor();
    }
}
// now define setters here
 
 void transaction::setItem(char **items) {
    item = items;
}

void transaction::setQuantity(int q) {
    quantity = q;
}

void transaction::setPrice(double *p) {
    price = p;
}

void transaction::setTotal(double *t) {
    total = t;
}

void transaction::setSelected(int s) {
    selected = s;
}

char ** transaction::getItem() {
    return item;
}

int transaction::getQuantity() {
    return quantity;
}

double * transaction::getPrice() {
    return price;
}

double * transaction::getTotal() {
    return total;
}

int transaction::getSelected() {
    return selected;
}

 transaction::~transaction(){
    delete [] item;
    delete [] price;
    delete [] total;
    
 }
