#include "book.h"
#include <iostream>
#include <sstream>
#include <algorithm>
#include "util.h"

using namespace std;

Book::Book(const std::string& category, const std::string& name, double price, int qty,
           const std::string& ISBN, const std::string& author)
    : Product(category, name, price, qty), ISBN_(ISBN), author_(author) {}

Book::~Book() {}

// Notes: product name + the words in the author’s name should be searchable keywords as well as the book’s ISBN number
std::set<std::string> Book::keywords() const {
    std::set<std::string> keys = parseStringToWords(author_);
    keys.insert(ISBN_);
    set<string> namekeys = parseStringToWords(name_);
    for (const string& word : namekeys) {
        keys.insert(word);
    }
    keys.insert("book");
    return keys;
}

// Format
/*<name>
Author: <author> ISBN: <isbn>
<price> <quantity> left.
*/
std::string Book::displayString() const {
    return getName() + "\n" +
           "Author: " + author_ + " ISBN: " + ISBN_ + "\n" +
           to_string(getPrice()) + " " + to_string(getQty()) + " left.";
}

void Book::dump(std::ostream& os) const {
    os << category_ << endl;
    os << name_ << endl;
    os << price_ << endl;
    os << qty_ << endl;
    os << ISBN_ << endl;
    os << author_ << endl;
}
