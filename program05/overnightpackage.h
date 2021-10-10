#ifndef OVERNIGHTPACKAGE_H
#define OVERNIGHTPACKAGE_H

#include <string>

#include "package.h"

using std::string;

class OvernightPackage: public Package{

public:
    OvernightPackage();
    ~OvernightPackage();

    double calculateCost();

    bool setOvernightRate(double);

    double getOvernightRate();

private:
    double overnightRate; // an additional cost per ounce rate for overnight shipping.

};




#endif