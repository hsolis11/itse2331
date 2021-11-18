#include "main.h"

int main(){

    // TODO customer data
    //  CustotmerID, FirstName, LastName, StreetAddress, City, State, ZipCode.
    //  All fields are separated by percent signs.

    // TODO create the following files
    // Products.txt with the following fields: ProductID, Description, Price
    // Orders.txt with the following format: OrderID, CustomerID, ProductID, Quantity, OrderTotal

    // TODO enable the user to perform these minimum iterated operations:
    // 1. Add products to the Products.txt file and populate all fields
    // 2. Add orders to the Orders.txt file and populate all fields
    // After each selection, ask your user if s/he has another request to process.

    /*
     * TODO provide the following minimum reporting capabilities as iterated choices:
     * 1. List of cities in CustomerMaster.txt
     * 2. List of states in CustomerMaster.txt
     * 3. All customer records in a city
     * 4. All cusomer records in a state
     * 5. All orders associated with a customer by CustomerID
     * 6. All orders associated with a customer by ZipCode
     * After each selection, ask your user if s/he has another request to process.
     * */

    Database database;

    database.setFile("CustomerMaster.txt");
    database.processFile();
    database.printData();
    cout << endl;
    cout << endl;
    // database.customersInCities("Chase");

    return 0;
}