#include "main.h"

bool is_positive_integer(char*);
void printArray(array<array<string, dragons>, characters>);
bool processYN(string);

int main(){

    bool addCharacter = true;
    int count{0};

    array<array<string, dragons>, characters> gotData;

    cout << endl;
    cout << "=============================" << endl;
    cout << "Character & Dragon data entry" << endl;
    cout << "=============================" << endl;
    cout << endl;

    while(addCharacter && count < gotData.size()){

        string question = "Would you like to enter a character?(y/n) ";

        addCharacter = processYN(question);
        

        if (addCharacter && count < 9){
            cout << "Enter the character name: ";
            cin >> gotData[count][0];

            bool valid = false;

            while(!valid){
                char dragonCount[256];
                cout << "How many dragons would you like to enter for "<< gotData[count][0] << "? ";
                cin >> dragonCount;

                if(is_positive_integer(dragonCount)){
                    if(atoi(dragonCount) < 10){
                        for(int i=1; i < atoi(dragonCount)+1; i++){
                            cout << "Enter the name of dragon " << i << ": ";
                            cin >> gotData[count][i];
                        }
                        valid = true;
                    } else {
                        cout << "Error: Invalid response. Must type a positive integer from 0 to 9." << endl;
                    }
                    
                } else {
                    cout << "Error: Invalid response. Must type a positive integer from 0 to 9." << endl;
                }
            }
            
            cout << endl;
        }

        count++;
    }
    
    printArray(gotData);
    cout << endl;

    
    bool addKingdom = true;
    vector<string> kingdomNames;
    vector<int> armySize;

    cout << endl;
    cout << "=============================" << endl;
    cout << "Kingdom & Army size data entry" << endl;
    cout << "=============================" << endl;
    cout << endl;

    while(addKingdom){
        string question = "Would you like to enter a kingdom?(y/n) ";
        addKingdom = processYN(question);

        if(addKingdom){
            string kingdomName;
            cout << "Enter the kingdom name: ";
            cin >> kingdomName;
            // getline(cin, kingdomName);
            // getline(cin, kingdomName);
            kingdomNames.push_back(kingdomName);

            int kingdomSize;
            cout << "Enter the army size: ";
            // cin >> kingdomSize;
            cin >> kingdomSize;
            armySize.push_back(kingdomSize);
            cout << endl;
        }

    }

    for(int i = 0; i < kingdomNames.size(); i++){
        cout << "Kingdom: " << kingdomNames[i] << endl;
        cout << "Army Size: " << armySize[i] << endl;
        cout << endl;
    }

    return 0;
}




bool is_positive_integer(char* value){

    bool not_int = false;

    if(strlen(value) > 0){
        for(int i = 0; i < strlen(value); i++){
            if(!(value[i] >= 48 && value[i] <= 57)){
                not_int = true;
            }
        }
    }
    
    return !(not_int);
}

void printArray(array<array<string, dragons>, characters> data){
    cout << "============================================" << endl;
    cout << "Printing character and dragon collected data" << endl;
    cout << "============================================" << endl;

    for(int character=0; character < data.size(); character++){

        if(data[character][0] != ""){
            cout << "Name: " << data[character][0] << endl;

            cout << "Dragons: " << endl;
            for(int dragon=1; dragon < data[character].size(); dragon++){
                if(data[character][dragon] != ""){
                    cout << "\t" << data[character][dragon] << endl;
                }
            }
            cout << endl;
        }
        
    }

}

bool processYN(string question){
    bool answer = false;
    string response;
    bool initvalid = false;

    while(!initvalid){
        cout << question;
        cin >> response;
        cout << endl;

        if((response[0] == 'y' || response[0] == 'Y' || response[0] == 'n' || response[0] == 'N') && (response.length() < 2 && response.length() > 0)){
            answer = response[0] == 'y' || response[0] == 'Y'? true: false;
            initvalid = true;
        } else {
            cin.clear();
            cout << "Error: Invalid response. Must type one of the following [y, Y, n, N]." << endl;
        }
    }
    return answer;
}