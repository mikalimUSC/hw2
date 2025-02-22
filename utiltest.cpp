#include <iostream>
#include <sstream>
#include <cctype>
#include <algorithm>
#include "util.h"
#include <string>

using namespace std;

void printset(const set<string>& s);

int main() {
    string test1 = "This is a simple test";
    cout << "Test 1 (simple) result:" << endl;
    set<string> wordset1 = parseStringToWords(test1);
    printset(wordset1);

    string test2 = "The quick brown fox jumps over the lazy dog.";
    cout<< "Test 2 (fox) result:" << endl;
    set<string> wordset2 = parseStringToWords(test2);
    printset(wordset2);

    string test3 = "";
    cout<< "Test 3 (empty) result:" << endl;
    set<string> wordset3 = parseStringToWords(test3);
    printset(wordset3);

    string test4 = "J. Random Hacker";
    cout<< "Test 4 (J.) result:"<< endl;
    set<string> wordset4 = parseStringToWords(test4);
    printset(wordset4);

    cout << "UNION/INTERSECTION TESTS"<<endl;

    std::set<std::string> set1;
    set1.insert("a");
    set1.insert("b");
    set1.insert("c");

    std::set<std::string> set2;
    set2.insert("e");
    set2.insert("f");
    set2.insert("g");
    set2.insert("a");

    std::set<std::string> result1 = setIntersection(set1, set2);
    std::cout << "Intersection of set{a,b,c} with {e,f,g} ";
    printset(result1);

    std::set<std::string> u1 = setUnion(set1, set2);
    std::cout << "Union of that set is  ";
    printset(u1);

    // Test case 2
    std::set<std::string> set3;
    set3.insert("a");
    set3.insert("b");
    set3.insert("c");

    std::set<std::string> set4;
    set4.insert("b");
    set4.insert("c");
    set4.insert("d");
    set4.insert("l");
    set4.insert("k");

    std::set<std::string> result2 = setIntersection(set3, set4);
    std::cout << "Intersection of set{a,b,c} with {b,c,d,l,k} ";
    printset(result2);

    std::set<std::string> u2 = setUnion(set3, set4);
    std::cout << "Union of that set is  ";
    printset(u2);

    // Test case 3
    std::set<std::string> set5;
    std::set<std::string> set6;

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
