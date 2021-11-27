//
// Created by hsolis on 11/26/21.
//

#include "mergesort.h"


template <typename T, size_t size>
void displayElements(const array<T, size>& items, size_t low, size_t high){
    for(size_t i{0}; i<items.size() && i<low; ++i){
        cout << "   ";
    }

    for(size_t i{low}; i<items.size() && i <= high; ++i){
        cout << items[i] << " ";
    }

    cout << endl;
}

template <typename T, size_t size>
void mergeSort(array<T, size>& items, size_t low, size_t high){
    if((high - low) >= 1){
        size_t middle1{(low + high) / 2};
        size_t middle2{middle1 + 1};

        cout << "split:   ";
        displayElements(items, low, high);
        cout << "         ";
        displayElements(items, low, middle1);
        cout << "         ";
        displayElements(items, middle2, high);
        cout << endl;

        mergeSort(items, low, middle1);
        mergeSort(items, middle2, high);

        mergeSort(items, low, middle1, middle2, high);
    }
}


template <typename T, size_t size>
void merge(array<T, size>& items, size_t left, size_t middle1, size_t middle2, size_t right){
    size_t leftIndex{left};
    size_t rightIndex{middle2};
    size_t combinedIndex{left};
    array<T, size> combined;

    cout << "merge:   ";
    displayElements(items, left, middle1);
    cout << "         ";
    displayElements(items, middle2, right);
    cout << endl;

    while(leftIndex <= middle1 && rightIndex <= right){
        if(items[leftIndex] <= items[rightIndex]){
            combined[combinedIndex++] = items[leftIndex++];
        } else {
            combined[combinedIndex++] = items[rightIndex++];
        }
    }

    if(leftIndex == middle2){
        while(rightIndex <= right){
            combined[combinedIndex++] = items[rightIndex++];
        }
    } else {
        while(leftIndex <= middle1){
            combined[combinedIndex++] = items[leftIndex++];
        }
    }

    for(size_t i = left; i <= right; ++i){
        items[i] = combined[i];
    }

    cout << "         ";
    displayElements(items, left, right);
    cout << endl;
}