
#include "product.h"
#include <iostream>
#include <string>
#include <set>
#include <vector>
#include <algorithm>

class Movie : public Product {
public:
    Movie(const std::string& category, const std::string& name, double price, int qty,
           const std::string& genre, const std::string& rating);
    virtual ~Movie();

    /**
     * Returns the appropriate keywords that this product should be associated with
     */
    virtual std::set<std::string> keywords() const override;

    /**
     * Returns a string to display the product info for hits of the search
     */
    virtual std::string displayString() const override;

    /**
     * Outputs the product info in the database format
     */
    virtual void dump(std::ostream& os) const override;

private:
    std::string genre_;
    std::string rating_;
};
