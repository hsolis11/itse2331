#include "order.h"



Order::Order(int customerID){
    custID = customerID;
    setOrderNum();
    setOrderCreationTime();
    orderCount++;
}

Order::~Order(){
}

void Order::outputReport() {
    cout << "Order ID: " << getOrderNum()
        << "\nCustomer ID: " << getCustID()
        << "\nCreated at: " << getOrderCreationTime();
    for(auto it = productNums.begin(); it != productNums.end(); ++it){
        cout << "\tProduct ID: " << *it << endl;
    }
    cout << endl;
}

int Order::getOrderNum(){
    return orderNum;
}

int Order::getCustID(){
    return custID;
}

string Order::getOrderCreationTime(){
    return orderCreationTime;
}

int Order::getOrderCount(){
    return orderCount;
}


void Order::setOrderNum(){
    orderNum = rand() % 100000;
}

void Order::setOrderCreationTime(){
    time_t curr_time;
    curr_time = time(NULL);

    orderCreationTime = ctime(&curr_time);

}

void Order::addProduct(int product_id) {
    productNums.push_back(product_id);
}