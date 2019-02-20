//
//  fileintro.cpp
//  std_lib_facilities_mac
//
//  Created by Christian Sletten on 15/02/2019.
//  Copyright © 2019 Lars Musaus. All rights reserved.
//

#include "std_lib_facilities.h"
#include "fileintro.hpp"
#include "CourseCatalog.hpp"
#include "temps.hpp"

void storeInput(){
    string userInput;
    string oname;
    cout << "Please enter name of output file: ";
    cin >> oname;
    ofstream ost {oname};
    if (!ost) error("Can't open output file", oname);
    while (userInput != "quit"){
        cout << "Enter words one by one (write 'quit' to quit): ";
        cin >> userInput;
        if (userInput == "quit"){break;}
        ost << userInput << endl;
    }
}

void readline(){
    string word;
    cout << "Please enter input file name: ";
    string iname;
    cin >> iname;
    ifstream ist {iname};
    if (!ist) error("Can't open input filename ", iname);
    vector<string> words;
    while(ist >> word){
        words.push_back(word);
    }
    for (string word: words){
        cout << word << endl;;
    }
}

void charStatistics(){
    vector<int> charAmount(26);
    string word;
    cout << "Please enter input file name: ";
    string iname;
    cin >> iname;
    ifstream ist {iname};
    if (!ist) error("Can't open input filename ", iname);
    while (ist >> word){
        for (int i = 0; i < word.length(); i++){
            char letter = tolower(word[i]);
            // Sjekker om karakteren er en bokstav mellom a-z
            if (letter >= 'a' && letter <= 'z'){
                charAmount[tolower(word[i])-'a']++;
            }
        }
    }
    // Skriver ut forekomstene av bokstavene a-z
    for (int i = 0; i < charAmount.size(); i++){
        cout << char(i + 'a') << ": " << charAmount[i] << endl;
    }
}



