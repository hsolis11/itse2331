#ifndef PHONENUMBER_H
#define PHONENUMBER_H

#include <iostream>
#include <string.h>
#include <iomanip>
#include <cstring>
using namespace std;

class PhoneNumber {
    friend std::ostream& operator<<(std::ostream&, const PhoneNumber&);
    friend std::istream& operator>>(std::istream&, PhoneNumber&);

    private:
//    std::string areaCode;
//    std::string exchange;
//    std::string line;

    char phone[15]; // holds entire phone number plus \0
    char areaCode[4]; // holds area code plus \0
    char exchange[4]; // holds exchange plus \0
    char line[5]; // holds line plus \0
};

#endif // PHONENUMBER_H
