//
// Created by hsoli on 11/20/2021.
//

#include "main.h"

void instructions() {
    cout << "Enter one of the following:\n"
         << " 1. to insert at begining of list\n"
         << " 2. to insert at end of list\n"
         << " 3. to delete from begining of list\n"
         << " 4. to delete from end of list\n"
         << " 5. insert at a location (index value)\n"
         << " 6. delete a node from the list based on its value\n"
         << " 7. end list processing\n";
}

void search_sort_instructions(){
    cout << "Enter one of the following:\n"
        << "1. linear search\n"
        << "2. selection sort\n"
        << "3. merge sort\n"
        << "4. binary search\n"
        << "5. end list sort/search\n";
}


template<typename T>
void testList(List<T>& listObject, const string& typeName){
    cout << "Testing a List of " << typeName << " values\n";
    instructions();

    int choice;
    T value;
    int index;

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
                if(listObject.removeFromFront()){
                    cout << value << " removed from list\n";
                }

                listObject.print();
                break;
            case 4:
                if(listObject.removeFromBack()){
                    cout << value << " removed from list\n";
                }

                listObject.print();
                break;

            case 5:
                cout << "Enter " << typeName << ": ";
                cin >> value;
                cout << "Enter index position: ";
                cin >> index;

                listObject.insert(value, index);
                listObject.print();
                break;

            case 6:
                cout << "Enter " << typeName << ": ";
                cin >> value;

                listObject.deleteByValue(value);
                listObject.print();
        }
    } while (choice < 7);
    cout << "End list test\n\n";
}

template<typename T>
void searchSortList(List<T>& listObject, const string& typeName){
    cout << "Searching/sorting a List of " << typeName << " values\n";
    search_sort_instructions();

    int choice;
    T value;
    int element;

    do {
        cout << "? ";
        cin >> choice;

        switch(choice){
            case 1: // TODO: linearSearch
                cout << "Enter " << typeName << " to search in the list: ";
                cout << "Do line search" << endl;
                cin >> value;
                element = listObject.LinearSearch(value);
                if(element != -1){
                    cout << "Element found at index position " << element << ".\n";
                } else {
                    cout << "Element not found in list.\n";
                }
                break;

            case 2: // TODO: SelectionSort
                cout << "Performing Select Sort" << endl;
                listObject.SelectionSort();
                listObject.print();
                break;

            case 3: // TODO: merge  Sort
                cout << "Performing merge sort" << endl;
                listObject.MergeSort();
                listObject.print();
                break;

            case 4: // TODO: binary search
                cout << "Enter " << typeName << " to binary search in the list: ";
                cin >> value;
                element = listObject.BinarySearch(value);
                if(element != -1){
                    cout << "Element found at index position " << element << ".\n";
                } else {
                    cout << "Element not found in list.\n";
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
    searchSortList(integerList, "integer");


    List<double> doubleList;
    testList(doubleList, "double");
    searchSortList(doubleList, "double");


    return 0;
}