//
// Created by hsoli on 11/10/2021.
//

#include "main.h"

int selectType();
int selectFunction();
void intHandler();

int main(){

    switch(selectType()){

        case 1:
            intHandler();
            break;
        case 2:
            cout << "Double" << endl;
            selectFunction();
            break;
        case 3:
            cout << "String" << endl;
            selectFunction();
            break;

    }

//    Stack<double> doubleStack;
//    const size_t doubleStackSize{5};
//    double doubleValue{1.1};
//
//    cout << "Pushing elements onto doubleStack\n";
//
//    for(size_t i{0}; i < doubleStackSize; i++){
//        doubleStack.push(doubleValue);
//        cout << doubleValue << " ";
//        doubleValue += 1.1;
//    }
//
//    cout << "\n\nPopping elements from doubleStack\n";
//
//    while(!doubleStack.empty()){
//        cout << doubleStack.top() << " ";
//        doubleStack.pop();
//    }
//
//    cout << "\nStack is empty, cannot pop.\n";
//
//
//
//    cout << "\nPushing elements onto intStack\n";
//
//    for(size_t i{0}; i < intStackSize; ++i){
//        intStack.push(intValue);
//        cout << intValue++ << " ";
//    }
//
//    cout << "\n\nPopping elements from intStack\n";
//    while(!intStack.empty()) {
//        cout << intStack.top() << " ";
//        intStack.pop();
//    }
//
//    cout << "\nStack is empty, cannot pop." << endl;
    return 0;
}

int selectType(){
    char answer[2];

    cout << "Types of Stacks\n";
    cout << "\t1. Integer\n";
    cout << "\t2. Double\n";
    cout << "\t3. String\n";
    cout << "Type the number associated with the stack type: ";
    cin.getline(answer, 2);

    return atoi(answer);
}

int selectFunction(){
    char answer[2];

    cout << "Types of functions\n";
    cout << "\t1. push()\n";
    cout << "\t2. pop()\n";
    cout << "\t3. top()\n";
    cout << "\t4. clear()\n";
    cout << "\t5. empty()\n";
    cout << "\t6. quit\n";
    cout << "Type the number associated with the function: ";
    cin.getline(answer, 2);

    return atoi(answer);
}

void intHandler(){
    cout << "Integer" << endl;
    int choice = 0;
    Stack<int> intStack;
    char inttopush[256];

    while(choice != 6){
        switch(choice){
            case 1:
                cout << "Type the integer to push: ";
                cin.getline(inttopush, 256);
                intStack.push(atoi(inttopush));
                break;

            case 2:
                try{
                    cout << "\nPopping value " << intStack.pop() << endl;
                } catch (...){
                    cout << "Error: nothing to pop\n\n";
                }
                break;

            case 3:
                try{
                    cout << "\nTop value is " << intStack.top() << endl;
                } catch (...){
                    cout << "Error: nothing on top\n\n";
                }
                break;

            case 4:
                cout << "Clearing stack" << endl;
                intStack.clear();
                break;

            case 5:
                if(intStack.empty()){
                    cout << "Is empty." << endl;
                } else {
                    cout << "Is not empty." << endl;
                }
                break;
        }

        choice = selectFunction();
    }
}