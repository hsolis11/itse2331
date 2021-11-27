//
// Created by hsolis on 11/26/21.
//

#ifndef ITSE2331_MERGESORT_H
#define ITSE2331_MERGESORT_H

#include <array>
#include <ctime>
#include <iostream>
#include <random>
using namespace std;

template <typename T, size_t size>
void displayElements(const array<T, size>& items, size_t low, size_t high);

template <typename T, size_t size>
void mergeSort(array<T, size>& items, size_t low, size_t high);

template <typename T, size_t size>
void merge(array<T, size>& items, size_t left, size_t middle1, size_t middle2, size_t right);

#endif //ITSE2331_MERGESORT_H
