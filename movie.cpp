#include "movie.h"
#include <iostream>
#include <sstream>
#include <algorithm>
#include "util.h"

using namespace std;

Movie::Movie(const std::string& category, const std::string& name, double price, int qty,
             const string& genre, const string& rating)
    : Product(category, name, price, qty), genre_(genre), rating_(rating) {}

Movie::~Movie() {}

\
std::set<std::string> Movie::keywords() const {
    std::set<std::string> keys = parseStringToWords(name_);

    keys.insert(genre_);
    for (const string& word : keys) {
        string lowerCaseWord = word;
        transform(lowerCaseWord.begin(), lowerCaseWord.end(), lowerCaseWord.begin(),::tolower);
        keys.insert(lowerCaseWord);
    }
    return keys;
}

std::string Movie::displayString() const {
    return getName() + "\n" +
           "Genre: " + genre_ + " Rating: " + rating_ + "\n" +
           to_string(getPrice()) + " " + to_string(getQty()) + " left.";
}

void Movie::dump(std::ostream& os) const {
    os << category_ << endl;
    os << name_ << endl;
    os << price_ << endl;
    os << qty_ << endl;
    os << genre_ << endl;
    os << rating_ << endl;
}
