//
// Created by hsolis on 11/26/21.
//

#include "linearsearch.h"


template <typename T, size_t size>
int linearSearch(const array<T, size>& items, const T& key){
    for(size_t i{0}; i<items.size(); ++i){
        if(key == items[i]){
            return i;
        }
    }
    return -1;
}