#include "package.h"

Package::Package() {
    name = "";
    address = "";
    city = "";
    state = "";
    zipSender = 0;
    zipReceiver = 0;
    weight = 0.0;
    costPerOunce = 0.0;
}

Package::~Package() {

}

double Package::calculateCost() {
    double cost = 0.0;

    if(weight > 0 && costPerOunce > 0){
        cost = weight * costPerOunce;
    } else {
        throw 0;
    }
    return cost;
}

/*************************************
 * SETTERS
 ************************************/

bool Package::setName(string newName) {
    bool success = false;

    if(newName != ""){
        name = newName;
        success = true;
    }
    return success;
}

bool Package::setAddress(string newAddress) {
    bool success = false;

    if(newAddress != ""){
        address = newAddress;
        success = true;
    }
    return success;
}

bool Package::setCity(string newCity) {
    bool success = false;

    if(newCity != ""){
        city = newCity;
        success = true;
    }
    return success;
}

bool Package::setState(string newState) {
    bool success = false;

    if(newState != ""){
        state = newState;
        success = true;
    }
    return success;
}

bool Package::setSenderZip(int zipcode) {
    bool success = false;

    if(zipcode > 0 && zipcode < 99999){
        zipSender = zipcode;
        success = true;
    }
    return success;
}

bool Package::setReceiverZip(int zipcode) {
    bool success = false;

    if(zipcode > 0 && zipcode < 99999){
        zipReceiver = zipcode;
        success = true;
    }
    return success;
}

bool Package::setWeight(double newWeight) {
    bool success = false;

    if(newWeight > 0){
        weight = newWeight;
        success = true;
    }
    return success;
}

bool Package::setCostPerOunce(double newCost) {
    bool success = false;

    if(newCost > 0){
        costPerOunce = newCost;
        success = true;
    }
    return success;
}

/*************************************
 * GETTERS
 ************************************/

string Package::getName(){
    return name;
}

string Package::getAddress(){
    return address;
}

string Package::getCity(){
    return city;
}

string Package::getState(){
    return state;
}

int Package::getSenderZip(){
    return zipSender;
}

int Package::getReceiverZip() {
    return zipReceiver;
}

double Package::getWeight() {
    return weight;
}

double Package::getCostPerOunce() {
    return costPerOunce;
}