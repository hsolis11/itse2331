#include "main.h"

void outputReport(){


}


int main(){

    vector<Customer> customerList;

    bool createNewCustomer = true;
    char createCustomerResponse[5];
    char customeryn[5];

    while(createNewCustomer){
        cout << "Create new customer? (y/n)" << endl;
        cin.getline(createCustomerResponse, 5);

        if(createCustomerResponse[0] == 'y' || createCustomerResponse[0] == 'Y'){
            char customerName[256];
            char customerAddress[256];
            cout << "Creating new customer " << endl;

            cout << "Enter customers name: ";
            cin.getline(customerName, 256);
            Customer customer = Customer(customerName);


            cout << "Enter customers " << customerName << "'s address: ";
            cin.getline(customerAddress, 256);
            customer.setAddress(customerAddress);


            cout << "Add order to customer " << customer.getName() << "? (y/n)" << endl; 
            cin.getline(customeryn, 5);
            if(customeryn[0]== 'y' || customeryn[0] == 'Y'){
                bool addMore = true;
                char orderNum[25];

                while(addMore){
                    cout << "Enter the customers order number: ";
                    cin.getline(orderNum, 25);
                }
                
            }
            cout << endl;

            

            customerList.push_back(customer);
        } else {
            createNewCustomer = false;
        }


    }
    
    cout << "[OUTPUT CUSTOMER REPORT]" << endl;
    for(Customer customer:customerList){
        customer.outputReport();
        cout << endl;
    }

    


    return 0;
}