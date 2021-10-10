#include "twodaypackage.h"

TwoDayPackage::TwoDayPackage() {
    twoDayFee = 0;
}

TwoDayPackage::~TwoDayPackage(){

}

double TwoDayPackage::calculateCost() {
    double cost;

    if(getWeight() > 0 && getCostPerOunce() > 0 && twoDayFee > 0){
        cost = (getWeight() * getCostPerOunce()) + twoDayFee;
    } else {
        throw 0;
    }
    return cost;
}

bool TwoDayPackage::setTwoDayFee(double newFee) {
    bool success = false;

    if(newFee > 0){
        twoDayFee = newFee;
        success = true;
    }
    return success;
}

double TwoDayPackage::getTwoDayFee() {
    return twoDayFee;
}