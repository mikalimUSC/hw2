#ifndef MYDATASTORE_H
#define MYDATASTORE_H
#include <string>
#include <set>
#include <vector>
#include <map>
#include "product.h"
#include "user.h"
#include "datastore.h"

using namespace std;

class MyDataStore : public DataStore {
public:
    virtual ~MyDataStore();

    /**
     * Adds a product to the data store
     */
    virtual void addProduct(Product* p);

    /**
     * Adds a user to the data store
     */
    virtual void addUser(User* u);

;
   std::vector<Product*> getCart(const std::string& username) const;
    bool buyCart(const std::string& username);
    void addToCart(const std::string& username, Product* product) ;
    
    /**
     * Performs a search of products whose keywords match the given "terms"
     *  type 0 = AND search (intersection of results for each term) while
     *  type 1 = OR search (union of results for each term)
     */
    virtual std::vector<Product*> search(std::vector<std::string>& terms, int type);
    const map<string, User*>& getUsers();
    /**
     * Reproduce the database file from the current Products and User values
     */
    virtual void dump(std::ostream& ofile);

    private:
   vector<Product*> products;// added to keep the FIFO order yay
    map<string,Product*> data; //key is the product name, value is the prodocut object itself
    map<string, set<string> > keys; //map key is the productname, value is the set contains all keywords
    map<string,User*> users;
    map<string, vector<Product*>> carts;


};

#endif
