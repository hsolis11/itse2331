#ifndef DATABASE_H
#define DATABASE_H

#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include "data.h"
using namespace std;

class Database{

public:
    Database();
    ~Database();

//    bool addProduct();
//    bool addOrders();

    bool setFile(string); // set the file to be read CustomerMaster.txt
    bool processFile(); // read the file and extract all the data
    void printData();

    // Reporting capabilities
//    void listCities(); // List of cities in CustomerMaster.txt
//    void listStates(); // List of states in CustomerMaster.txt
    void customersInCities(string); // All customer records in a city
//    void customersInStates(string); // All cusomer records in a state
//    void ordersByCustomerID(string); // All orders associated with a customer by CustomerID
//    void ordersByCustomerZip(string); // All orders associated with a customer by ZipCode



private:
    string file_name;
    vector<vector <string>> customers;


};


#endif
