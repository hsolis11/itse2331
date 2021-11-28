//
// Created by hsoli on 11/20/2021.
//

#ifndef PROGRAM13_LIST_H
#define PROGRAM13_LIST_H

#include <iostream>
#include <array>

using namespace std;

template<typename NODETYPE>
class List {
public:
    List(){
        for(int i=0;i<50;i++){
            myArray[i] = -1;
        }
    }
    ~List(){
        if(!isEmpty()){
            std::cout << "Destroying nodes...\n";

        }

        std::cout << "All nodes destroyed\n\n";
    }

    bool insertAtFront(const NODETYPE& value){
        if(value > 0){
            array<NODETYPE, 50> tempArray;
            tempArray[0] = value;
            for(int i=1; i<50; i++){
                tempArray[i] = myArray[i-1];
            }
            myArray = tempArray;
            arraySize++;
            return true;
        }
        return false;
    } // end insertAtFront

    bool insertAtBack(const NODETYPE& value){
        if(value > 0){
            int index = 0;
            while(myArray[index] > -1){
                index++;
            }
            myArray[index] = value;
            arraySize++;
            return true;
        }
        return false;
    } // end insertAtBack

    bool removeFromFront(){
        if(arraySize < 0){
            return false;
        }
        array<NODETYPE, 50> tempArray;
        for(int i=1; i<arraySize; i++){
            tempArray[i-1] = myArray[i];
        }
        myArray = tempArray;
        arraySize--;
        return true;
    } // end removeFromFront

    bool removeFromBack(){
        myArray[arraySize--] = -1;
        return true;
    }

    bool insert(NODETYPE& value, int index){

        if(value > -1 && (index > -1 && index < arraySize)){
            array<NODETYPE, 50> tempArray;
            for(int i=0; i<=arraySize; i++){
                if(i<index){
                    tempArray[i] = myArray[i];
                }else if(i == index){
                    tempArray[i] = value;
                } else if(i <= arraySize){
                    tempArray[i] = myArray[i-1];
                }
            }
            myArray = tempArray;
            arraySize++;
            return true;
        }
        return false;
    }

    bool deleteByValue(NODETYPE& value){
        bool found = false;
        int index = -1;
        array<NODETYPE, 50> tempArray;

        for(int i=0; i < arraySize; i++){
            if(value == myArray[i]){
                found = true;
            }
            if(found){
                tempArray[i] = myArray[i+1];
            } else {
                tempArray[i] = myArray[i];
            }
        }
        myArray = tempArray;
        arraySize--;
        return found;
    }

    bool isEmpty() const {
        return arraySize < 0;
    }

    int getSize() const {
        return arraySize;
    }

    void print() const{
        cout << "Array: ";
        for(int i=0; i<arraySize; i++){
            if(myArray[i]>-1){
                cout << myArray[i] << ", ";
            }
        }
        cout << endl;
    } // end print()

    int LinearSearch(const NODETYPE& key){
        for(size_t i{0}; i<arraySize; ++i){
            if(key == myArray[i]){
                return i;
            }
        }
        return -1;
    }

    void SelectionSort(){
        for(size_t i{0}; i<arraySize -1; ++i){
            size_t indexOfSmallest{i};

            for(size_t index{i+1}; index<arraySize; ++index){
                if(myArray[index]<myArray[indexOfSmallest]){
                    indexOfSmallest = index;
                }
            }

            NODETYPE hold{myArray[i]};
            myArray[i] = myArray[indexOfSmallest];
            myArray[indexOfSmallest] = hold;
        }

    }

    void MergeSort(){
        mergeSort(myArray, 0, arraySize-1);
    }

    void displayElements(const array<NODETYPE, 50>& items, size_t low, size_t high){
        for(size_t i{0}; i<items.size() && i < low; ++i){
            cout << "   ";
        }
        for(size_t i{low}; i<items.size() && i <= high; ++i){
            cout << items[i] << " ";
        }
        cout << endl;
    }


    int BinarySearch(const NODETYPE& key){
        cout << "Sorting before binary search...\n";
        MergeSort();

        int low{0};
        int high{static_cast<int>(arraySize) -1};
        int middle{(low + high + 1) / 2};
        int location{-1};

        do {
            displayElements(myArray, low, high);

            for(int i{0}; i< middle; ++i){
                cout << "   ";
            }
            cout << " * " << endl;
            //    cout << "Before key: " << key << " location: " << location << " middle: " << middle << endl;
            if(key == myArray[middle]){
                //cout << "in equals\n";
                location = middle;
            }
            else if(key < myArray[middle]){
                //cout << "in less than\n";
                high = middle - 1;
            }
            else {
                //cout << "in else\n";
                low = middle + 1;
            }

            middle = (low + high + 1) / 2;
            //cout << "After key: " << key << " location: " << location << " middle: " << middle << endl;
        } while((low <= high) && (location == -1));

        cout << "location " << location << endl;

        return location;
    }





private:

    void mergeSort(array<NODETYPE, 50>& items, size_t low, size_t high) {
        if ((high - low) >= 1) {
            size_t middle1{(low + high) / 2};
            size_t middle2{middle1 + 1};

            mergeSort(items, low, middle1);
            mergeSort(items, middle2, high);

            merge(items, low, middle1, middle2, high);
        }
    }

    void merge(array<NODETYPE, 50>& items, size_t left, size_t middle1, size_t middle2, size_t right) {
        size_t leftIndex{left};
        size_t rightIndex{middle2};
        size_t combinedIndex{left};
        array <NODETYPE, 50> combined;

        while (leftIndex <= middle1 && rightIndex <= right) {
            if (items[leftIndex] <= items[rightIndex]) {
                combined[combinedIndex++] = items[leftIndex++];
            } else {
                combined[combinedIndex++] = items[rightIndex++];
            }
        }

        if (leftIndex == middle2) {
            while (rightIndex <= right) {
                combined[combinedIndex++] = items[rightIndex++];
            }
        } else {
            while (leftIndex <= middle1) {
                combined[combinedIndex++] = items[leftIndex++];
            }
        }

        for (size_t i = left; i <= right; ++i) {
            items[i] = combined[i];
        }
    }

    int arraySize{0};
    array<NODETYPE, 50> myArray;

};


#endif //PROGRAM13_LIST_H
