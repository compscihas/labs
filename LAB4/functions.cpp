
#include "functions.h"
#include <iostream>
#include <string>
#include <stdexcept>

// add any includes

using std::cout, std::cin, std::endl, std::string;

void deobfuscate() {
    // TODO
    int x = 0;
}

void wordFilter() {
    // TODO
    string sentence;
    string fword;
    int index = 1;
    string reps;
    cout << "Please enter the sentence: ";
    getline(cin, sentence);
    cout << "Please enter the filter word: ";
    cin >> fword;
    for (int i = 0; i < fword.length(); i++){
        reps += "#";
    }
    while (index > 0){
        index = sentence.find(fword);
        if ((index > 0) && (index < sentence.length())){
            sentence.replace(index, fword.length(), reps);
        }
    }
    cout << "Filtered sentence: " << sentence << endl;

}


void passwordConverter() {
    // TODO
    string password = "";
    string passwordBack = "";
    string revPassword = "";
    cout << "Please enter your text input: ";
    cin >> password;
    cout << "input: " << password << endl;
    unsigned int pLen = password.length();
    for(unsigned int i=0; i< pLen; ++i){
        if (password.at(i) == 'a'){
            password[i] = '@';
        }
        if (password.at(i) == 'e'){
            password[i] = '3';
        }
        if (password.at(i) == 'i'){
            password[i] = '!';
        }
        if (password.at(i) == 'o'){
            password[i] = '0';
        }
        if (password.at(i) == 'u'){
            password[i] = '^';
        }
    }
    for(unsigned int i=0; i < pLen; i++){
        revPassword += password[pLen - 1 - i];
    }
    password += revPassword;
    cout << "output: " << password << endl;
}

void wordCalculator() {
    // TODO
    int x = 0;
}

void palindromeCounter() {
    // TODO
    int x = 0;
}