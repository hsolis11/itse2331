#ifndef ORDER_H
#define ORDER_H

#include <string>
#include <vector>
#include <stdlib.h> // srand, rand
#include <time.h> // time
#include <ctime>

using std::string;
using std::vector;
using std::time_t;


class Order {

    public:
        Order();
        ~Order();

        void setCustID();
        void setProductNums();

        int getOrderNum();
        int getCustID();
        string getOrderCreationTime();
        int getOrderCount();
        

        


    private:
        int orderNum;
        int custID;
        vector<int> productNums;
        string orderCreationTime;
        static int orderCount;



};



#endif