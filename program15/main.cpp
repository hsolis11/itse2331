//
// Created by hsolis on 12/4/21.
//

#include "main.h"


int main(){
    string userInput;

    string title; // title like Mr., Mrs. Ms., Sir, Madam, Dr., Doctor, Lord, Lady, His Illustrious Magesty, Darth, Prince, etc
    string petsName; // current or past
    string favoriteFictionalPlace; // example, Rivendell, Mordor, Death Star, Gallifrey, etc.
    string favoriteRealPlace; // example, Wisconsin, Cleveland, Texas, Antartica


    cout << "Type a title: ";
    getline(cin, userInput);
    title = userInput;

    cout << "Type your favorite drink: ";
    getline(cin, userInput);
    string favoriteDrink{userInput};

    cout << "Type your pets name: ";
    getline(cin, userInput);
    petsName.assign(userInput);

    cout << "Enter your favorite fictional place: ";
    getline(cin, userInput);
    favoriteFictionalPlace.assign(userInput);

    cout << "Enter your favorite real place: ";
    getline(cin, userInput);
    favoriteRealPlace = userInput;

    string fullName{title + favoriteDrink + " " + petsName};

    string from;
    from.append(favoriteFictionalPlace + " and " + favoriteRealPlace);

    string fullTitle;
    fullTitle += fullName;
    fullTitle.append(" of ");
    fullTitle.append(from, 0, from.size());
    cout << endl;

    cout << "Hello, " << fullTitle;

    cout << "\n\nString iterator displaying a string in forward order: \n";
    string::const_iterator iterator1{fullTitle.begin()};
    while(iterator1 != fullTitle.end()){
        cout << *iterator1;
        ++iterator1;
    }

    cout << "\n\nString iterator displaying a string in reverse order: \n";
    string::reverse_iterator iterator2{fullTitle.rbegin()};
    while(iterator2 != fullTitle.rend()){
        cout << *iterator2;
        ++iterator2;
    }

    cout << endl;
    cout << endl;

    string robotTitle = "Darth Oil Chip of the Cloud and Server";
    int robotIndexStart;
    int robotIndexEnd;
    int myIndexStart;
    int myIndexEnd;

    cout << "The robot also has a title and it is:\n"
        << robotTitle << endl;

    cout << endl;

    cout << "Compare the robots title with your title.\n";
    cout << "Type the starting index of the robot title to compare: ";
    getline(cin, userInput);
    robotIndexStart = std::stoi(userInput);

    cout << "Type the end index of the robot title to compare: ";
    getline(cin, userInput);
    robotIndexEnd = std::stoi(userInput);

    cout << "Type the starting index of your title to compare: ";
    getline(cin, userInput);
    myIndexStart = stoi(userInput);

    cout << "Type the end index of your title to compare: ";
    getline(cin, userInput);
    myIndexEnd = stoi(userInput);

    int result = robotTitle.compare(robotIndexStart, robotIndexEnd, fullTitle, myIndexStart, myIndexEnd);
    cout << "\nComparing '" << robotTitle.substr(robotIndexStart, robotIndexEnd - robotIndexStart)
        << "' and '" << fullTitle.substr(myIndexStart, myIndexEnd - myIndexStart) << "'. \n\n";

    if(result == 0){
        cout << "Both titles are equally worthy\n";
    } else if (result > 0){
        cout << "The robot title has a more worthy title\n";
    } else {
        cout << "Your title is more worthy than the robots!\n";
    }


    cout << "\nUsing ostringstream: \n";
    ostringstream outputString;
    outputString << title << favoriteDrink << " " << petsName << " of " << favoriteFictionalPlace << " and " << favoriteRealPlace;
    cout << "outputString contains:\n" << outputString.str();

    cout << endl;

    cout << "\nUsing istringstream: \n";
    string input{"Darth Oil Chip Cloud Server"};
    istringstream inputString{input};
    string robot_title;
    string robotDrink;
    string robotPetName;
    string robotFicPlace;
    string robotRealPlace;

    inputString >> robot_title >> robotDrink >> robotPetName >> robotFicPlace >> robotRealPlace;
    cout << "The extracted values:"
        << "\nrobot title: " << robot_title
        << "\nrobot favorite drink: " << robotDrink
        << "\nrobot pet name: " << robotPetName
        << "\nrobot favorite fictional place: " << robotFicPlace
        << "\nrobot favorite real place: " << robotRealPlace;

    cout << endl;
    cout << endl;

    cout << "Storing full titles in text file: ";
    ofstream myfile;
    myfile.open("myfile.txt");
    myfile << fullTitle << endl;
    myfile << robotTitle << endl;
    myfile.close();
    cout << " ...COMPLETE. Stored in 'myfile.txt'\n";

    string line;
    cout << "\nExtracting from file: \n";
    ifstream imyfile("myfile.txt");
    if(imyfile.is_open()){
        while(getline(imyfile, line)){
            cout << line << "\n";
        }
        imyfile.close();
        cout << "... COMPLETE";
    }



    return 0;
}