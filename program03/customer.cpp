
#include "customer.h"

Customer::Customer(string name){
    srand (time(NULL));
    setName(name);
    setCustID();
    setCustomerCreationTime();
    customerCount++;
}

Customer::~Customer(){
    customerCount--;
}

void Customer::outputReport(){
    
    cout << "Customer Name: " << getName() << endl;
    cout << "Customer ID: " << getCustID() << endl;
    cout << "created at: " << getCustomerCreationTime();            
    cout << "Customer Address: " << getAddress() << endl;
    cout << "Order Numbers: ";
    if(orderNums.size() > 0){
        cout << endl;
        for (int i = 0; i < orderNums.size(); i++){
        cout << "\t- " << orderNums[i] << endl;
        }
    } else {
        cout << "None" << endl;
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

bool Customer::setOrderNums(){
    // (Class Template vector)?? holds the values in the vector?
    return false;
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

void Customer::getOrderNums(){

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
    time_t curr_time;
    curr_time = time(NULL);

    customerCreationTime = ctime(&curr_time);
    
}