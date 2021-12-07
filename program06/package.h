#ifndef PACKAGE_H
#define PACKAGE_H

#include <string>

using std::string;

class Package{

public:
    Package();
    ~Package();

    // member functions
    virtual double calculateCost(); // returns a double of weight x costPerOunce
    // ENSURE weight and costPerOunce is > 0

    // Setters
    bool setName(string);
    bool setAddress(string);
    bool setCity(string);
    bool setState(string);
    bool setSenderZip(int);
    bool setReceiverZip(int);
    bool setWeight(double);
    bool setCostPerOunce(double);

    // Getters
    string getName();
    string getAddress();
    string getCity();
    string getState();
    int getSenderZip();
    int getReceiverZip();
    double getWeight();
    double getCostPerOunce();


private:
    string name;
    string address;
    string city;
    string state;
    int zipSender;
    int zipReceiver;
    double weight;
    double costPerOunce;

};

#endif