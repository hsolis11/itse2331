//
// Created by hsoli on 11/20/2021.
//

#include "main.h"

void instructions() {
    cout << "Enter one of the following:\n"
         << " 1 to insert at begining of list\n"
         << " 2 to insert at end of list\n"
         << " 3 to delete from begining of list\n"
         << " 4 to delete from end of list\n"
         << " 5 to end list processing\n";
}


template<typename T>
void testList(List<T>& listObject, const string& typeName){
    cout << "Testing a List of " << typeName << " values\n";
    instructions();

    int choice;
    T value;

    do {
        cout << "? ";
        cin >> choice;

        switch(choice){
            case 1:
                cout << "Enter " << typeName << ": ";
                cin >> value;
                listObject.insertAtFront(value);
                listObject.print();
                break;

            case 2:
                cout << "Enter " << typeName << ": ";
                cin >> value;
                listObject.insertAtBack(value);
                listObject.print();
                break;
            case 3:
                if(listObject.removeFromFront(value)){
                    cout << value << " removed from list\n";
                }

                listObject.print();
                break;
            case 4:
                if(listObject.removeFromBack(value)){
                    cout << value << " removed from list\n";
                }

                listObject.print();
                break;
        }
    } while (choice < 5);
    cout << "End list test\n\n";
}


int main(){

    List<int> integerList;
    testList(integerList, "integer");

    List<double> doubleList;
    testList(doubleList, "double");


    return 0;
}