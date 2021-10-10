#ifndef CUSTOMER_H
#define CUSTOMER_H

#include <string>
#include <iostream>
#include <vector>
#include <stdlib.h> // srand, rand
#include <time.h> // time
#include <ctime>

using std::string;
using std::vector;
using std::time_t;
using std::cout;
using std::endl;


class Customer {

    public:
        
        Customer(string);
        ~Customer();

        // setters
        bool setName(string);
        bool setAddress(string);
        bool setOrderNums(); // class template vector

        // getters
        int getCustID();
        string getName();
        string getAddress();
        string getCustomerCreationTime();
        void getOrderNums();
        int getCustomerCount();
        void outputReport();


    private:
        void setCustID();
        void setCustomerCreationTime();

        int custID;
        string name;
        string address;
        vector<int> orderNums;
        char* customerCreationTime;
        static int customerCount;



};



#endif