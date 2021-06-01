#ifndef PRODUCT_H
#define PRODUCT_H
#include <iostream>


class Product
{
public:
    Product();
    Product(const char* name, double price);

    Product(const Product& p);
    Product(Product&& p);

    char *getName() const;
    void setName(char *name);

    double getPrice() const;
    void setPrice(double price);

    Product& operator=(const Product &rhs);
    Product& operator=(Product &&rhs);
    bool operator==(const Product &rhs);
    friend std::ostream& operator<<(std::ostream& out, const Product& p);

private:
    char *mName;
    double mPrice;
};

#endif // PRODUCT_H
