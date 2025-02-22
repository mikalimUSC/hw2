#include <iostream>
#include <vector>

#include "mydatastore.h"
#include "book.h"
#include "movie.h"
#include "clothing.h"
#include "user.h"
#include <fstream>
using namespace std;

int main() {
    MyDataStore ds = MyDataStore();


    // Movie::Movie(const std::string& category, const std::string& name, double price, int qty,
    //          const string& genre, const string& rating)

    Movie* m1 = new Movie("movie", "Wolfwalkers", 20.50, 3, "Kids", "PG");
    Movie* m2 = new Movie("movie", "Millenium Actress", 25.50, 1, "Drama", "PG-13");
    Movie* m3 = new Movie("movie", "There Will Be Blood", 25.50, 1, "Drama", "R");
    Movie* m4 = new Movie("movie", "Blair Witch Project", 25.50, 1, "Horror", "R");

    Book* b1 = new Book("book", "Project Hail Mary",15.00, 4, "ISBN100000", "Andy Weir" );
    Book* b2 = new Book("book", "Catcher in the Rye",15.00, 2, "ISBN1001222", "J. D. Salinger" );
    Book* b3 = new Book("book", "Project Minotaur",15.00, 1, "ISBN100102", "Johnny Quest" );
    Book* b4 = new Book("book", "10 Art Projects For Kids",15.00, 1, "ISBN1220112", "Johnny Smith" );
 
 //User::User(std::string name, double balance, int type) :name_(name), balance_(balance), type_(type)
    User* u1 = new User("Mika", 20.00, 1);
    User* u2 = new User("Nat", 30.00,0);
    User* u3 = new User("Kae", 12.00, 3);


    ds.addProduct(m1);
    ds.addProduct(m2);
    ds.addProduct(m3);
        ds.addProduct(m4);
    ds.addProduct(b1);
    ds.addProduct(b2);
    ds.addProduct(b3);
    ds.addProduct(b4);

    ds.addUser(u1);
    ds.addUser(u2);
    ds.addUser(u3);



    // vector<string> terms1 = {"Book"};
    // vector<Product*> results1 = ds.search(terms1, 0); // AND search

    // cout << "AND search results for 'Book':\n";
    // for (Product* p : results1) {
    //     cout << p->displayString() << "\n\n";
    // }


    vector<string> terms2 = { "Project", "book"};
    vector<Product*> results2 = ds.search(terms2, 0); 
    cout << "AND search results for 'Project':\n";
    cout<< "Vector size is " << results2.size()<< endl;
    for (Product* p : results2) {
        cout << p->getName() << "\n\n";
    }


    ofstream dumpFile("datastore_dump.txt");
    ds.dump(dumpFile);
    dumpFile.close();

    delete m1;
    delete m2;
    delete m3;
}
