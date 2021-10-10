#include "main.h"

int main(){
    bool sendPackage = true;
    char response[2];

    while(sendPackage){
        cout << "Send a package? ";
        cin.getline(response, 2);

        if(response[0] == 'y' || response[0] == 'Y'){
            char userInput[256];
            string userName;
            string userAddress;
            string userCity;
            string userState;
            int sendersZip;
            int receiversZip;
            double packageWeight;
            double costPerOunce;

            cout << "Building user profile for shipping" << endl;
            cout << "Enter Name: ";
            cin.getline(userInput, 50);
            userName = userInput;

            cout << "Enter Address: ";
            cin.getline(userInput, 50);
            userAddress = userInput;

            cout << "Enter City: ";
            cin.getline(userInput, 50);
            userCity = userInput;

            cout << "Enter State: ";
            cin.getline(userInput, 50);
            userState = userInput;

            cout << "Zipcode of sender: ";
            cin.getline(userInput, 6);
            sendersZip = atoi(userInput);

            cout << "Zipcode of receiver: ";
            cin.getline(userInput, 6);
            receiversZip = atoi(userInput);

            cout << "Weight of package: ";
            cin.getline(userInput, 100);
            packageWeight = atof(userInput);

            cout << "Cost per Ounce: ";
            cin.getline(userInput, 100);
            costPerOunce = atof(userInput);

            cout << endl;
            cout << endl;

            bool validShippingOption = false;

            while(!validShippingOption){
                cout << "Shipping options" << endl;
                cout << "1) Overnight Shipping \n2) Two Day Shipping \n3) Regular Shipping" << endl;
                cout << "Select a shipping option: ";
                cin.getline(userInput, 2);
                cout << endl;

                if(userInput[0] == '1'){
                    validShippingOption = true;
                    OvernightPackage nightshipping;
                    cout << "Overnight shipping selected" << endl;
                    cout << "Overnight rate: ";
                    cin.getline(userInput, 100);
                    nightshipping.setOvernightRate(atof(userInput));

                    nightshipping.setName(userName);
                    nightshipping.setAddress(userAddress);
                    nightshipping.setCity(userCity);
                    nightshipping.setState(userState);
                    nightshipping.setSenderZip(sendersZip);
                    nightshipping.setReceiverZip(receiversZip);
                    nightshipping.setWeight(packageWeight);
                    nightshipping.setCostPerOunce(costPerOunce);

                    cout << endl;
                    cout << endl;

                    cout << "User shipping info" << endl;
                    cout << "Name: " << nightshipping.getName() << endl;
                    cout << "Address: " << nightshipping.getAddress() << endl;
                    cout << "City: " << nightshipping.getCity() << endl;
                    cout << "State: " << nightshipping.getState() << endl;
                    cout << "Senders zipcode: " << nightshipping.getSenderZip() << endl;
                    cout << "Receivers Zipcode: " << nightshipping.getReceiverZip() << endl;
                    cout << "Package Weight: " << nightshipping.getWeight() << endl;
                    cout << "Cost per Ounce: " << nightshipping.getCostPerOunce() << endl;
                    cout << "Overnight rate: " << nightshipping.getOvernightRate() << endl;
                    cout << endl;
                    cout << "Total shipping cost: " << nightshipping.calculateCost() << endl;
                    cout << endl;
                    cout << endl;

                } else if (userInput[0] == '2'){
                    validShippingOption = true;
                    TwoDayPackage twodayshipping;
                    cout << " Two Day Shipping selected" << endl;
                    cout << "Two day shipping fee: ";
                    cin.getline(userInput, 100);
                    twodayshipping.setTwoDayFee(atof(userInput));

                    twodayshipping.setName(userName);
                    twodayshipping.setAddress(userAddress);
                    twodayshipping.setCity(userCity);
                    twodayshipping.setState(userState);
                    twodayshipping.setSenderZip(sendersZip);
                    twodayshipping.setReceiverZip(receiversZip);
                    twodayshipping.setWeight(packageWeight);
                    twodayshipping.setCostPerOunce(costPerOunce);

                    cout << endl;
                    cout << endl;

                    cout << "User shipping info" << endl;
                    cout << "Name: " << twodayshipping.getName() << endl;
                    cout << "Address: " << twodayshipping.getAddress() << endl;
                    cout << "City: " << twodayshipping.getCity() << endl;
                    cout << "State: " << twodayshipping.getState() << endl;
                    cout << "Senders zipcode: " << twodayshipping.getSenderZip() << endl;
                    cout << "Receivers Zipcode: " << twodayshipping.getReceiverZip() << endl;
                    cout << "Package Weight: " << twodayshipping.getWeight() << endl;
                    cout << "Cost per Ounce: " << twodayshipping.getCostPerOunce() << endl;
                    cout << "Two day shipping fee: " << twodayshipping.getTwoDayFee() << endl;
                    cout << endl;
                    cout << "Total shipping cost: " << twodayshipping.calculateCost() << endl;
                    cout << endl;
                    cout << endl;
                } else if (userInput[0] == '3'){
                    validShippingOption = true;
                    Package regularshipping;
                    cout << "Regular shipping selected" << endl;

                    regularshipping.setName(userName);
                    regularshipping.setAddress(userAddress);
                    regularshipping.setCity(userCity);
                    regularshipping.setState(userState);
                    regularshipping.setSenderZip(sendersZip);
                    regularshipping.setReceiverZip(receiversZip);
                    regularshipping.setWeight(packageWeight);
                    regularshipping.setCostPerOunce(costPerOunce);

                    cout << endl;
                    cout << endl;

                    cout << "User shipping info" << endl;
                    cout << "Name: " << regularshipping.getName() << endl;
                    cout << "Address: " << regularshipping.getAddress() << endl;
                    cout << "City: " << regularshipping.getCity() << endl;
                    cout << "State: " << regularshipping.getState() << endl;
                    cout << "Senders zipcode: " << regularshipping.getSenderZip() << endl;
                    cout << "Receivers Zipcode: " << regularshipping.getReceiverZip() << endl;
                    cout << "Package Weight: " << regularshipping.getWeight() << endl;
                    cout << "Cost per Ounce: " << regularshipping.getCostPerOunce() << endl;
                    cout << endl;
                    cout << "Total shipping cost: " << regularshipping.calculateCost() << endl;
                    cout << endl;
                    cout << endl;
                } else {
                    cout << "Error: invalid input. Enter one of the following 1,2,3.";
                }
            }

        } else if(response[0] == 'n' || response[0] == 'N'){
            sendPackage = false;
        } else {
            cout << "Error: Invalid response. Type y for Yes and n for No" << endl;
        }


    }









    return 0;
}