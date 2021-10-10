//
// Created by hsoli on 9/13/2021.
//

#ifndef PROGRAM04_OVERLOADDEMO_H
#define PROGRAM04_OVERLOADDEMO_H

#include <string>
#include <algorithm>
using std::string;
using std::ostream;

class OverloadDemo {


public:
    OverloadDemo();
    ~OverloadDemo();

    int getIntOne();
    double getDoubleOne();
    string getStringOne();

    void setIntOne(int);
    void setDoubleOne(double);
    void setStringOne(string);

    // +, -, *, /, ++ (prefix and postfix), -- (prefix and postfix)
    friend ostream& operator<<(ostream&, const OverloadDemo&);
    void operator+(int);
    void operator+(double);
    void operator+(string);
    void operator-(int);
    void operator-(double);
    void operator-(string);
    void operator*(int);
    void operator*(double);
    void operator*(string);
    void operator/(int);
    void operator/(double);
    void operator/(string);
    void operator++();
    void operator--();
    void operator++(int);
    void operator--(int);


private:

    int intOne;
    double doubleOne;
    string stringOne;
};


#endif //PROGRAM04_OVERLOADDEMO_H
