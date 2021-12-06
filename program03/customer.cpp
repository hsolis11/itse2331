
#include "customer.h"

Customer::Customer(string name){
    srand (time(NULL));
    setName(name);
    setCustID();
    setCustomerCreationTime();
    customerCount++;
}

Customer::~Customer(){

}

void Customer::outputReport(){
    
    cout << "Customer Name: " << getName() << endl;
    cout << "Customer ID: " << getCustID() << endl;
    cout << "created at: " << getCustomerCreationTime();            
    cout << "Customer Address: " << getAddress() << endl;
    cout << "Order Numbers:" << endl;
    for (auto it = orderNums.begin(); it != orderNums.end(); ++it){
        cout << "\tOrder ID: " << *it << endl;
    }
    
    cout << endl;
}

/****************************************
 * Setters
 * *************************************/

bool Customer::setName(string newName){
    name = newName;
    return true;
}

bool Customer::setAddress(string newAddress){
    address = newAddress;
    return true;
}

bool Customer::addOrder(int order_id){
    orderNums.push_back(order_id);
    return true;
}


/****************************************
 * Getters
 * *************************************/

int Customer::getCustID(){
    return custID;
}

string Customer::getName(){
    return name;
}

string Customer::getAddress(){
    return address;
}

string Customer::getCustomerCreationTime(){
    return customerCreationTime;
}


int Customer::getCustomerCount(){
    return customerCount;
}

/****************************************
 * Private
 * *************************************/

void Customer::setCustID(){
    custID = rand() % 100000;
}

void Customer::setCustomerCreationTime(){
    getTime(customerCreationTime);
}

void Customer::getTime(string &timestamp){
    time_t curr_time;
    curr_time = time(NULL);
    timestamp = ctime(&curr_time);
}