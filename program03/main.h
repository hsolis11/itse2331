#ifndef MAIN_H
#define MAIN_H

#include <string>
#include <iostream>
#include <vector>
#include <stdlib.h> // srand, rand
#include <time.h> // time
#include <sstream>

#include "customer.h"
#include "order.h"
// #include "product.h"

using std::cout;
using std::endl;
using std::cin;
using std::string;
using std::vector;


int Customer::customerCount = 0;
int Order::orderCount = 0;


vector<Customer> customerList;
vector<Order> orderList;
// vector<Product> productList;

#endif