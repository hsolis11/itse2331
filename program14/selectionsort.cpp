//
// Created by hsolis on 11/26/21.
//

#include "selectionsort.h"


template <typename T, size_t size>
void selectionSort(array<T, size>& items){

    for(size_t i{0}; i<items.size() -1; ++i){
        size_t indexOfSmallest{i};

        for(size_t index{i+1}; index<items.size(); ++index){
            if(items[index]<items[indexOfSmallest]){
                indexOfSmallest = index;
            }
        }

        T hold{items[i]};
        items[i] = items[indexOfSmallest];
        items[indexOfSmallest] = hold;
    }
}