//
//  mastermind.cpp
//  std_lib_facilities_mac
//
//  Created by Christian Sletten on 31/01/2019.
//  Copyright © 2019 Lars Musaus. All rights reserved.
//
#include "std_lib_facilities.h"
#include "utilities.hpp"
#include "tests.hpp"
#include "mastermind.hpp"
#include "masterVisual.h"


void playMastermind(){
    int constexpr size = 4;
    int constexpr letters = 6;
    int constexpr win_w = 400;
    int constexpr win_h = 600;
    
    int round = 0;

    int attempts = 2;
    
    // Fordi vi ønsker at variablene skal initaliseres ved kompilering
    
    string code = "";
    string guess = "";
    
    code = randomizeString(size, 'A', 'A'+letters-1);
    cout << "Fasit: " << code << endl;
    
    MastermindWindow mwin{Point{900, 20}, win_w, win_h, "Mastermind"};
    addGuess(mwin, code, size, 'A', round);
//    hideCode(mwin, 4);
    
    while (attempts){
        guess = readInputToString(size, 'A', 'A'+letters-1);
        round++;
        addGuess(mwin, guess, size, 'A', round);
        
        int numChars = checkCharacters(code, guess);
        int numCharsandPos = checkCharactersAndPosition(code, guess);
        
        addFeedback(mwin, numChars, numCharsandPos, size, round);
        
        mwin.wait_for_button();
        
        cout << "Antall riktig gjettede bokstaver: " << numChars << endl;
        cout << "Antall bokstaver på riktig plass: " << numCharsandPos << endl;
        
        if (numCharsandPos == size){
            keep_window_open();
            break;
        }
        attempts --;
    }
    if (!attempts){
        cout << "Du har tapt! " << endl;
    } else{
        cout << "Gratulerer, du har vunnet!" << endl;
    }
}

int checkCharactersAndPosition(string solution, string guess){
    int correctAnswers = 0;
    for (int i = 0; i < solution.size(); i++){
        if (solution[i] == guess[i]){
            correctAnswers++;
        }
    }
    return correctAnswers;  
}

int checkCharacters(string solution, string guess){
    constexpr int letters = 6;
    vector<int> characterCounts;
    for (int i = 0; i < letters; i++){
        characterCounts.push_back(0);
    }
    for (char j : solution){
        int idx = j - 'A';
        characterCounts[idx]++;
    }
    /*
    for (int k: characterCounts){
        cout << "Antall: " << k <<endl;
    }
     */
    int result = 0;
    for (char l: guess){
        int idx = l - 'A';
        if (idx > letters-1){
            continue;
        }
        if (characterCounts[idx] > 0){
            characterCounts[idx]--;
            result ++;
        }
    }
    return result;
}

