#include "clothing.h"
#include <iostream>
#include <sstream>
#include <algorithm>
#include "util.h"

using namespace std;

Clothing::Clothing(const std::string& category, const std::string& name, double price, int qty,
                   const string& size, const string& brand)
    : Product(category, name, price, qty), size_(size), brand_(brand) {}

Clothing::~Clothing() {}


std::set<std::string> Clothing::keywords() const {
    std::set<std::string> keys = parseStringToWords(brand_);
    set<string> namekeys = parseStringToWords(name_);
    for (const string& word : namekeys) {
        keys.insert(word);
    }
     for (const string& word : keys) {
        string lowerCaseWord = word;
        transform(lowerCaseWord.begin(), lowerCaseWord.end(), lowerCaseWord.begin(),::tolower);
        keys.insert(lowerCaseWord);
    }

    return keys;
}

std::string Clothing::displayString() const {
    return getName() + "\n" +
           "Size: " + size_ + " Brand: " + brand_ + "\n" +
           to_string(getPrice()) + " " + to_string(getQty()) + " left.";
}

void Clothing::dump(std::ostream& os) const {
    os << category_ << endl;
    os << name_ << endl;
    os << price_ << endl;
    os << qty_ << endl;
    os << size_ << endl;
    os << brand_ << endl;
}
