#ifndef PRODUCT_H
#define PRODUCT_H

#include <string>
#include <vector>
#include <stdlib.h> // srand, rand
#include <time.h> // time
#include <ctime>
#include <iostream>

using std::string;
using std::vector;
using std::time_t;
using std::cout;
using std::endl;


class Product {

    public:
        
        Product();
        ~Product();

        void outputReport();

        // setters
        bool setProductName(string);
        bool setProductDescription(string);

        // getters
        int getProductNum();
        string getProductName();
        string getProductDescription();
        string getProductCreationTime();
        static int getProductCount();

    private:
        void setProductNum();
        void setProductCreationTime();
        void getTime(string&);

        int productNum;
        string productName;
        string productDescription;


        string productCreationTime;

        static int productCount;



};



#endif