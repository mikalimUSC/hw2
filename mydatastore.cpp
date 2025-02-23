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
    for (auto& term : terms) {
        if (keys.find(term) != keys.end()) {
          
            for (const auto& productName : keys[term]) {

                results.insert(productName);
            }
        }
    }

    std::vector<Product*> foundProducts;
    if (type == 1) { // OR search, using UNION
        for (auto& productName : results) {
            if (data.find(productName) != data.end()) {
                foundProducts.push_back(data[productName]);
            }
        }
    } else if (type == 0) { // AND search, using INTERSECTION!!!
        std::set<std::string> intersectionResults = results;
        for (auto& term : terms) {
            std::set<std::string> currentSet;
            if (keys.find(term) != keys.end()) {
                currentSet = keys[term];
            }
            std::set<std::string> tempIntersection;
            std::set_intersection(intersectionResults.begin(), intersectionResults.end(),
                                   currentSet.begin(), currentSet.end(),
                                   std::inserter(tempIntersection, tempIntersection.begin()));
            intersectionResults = std::move(tempIntersection);
        }
        for (auto& productName : intersectionResults) {
            if (data.find(productName) != data.end()) {
                foundProducts.push_back(data[productName]);
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
    
    for (const auto& productPtr : carts[username]) {
        const std::string productName = productPtr->getName(); 
        
        if (!data[productName]->getQty()) { 
            // std::cout << "Product " << productName << "out of stock" << std::endl;
            purchaseSuccessful = false;
            continue;  
        }
        User* userPtr = users.find(username)->second;
        if (userPtr->getBalance() < productPtr->getPrice()) {
            // std::cout << "NO BALANCEEE " << productName << "." << std::endl;
            purchaseSuccessful = false;
            continue;  
        }

  
        data[productName]->subtractQty(1);  
        userPtr->deductAmount(productPtr->getPrice());  
        carts[username].erase(carts[username].begin());
    }
    return purchaseSuccessful;
}


void MyDataStore::dump(std::ostream& ofile) {
    ofile << "<products>\n";
    for (auto& pair : products) {
        pair->dump(ofile);
    }
    ofile << "</products>\n";

    ofile << "<users>\n";
    for (auto& pair : users) {
        pair.second->dump(ofile);
    }
    ofile << "</users>\n";
}
