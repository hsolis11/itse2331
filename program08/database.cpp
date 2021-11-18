#include "database.h"

Database::Database() {

}

Database::~Database() {

}

bool Database::setFile(string file) {
    bool success = false;

    if(!file.empty()){
        file_name = file;
        success = true;
    }
    return success;
}

bool Database::processFile() {
    string data;
    ifstream MyReadFile(file_name);
    int row = 0;
    int column = 0;

    while(getline(MyReadFile, data)){

        int count = 0;
        int found = 0;
        string temp;

        while(data[count] != '\0'){
            if(data[count] == '\n'){
                data.erase(count, 1);
            }
            count++;
        }

        vector<string> customer;
        string data2;
        while(getline(MyReadFile, data2, '%')){
            customer.push_back(data2);
        }
        customers.push_back(customer);
    }

//    while(getline(MyReadFile, data, '%')){
//        int count = 0;
//        int found = 0;
//        string temp;
//
//
////        while(data[count] != '\0'){
////            if(data[count]=='\n'){
////                temp = data.substr(0, count-1);
////            }
////            count++;
////        }
//        while(data[count] != '\0'){
//            if(data[count] == '\n'){
//                found = count;
//                data.erase(found, 1);
//            }
//            count++;
//        }
//        cout << "Length is " << count;
////        if(data.find('\0')){
////            // cout << "Found NULL" << endl;
////        }
//
//
////        if(found < count){
////             // cout << "Found new line" << endl;
////             // cout << data << " at " << data.find('\n') << endl;
////             data.erase(data.find('\n'), 1);
////        }
//
//        if(column < 6){
//            customer.push_back(data);
//            column++;
//        } else {
//            customer.push_back(data);
//            customers.push_back(customer);
//
//            vector<string> new_customer;
//            customer = new_customer;
//            column = 0;
//            row++;
//        }
//    }

    MyReadFile.close();
    return true;
}

void Database::printData() {
    for(int i=0; i < customers.size(); i++){
        for(int j=0; j<7; j++){
            cout << customers[i][j] << " ";
        }
        cout << endl;
        cout << endl;

    }

    cout << endl;
    cout << endl;
    cout << "start";
    for(int i=0; i < 7; i++){
        cout << customers[25][i] << " ";

    }
    cout << "end";
}

void Database::customersInCities(string city) {
    int city_column = 4;
    for(int i=0; i < customers.size(); i++){
        if(customers[i][city_column] == city){
            for(int j=0; j<7; j++){
                cout << customers[i][j] << " ";
            }
        }
    }
}