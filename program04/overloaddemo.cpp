//
// Created by hsoli on 9/13/2021.
//

#include "overloaddemo.h"

OverloadDemo::OverloadDemo() {
    intOne = 0;
    doubleOne = 0;
    stringOne = "";

}

OverloadDemo::~OverloadDemo() {

}

ostream& operator<<(ostream& output, const OverloadDemo& d){
    output << d;
    return output;
}

/*********************************
 * Getters
 * ******************************/

int OverloadDemo::getIntOne() {
    return intOne;
}

double OverloadDemo::getDoubleOne() {
    return doubleOne;
}

string OverloadDemo::getStringOne() {
    return stringOne;
}

/*********************************
 * Setters
 * ******************************/

void OverloadDemo::setIntOne(int value) {
    intOne = value;
}

void OverloadDemo::setDoubleOne(double value) {
    doubleOne = value;
}

void OverloadDemo::setStringOne(string value) {
    stringOne = value;
}

/*********************************
 * Operator Overloading
 * ******************************/

void OverloadDemo::operator+(int value) {
    intOne += value;
}

void OverloadDemo::operator-(int value) {
    intOne -= value;
}

void OverloadDemo::operator*(int value) {
    intOne *= value;
}

void OverloadDemo::operator/(int value) {
    intOne /= value;
}

void OverloadDemo::operator++() {
    intOne += 1;
    doubleOne +=1;
}

void OverloadDemo::operator--() {
    intOne -= 1;
    doubleOne -= 1;
}

void OverloadDemo::operator++(int value) {
    intOne += 1;
    doubleOne += 1;
}

void OverloadDemo::operator--(int value) {
    intOne -= 1;
    doubleOne -= 1;
}






void OverloadDemo::operator+(double value) {
    doubleOne += value;
}

void OverloadDemo::operator-(double value) {
    doubleOne -= value;
}

void OverloadDemo::operator*(double value) {
    doubleOne *= value;
}

void OverloadDemo::operator/(double value) {
    doubleOne /= value;
}



void OverloadDemo::operator+(string value) {
    stringOne += value;
}

void OverloadDemo::operator-(string value) {
    for(int i=0; i < value.size(); i++){
        stringOne.erase(remove(stringOne.begin(), stringOne.end(), value[i]), stringOne.end());
    }
}

void OverloadDemo::operator*(string value) {
    stringOne = stringOne + "*" + value;
}

void OverloadDemo::operator/(string value) {
    stringOne = stringOne + "/" + value;
}
