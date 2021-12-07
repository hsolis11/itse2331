#include "main.h"

int main(){
    bool sendPackage = true;
    char response[2];

    while(sendPackage){
        cout << "Send a package(y/n)? ";
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
                    OvernightPackage *nightshipping = new OvernightPackage;
                    cout << "Overnight shipping selected" << endl;
                    cout << "Overnight rate: ";
                    cin.getline(userInput, 100);
                    nightshipping->setOvernightRate(atof(userInput));

                    nightshipping->setName(userName);
                    nightshipping->setAddress(userAddress);
                    nightshipping->setCity(userCity);
                    nightshipping->setState(userState);
                    nightshipping->setSenderZip(sendersZip);
                    nightshipping->setReceiverZip(receiversZip);
                    nightshipping->setWeight(packageWeight);
                    nightshipping->setCostPerOunce(costPerOunce);

                    cout << endl;
                    cout << endl;

                    packages.push_back(nightshipping);

                } else if (userInput[0] == '2'){
                    validShippingOption = true;
                    TwoDayPackage *twodayshipping = new TwoDayPackage;
                    cout << " Two Day Shipping selected" << endl;
                    cout << "Two day shipping fee: ";
                    cin.getline(userInput, 100);
                    twodayshipping->setTwoDayFee(atof(userInput));

                    twodayshipping->setName(userName);
                    twodayshipping->setAddress(userAddress);
                    twodayshipping->setCity(userCity);
                    twodayshipping->setState(userState);
                    twodayshipping->setSenderZip(sendersZip);
                    twodayshipping->setReceiverZip(receiversZip);
                    twodayshipping->setWeight(packageWeight);
                    twodayshipping->setCostPerOunce(costPerOunce);

                    packages.push_back(twodayshipping);


                } else if (userInput[0] == '3'){
                    validShippingOption = true;
                    Package *regularshipping = new Package;
                    cout << "Regular shipping selected" << endl;

                    regularshipping->setName(userName);
                    regularshipping->setAddress(userAddress);
                    regularshipping->setCity(userCity);
                    regularshipping->setState(userState);
                    regularshipping->setSenderZip(sendersZip);
                    regularshipping->setReceiverZip(receiversZip);
                    regularshipping->setWeight(packageWeight);
                    regularshipping->setCostPerOunce(costPerOunce);

                    packages.push_back(regularshipping);
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

    //Iterate through the vector to process the Packages polymorphically.
    // That is, output the data contained in each object.
    // Keep an accumulator of total cost and report the total cost after all object data has been reported.
    cout << endl;
    cout << endl;
    cout << "Printing All Shipping Info" << endl;
    cout << endl;

    double totalCost = 0;

    for (Package* packagePtr : packages){
        if(packagePtr != nullptr){
            // cout << "User shipping info for package " << 1 << endl;
            cout << "Name: " << packagePtr->getName() << endl;
            cout << "Address: " << packagePtr->getAddress() << endl;
            cout << "City: " << packagePtr->getCity() << endl;
            cout << "State: " << packagePtr->getState() << endl;
            cout << "Senders zipcode: " << packagePtr->getSenderZip() << endl;
            cout << "Receivers Zipcode: " << packagePtr->getReceiverZip() << endl;
            cout << "Package Weight: " << packagePtr->getWeight() << endl;
            cout << "Cost per Ounce: " << packagePtr->getCostPerOunce() << endl;

            cout << endl;
            cout << "Shipping cost: " << packagePtr->calculateCost() << endl;
            totalCost += packagePtr->calculateCost();
            cout << endl;
            cout << endl;
        }

    }

    cout << endl;
    cout << endl;
    cout << "Total Shipping Cost = " << totalCost << endl;

    return 0;
}