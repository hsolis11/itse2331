#include "order.h"



Order::Order(){

    orderCount++;
}

Order::~Order(){

    orderCount--;
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