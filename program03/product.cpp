#include "product.h"

Product::Product(){
    setProductNum();
    setProductCreationTime();
    productCount++;
}

Product::~Product(){

}

void Product::outputReport() {
    cout << "ID: " << getProductNum()
        << "\nName: " << getProductName()
        << "\nDescription: " << getProductDescription()
        << "\nCreated time: " << getProductCreationTime() << endl;
    cout << endl;
}

bool Product::setProductName(string new_name) {
    productName = new_name;
    return true;
}

bool Product::setProductDescription(string new_description) {
    productDescription = new_description;
    return true;
}


int Product::getProductNum() {
    return productNum;
}

string Product::getProductName() {
    return productName;
}

string Product::getProductDescription() {
    return productDescription;
}

string Product::getProductCreationTime() {
    return productCreationTime;
}

int Product::getProductCount() {
    return productCount;
}

void Product::setProductNum() {
    productNum = rand() % 100000;
}

void Product::setProductCreationTime() {
    getTime(productCreationTime);
}

void Product::getTime(string &timestamp){
    time_t curr_time;
    curr_time = time(NULL);
    timestamp = ctime(&curr_time);
}