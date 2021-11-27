//
// Created by hsolis on 11/26/21.
//

#include "binarysearch.h"

template <typename T, size_t size>
void displayElements(const array<T, size>& items, size_t low, size_t high){
    for(size_t i{0}; i<items.size() && i<low; ++i){
        cout << "  ";
    }
    for(size_t i{low}; i<items.size() && i <= high; ++i){
        cout << items[i] << " ";
    }

    cout << endl;
}

template <typename T, size_t size>
int binarySearch(const array<T, size>& items, const T& key){
    int low{0};
    int high{static_cast<int>(items.size()) -1};
    int middle{(low + high + 1) / 2};
    int location{-1};

    do {
        displayElements(items, low, high);

        for(int i{0}; i < middle; ++i){
            cout << "   ";
        }

        cout << " * " << endl;

        if(key == items[middle]){
            location = middle;
        }
        else if(key < items[middle]){
            high = middle - 1;
        }
        else {
            low = middle + 1;
        }

        middle = (low + high + 1) / 2;
    } while((low <= high) && (location == -1));

    return location;
}