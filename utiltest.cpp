#include <iostream>
#include <sstream>
#include <cctype>
#include <algorithm>
#include "util.h"
#include <string>

using namespace std;
 void printset(const set<string>& s);
int main(){
    // string test1 = "Men's";
    // string test2 = "P.arty";
    // string test3 = "Super.man:power;wow";
    // string test4 = "J.";

    // cout<< "Test 1 (Men's) result:"<< endl;
    // set<string> wordset1 = parseStringToWords(test1);

    // printset(wordset1);
    // cout<< "Test 2 (P.arty) result:"<< endl;
    // set<string> wordset2 = parseStringToWords(test2);
    // printset(wordset2);
    // set<string> wordset3 = parseStringToWords(test3);
    // cout<< "Test 3 (Super.man:power;wow) result:"<< endl;
    // printset(wordset3);
    // cout<< "Test 4 (J.) result:"<< endl;
    // set<string> wordset4 = parseStringToWords(test4);
    // printset(wordset4);

    cout << "UNION/INTERSECTION TESTS"<<endl;

    std::set<std::string> set1 = {"a","b","c"};
    std::set<std::string> set2 = {"e","f","g","a"};
    std::set<std::string> result1 = setIntersection(set1, set2);
    std::cout << "Intersection of set{a,b,c} with {e,f,g} ";
    printset(result1);
    std::set<std::string> u1 = setUnion(set1, set2);
    std::cout << "Union of that set is  ";
    printset(u1);

    // Test case 2
    std::set<std::string> set3 = {"a","b","c"};
    std::set<std::string> set4 = {"b","c","d","l","k"};
    std::set<std::string> result2 = setIntersection(set3, set4);
    std::cout << "Intersection of set{a,b,c} with {b,c,d,l,k} ";
    printset(result2);
    std::set<std::string> u2 = setUnion(set3, set4);
    std::cout << "Union of that set is  ";
    printset(u2);

     std::set<std::string> set5 = {"a"};
    std::set<std::string> set6 = {};
    std::set<std::string> result3 = setIntersection(set5, set6);
    std::cout << "Intersection of set {a} and empty set {} ";
    printset(result3);
    std::set<std::string> u3 = setUnion(set5, set6);
    std::cout << "Union of that set is  ";
    printset(u3);
    
return 0;
   
}
void printset(const set<string>& s) {
    for (const string& val : s) {
        std::cout << val << " ";
    }
    std::cout << endl;
}