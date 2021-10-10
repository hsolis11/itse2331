#include "overnightpackage.h"


OvernightPackage::OvernightPackage() {
    overnightRate = 0;
}

OvernightPackage::~OvernightPackage(){

}

double OvernightPackage::calculateCost() {
    double cost;
    if(getWeight() > 0 && getCostPerOunce() > 0 && overnightRate > 0){
        cost = getWeight() * (getCostPerOunce() + overnightRate);
    } else {
        throw 0;
    }
    return cost;
}

bool OvernightPackage::setOvernightRate(double newRate) {
    bool success = false;

    if(newRate > 0){
        overnightRate = newRate;
        success = true;
    }
    return success;
}

double OvernightPackage::getOvernightRate() {
    return overnightRate;
}