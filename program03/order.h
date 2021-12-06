#ifndef ORDER_H
#define ORDER_H

#include <string>
#include <vector>
#include <stdlib.h> // srand, rand
#include <time.h> // time
#include <ctime>
#include <iostream>

using std::string;
using std::vector;
using std::time_t;
using std::cout;
using std::endl;


class Order {

    public:
        Order(int);
        ~Order();

        void outputReport();


        // Getters
        int getOrderNum();
        int getCustID();
        string getOrderCreationTime();
        static int getOrderCount();

        // Setters
        void setCustID();
        void addProduct(int);







private:
        void setOrderCreationTime();
        void setOrderNum();
        int orderNum;
        int custID;
        vector<int> productNums;
        string orderCreationTime;
        static int orderCount;
};



#endif