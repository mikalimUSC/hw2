#include <iostream>
#include <sstream>
#include <cctype>
#include <algorithm>
#include "util.h"
#include <string>

using namespace std;
void printset(const set<string>& s);
int main(){
    string test1 = "Men's";
    string test2 = "P.arty";
    string test3 = "Super.man:power;wow";
    string test4 = "whoops.";

    cout<< "Test 1 (Men's) result:"<< endl;
    set<string> wordset1 = parseStringToWords(test1);

    printset(wordset1);


    cout<< "Test 2 (P.arty) result:"<< endl;
    set<string> wordset2 = parseStringToWords(test2);
    printset(wordset2);
    set<string> wordset3 = parseStringToWords(test3);
    cout<< "Test 3 (Super.man:power;wow) result:"<< endl;
    printset(wordset3);
    cout<< "Test 4 (whoops.) result:"<< endl;
    set<string> wordset4 = parseStringToWords(test4);

    printset(wordset4);
}

void printset(const set<string>& s){
     for (const string& val : s) {
        std::cout << val << " "; 
    }
    std::cout << std::endl;
}
