#include "main.h"


int main() {
    char userInput[20];
    int userInt;
    double userDouble;
    string userString;

    OverloadDemo overload = OverloadDemo();

    cout << "[Overload Demo]" << endl;
    cout << "Type an integer value: ";
    cin.getline(userInput, 20);
    userInt = atoi(userInput);
    overload.setIntOne(userInt);

    cout << "Type a double value: ";
    cin.getline(userInput, 20);
    userDouble = atof(userInput);
    overload.setDoubleOne(userDouble);

    cout << "Type a string value: ";
    cin.getline(userInput, 20);
    userString = userInput;
    overload.setStringOne(userString);

    cout << endl;
    cout << "Displaying all overloaded functions for the data" << endl;
    cout << endl;

    cout << "Integer overload starting with user's set value: " << overload.getIntOne() << endl;
    cout << "Adding integer 10" << endl;
    overload + 10;
    cout << "\tNew integer value = " << overload.getIntOne() << endl;
    cout << endl;

    cout << "Subtracting integer 5" << endl;
    overload - 5;
    cout << "\tNew integer value = " << overload.getIntOne() << endl;
    cout << endl;

    cout << "Multiplying integer 7" << endl;
    overload * 7;
    cout << "\tNew integer value = " << overload.getIntOne() << endl;
    cout << endl;

    cout << "Dividing integer 2" << endl;
    overload / 2;
    cout << "\tNew integer value = " << overload.getIntOne() << endl;
    cout << endl;

    cout << "Adding using ++(postfix)" << endl;
    overload++;
    cout << "\tNew integer value = " << overload.getIntOne() << endl;
    cout << endl;

    cout << "Adding using ++(prefix)" << endl;
    ++overload;
    cout << "\tNew integer value = " << overload.getIntOne() << endl;
    cout << endl;

    cout << "Subtracting using --(postfix)" << endl;
    overload--;
    cout << "\tNew integer value = " << overload.getIntOne() << endl;
    cout << endl;

    cout << "Subtracting using --(prefix)" << endl;
    --overload;
    cout << "\tNew integer value = " << overload.getIntOne() << endl;
    cout << endl;
    cout << endl;


    /***********************************************
     * Double Overloading
     ***********************************************/
    cout << "Double overload starting with user's set value: " << overload.getDoubleOne() << endl;
    cout << "Adding double 10.0" << endl;
    overload + 10.5;
    cout << "\tNew double value = " << overload.getDoubleOne() << endl;
    cout << endl;

    cout << "Subtracting double 5.0" << endl;
    overload - 5.0;
    cout << "\tNew double value = " << overload.getDoubleOne() << endl;
    cout << endl;

    cout << "Multiplying double 7.0" << endl;
    overload * 7.0;
    cout << "\tNew double value = " << overload.getDoubleOne() << endl;
    cout << endl;

    cout << "Dividing double 2.0" << endl;
    overload / 2.0;
    cout << "\tNew double value = " << overload.getDoubleOne() << endl;
    cout << endl;

    cout << "Adding using ++(postfix)" << endl;
    overload++;
    cout << "\tNew double value = " << overload.getDoubleOne() << endl;
    cout << endl;

    cout << "Adding using ++(prefix)" << endl;
    ++overload;
    cout << "\tNew double value = " << overload.getDoubleOne() << endl;
    cout << endl;

    cout << "Subtracting using --(postfix)" << endl;
    overload--;
    cout << "\tNew double value = " << overload.getDoubleOne() << endl;
    cout << endl;

    cout << "Subtracting using --(prefix)" << endl;
    --overload;
    cout << "\tNew double value = " << overload.getDoubleOne() << endl;
    cout << endl;
    cout << endl;


    /***********************************************
    * String Overloading
    ***********************************************/
    cout << "String overload starting with user's set value: " << overload.getStringOne() << endl;
    cout << "Adding string Again" << endl;
    overload + "Again";
    cout << "\tNew string value = " << overload.getStringOne() << endl;
    cout << endl;

    cout << "Subtracting string Hello" << endl;
    overload - "Hello";
    cout << "\tNew string value = " << overload.getStringOne() << endl;
    cout << endl;

    cout << "Multiplying string multiply" << endl;
    overload * "multiply";
    cout << "\tNew string value = " << overload.getStringOne() << endl;
    cout << endl;

    cout << "Dividing string divide" << endl;
    overload / "divide";
    cout << "\tNew string value = " << overload.getStringOne() << endl;
    cout << endl;

    cout << "Adding using ++(postfix)" << endl;
    overload++;
    cout << "\tNew string value = " << overload.getStringOne() << endl;
    cout << endl;

    cout << "Adding using ++(prefix)" << endl;
    ++overload;
    cout << "\tNew string value = " << overload.getStringOne() << endl;
    cout << endl;

    cout << "Subtracting using --(postfix)" << endl;
    overload--;
    cout << "\tNew string value = " << overload.getStringOne() << endl;
    cout << endl;

    cout << "Subtracting using --(prefix)" << endl;
    --overload;
    cout << "\tNew string value = " << overload.getStringOne() << endl;
    cout << endl;

    return 0;
}
