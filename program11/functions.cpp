//
// Created by hsoli on 11/7/2021.
//

#include "functions.h"

int multiple_choice(){
    char user_input[2];
    // TODO: Demonstrate exception handling. Supply appropriate interaction (input/output)
    // employ the appropriate try-throw-catch paradigm
    cout << "List of exceptions" << endl;
    cout << "\t1. Division by zero" << endl;
    cout << "\t2. Rethrowing exceptions" << endl;
    cout << "\t3. Stack unwinding" << endl;
    cout << "\t4. Using the 'new' operator to throw a bad_alloc exception type" << endl;
    cout << "\t5. Using the 'new' operator to demonstrate set_new_handler" << endl;
    cout << "Type the row number to execute the exception: " << endl;
    cin.getline(user_input, 2);

    return atoi(user_input);
}

double quotient(int numerator, int denominator){
    if (denominator == 0){
        throw DivideByZeroException{};
    }

    return static_cast<double>(numerator) / denominator;
}

void divide_zero(){
    int number1;
    int number2;

    cout << "Enter two integers (end-of-file to end): ";

    while(cin >> number1 >> number2){
        try {
            double result{quotient(number1, number2)};
            cout << "The quotient is: " << result << endl;
        } catch (const DivideByZeroException& divideByZeroException) {
            cout << "Exception occurred: " << divideByZeroException.what() << endl;
        }

        cout << "\nEnter two integers (end-of-file to end): ";
    }
    cout << endl;
}

void throwException(){
    try {
        cout << "\tFunction throwException throws an exception\n";
        throw exception{};
    } catch(const exception&){
        cout << "\tException handled in function throwException";
        cout << "\n\tFunction throwException rethrows exception";
        throw;
    }
}

void function3(){
    cout << "In function3" << endl;
    throw runtime_error{"runtime_error in function3"};
}
void function2(){
    cout << "function3 is called inside function2" << endl;
    function3();
}
void function1(){
    cout << "function2 is called inside function1" << endl;
    function2();
}

void customNewHandler(){
    cerr << "customNewHandler was called\n";
    exit(EXIT_FAILURE);
}