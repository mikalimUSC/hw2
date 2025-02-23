#include "mydatastore.h"
#include <iostream>
#include <fstream>
#include "product.h"

MyDataStore::~MyDataStore() {
    for (auto& val : users) {
        delete val.second;
    }

    for (auto& val : data) {
        delete val.second;
    }

}

void MyDataStore::addProduct(Product* p) {
    data[p->getName()] = p;
    products.push_back(p);
    for (const std::string& keyword : p->keywords()) {
        keys[keyword].insert(p->getName());
    }
}

void MyDataStore::addUser(User* u) {
    users[u->getName()] = u;
}

std::vector<Product*> MyDataStore::search(std::vector<std::string>& terms, int type) {

    std::set<std::string> results;
    std::vector<std::string>::iterator term_iterator;
    for (term_iterator = terms.begin(); term_iterator != terms.end(); ++term_iterator) {
        if (keys.find(*term_iterator) != keys.end()) {
          
            std::set<std::string>::iterator productName_iterator;
            for (productName_iterator = keys[*term_iterator].begin(); productName_iterator != keys[*term_iterator].end(); ++productName_iterator) {

                results.insert(*productName_iterator);
            }
        }
    }

    std::vector<Product*> foundProducts;
    if (type == 1) { // OR search, using UNION
        std::set<std::string>::iterator productName_iterator;
        for (productName_iterator = results.begin(); productName_iterator != results.end(); ++productName_iterator) {
            if (data.find(*productName_iterator) != data.end()) {
                foundProducts.push_back(data[*productName_iterator]);
            }
        }
    } else if (type == 0) { // AND search, using INTERSECTION!!!
        std::set<std::string> intersectionResults = results;
        for (term_iterator = terms.begin(); term_iterator != terms.end(); ++term_iterator) {
            std::set<std::string> currentSet;
            if (keys.find(*term_iterator) != keys.end()) {
                currentSet = keys[*term_iterator];
            }
            std::set<std::string> tempIntersection;
            std::set_intersection(intersectionResults.begin(), intersectionResults.end(),
                                   currentSet.begin(), currentSet.end(),
                                   std::inserter(tempIntersection, tempIntersection.begin()));
            intersectionResults = std::move(tempIntersection);
        }
        std::set<std::string>::iterator productName_iterator;
        for (productName_iterator = intersectionResults.begin(); productName_iterator != intersectionResults.end(); ++productName_iterator) {
            if (data.find(*productName_iterator) != data.end()) {
                foundProducts.push_back(data[*productName_iterator]);
            }
        }
    }


    return foundProducts;
}


void MyDataStore::addToCart(const std::string& username, Product* product) {
    if (users.find(username) == users.end()) {
       // std::cout << "User not found!" << std::endl;
        return;
    }
    const std::string productName = product->getName();  // Get the product name
    
    if (data.find(productName) == data.end()) {  // Check using product name
        //std::cout << "Product not found!" << std::endl;
        return;
    }
    carts[username].push_back(product);  // Add Product* to cart
}
std::vector<Product*> MyDataStore::getCart(const std::string& username) const {
    if (carts.find(username) == carts.end()) {
        return {};
    }
    return carts.at(username);
}


bool MyDataStore::buyCart(const std::string& username) {
    if (carts.find(username) == carts.end()) {
        return false;
    }

    bool purchaseSuccessful = true;
    std::vector<Product*> cartCopy = carts[username];
    for (Product* product : cartCopy) {
        const std::string productName = product->getName();

        if (!data[productName]->getQty()) {
            // std::cout << "Product " << productName << " out of stock" << std::endl;
            purchaseSuccessful = false;
            continue;
        }
        User* userPtr = users.find(username)->second;
        if (userPtr->getBalance() < product->getPrice()) {
            // std::cout << "NO BALANCEEE " << productName << "." << std::endl;
            purchaseSuccessful = false;
            continue;
        }

        data[productName]->subtractQty(1);
        userPtr->deductAmount(product->getPrice());
        
   
        carts[username].erase(std::remove(carts[username].begin(), carts[username].end(), product), carts[username].end());
    }

    return purchaseSuccessful;
}


const map<string, User*>& MyDataStore::getUsers() {
    return users;
}

void MyDataStore::dump(std::ostream& ofile) {
    ofile << "<products>\n";
    std::vector<Product*>::iterator product_iterator;
    for (product_iterator = products.begin(); product_iterator != products.end(); ++product_iterator) {
        (*product_iterator)->dump(ofile);
    }
    ofile << "</products>\n";

    ofile << "<users>\n";
    std::map<string, User*>::iterator user_iterator;
    for (user_iterator = users.begin(); user_iterator != users.end(); ++user_iterator) {
        user_iterator->second->dump(ofile);
    }
    ofile << "</users>\n";
}
