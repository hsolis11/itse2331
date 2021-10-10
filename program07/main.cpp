#include "main.h"

int main() {
    bool success = false;

    while(!success){
        PhoneNumber phone;

        cout << "Enter phone number in the form (888) 555-1234:" << endl;

        cin >> phone;

        if(!cin.fail()){
            success = true;
            cout << "\nThe phone number entered was:\n";

            cout << phone << endl;
        } else {
            char response[2];
            cin.clear();
            cout << "Invalid phone number has been entered." << endl;
            cout << "Would you like to enter another phone number? ";
            cin >> response;
            if(response[0] == 'y' || response[0] == 'Y'){
                cin.clear();
                cout << "\n\n\n" << endl;
            } else {
                cout << "else" << endl;
                success = true;
            }
        }
    }





    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    cin.clear();
    cout << "\n\n<ENTER> to exit: ";
    cin.get();

    return 0;
}