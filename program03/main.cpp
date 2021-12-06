#include "main.h"

void outputReport(){
    cout << "\n\nPrinting Report of all " << Customer::getCustomerCount() << " customers:\n";
    for (auto it = customerList.begin(); it != customerList.end(); ++it){
        it->outputReport();
    }

    cout << "\n\nPrinting Report of all " << Order::getOrderCount() << " orders:\n";
    for (auto it = orderList.begin(); it != orderList.end(); ++it){
        it->outputReport();
    }

    cout << "\n\nPrinting Report of all " << Product::getProductCount() << " products:\n";
    for (auto it = productList.begin(); it != productList.end(); ++it){
        it->outputReport();
    }

}

/*
 * TODO: Simulate a simple product ordering system. Provide functionality to allow your user to create new customers, new products, and new orders.
 * Customers will have orders. Orders will have products.
 * */
int main(){


    bool createNewCustomer = true;
    string customerInput;

    cout << "Creating Customers";
    while(createNewCustomer){

        cout << "\n\nCreate new customer? ";
        getline(cin, customerInput);

        if(customerInput[0] == 'y' || customerInput[0] == 'Y'){

            string name;
            cout << "Enter the customers full name: ";
            getline(cin, name);
            Customer customer(name);

            cout << "Customer profile started\n";
            cout << "CustomerID: " << customer.getCustID() << ", Name: " << customer.getName()
                << ", created at: " << customer.getCustomerCreationTime() << endl;
            cout << "Enter the customers address: ";
            getline(cin, customerInput);
            customer.setAddress(customerInput);

            bool addOrder = true;
            string orderNum;
            string decision;

            while(addOrder){
                cout << "Add an order? ";
                getline(cin, decision);
                if(decision[0] == 'y' || decision[0] == 'Y'){
                    cout << "Enter the order number: ";
                    getline(cin, orderNum);
                    customer.addOrder(stoi(orderNum));
                } else {
                    addOrder = false;
                }
            }
            customerList.push_back(customer);

        } else {
            createNewCustomer = false;
        }

    } // end createNewCustomer while loop

    /******************************************************************************************************************
     * Orders Class
     *****************************************************************************************************************/
    bool createNewOrder = true;
    string userInput;

    cout << "Creating New Orders\n";
    while(createNewOrder){

        cout << "\n\nCreate new order? ";
        getline(cin, userInput);

        if(userInput[0] == 'y' || userInput[0] == 'Y'){

            string orderNumber;
            string customerID;

            cout << "\nEnter a customers ID: ";
            getline(cin, customerID);
            Order order(stoi(customerID));
            cout << "Order started\n";
            cout << "Order number: " << order.getOrderNum()
                << " for customer ID: " << order.getCustID()
                << " on " << order.getOrderCreationTime() << endl;

            bool addProduct = true;
            string productID;
            string decision;

            while(addProduct){
                cout << "Add a product to order: " << order.getOrderNum() << "? ";
                getline(cin, decision);
                if(decision[0] == 'y' || decision[0] == 'Y'){
                    cout << "Enter product ID: ";
                    getline(cin, productID);
                    order.addProduct(stoi(productID));

                } else {
                    addProduct = false;
                }
            }
            orderList.push_back(order);


        } else {
            createNewOrder = false;
        }
    }


    /******************************************************************************************************************
     * Product Class
     *****************************************************************************************************************/
    bool createNewProduct = true;

    cout << "Creating New Product\n";
    while(createNewProduct){

        cout << "\n\nCreate new product? ";
        getline(cin, userInput);

        if(userInput[0] == 'y' || userInput[0] == 'Y'){

            string productName;
            string productDescription;

            cout << "\nEnter product name: ";
            getline(cin, productName);

            cout << "\nEnter product description: ";
            getline(cin, productDescription);

            Product product;
            product.setProductName(productName);
            product.setProductDescription(productDescription);

            cout << "\nNew product created:" << endl;
            product.outputReport();

            productList.push_back(product);

        } else {
            createNewProduct = false;
        }
    }















    outputReport();

    return 0;
}