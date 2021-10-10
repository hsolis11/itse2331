#ifndef TWODAYPACKAGE_H
#define TWODAYPACKAGE_H

#include <string>

#include "package.h"

class TwoDayPackage: public Package {

public:

    TwoDayPackage();
    ~TwoDayPackage();

    double calculateCost();

    bool setTwoDayFee(double);

    double getTwoDayFee();


private:
    double twoDayFee;

};


#endif