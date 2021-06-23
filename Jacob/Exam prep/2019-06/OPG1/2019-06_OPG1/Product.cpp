#include "Product.h"
#include <cstring>
#include <algorithm>

Product::Product() {
    mName = new char[1];
    mName[0] = '\0';
    mPrice = 0;
}

Product::Product(const char *name, double price) {
    unsigned int length = strlen(name);
    mName = new char[length];
    strcpy(mName, name);

    mPrice = price;
}

Product::Product(const Product &p) {
    unsigned int length = strlen(p.mName);
    mName = new char[length];
    strcpy(mName, p.mName);

    mPrice = p.mPrice;
}

Product::Product(Product &&p) {
    mPrice = std::move(p.mPrice);
    mName = std::move(p.mName);
/*
    mPrice = p.mPrice;
    mName = p.mName;

    // Make data valid for moved object
    p.mName = new char[1];
    p.mName[0] = '\0';
    p.mPrice = 0;
*/
}

char *Product::getName() const {
    return mName;
}

void Product::setName(char *name) {
    mName = name;
}

double Product::getPrice() const {
    return mPrice;
}

void Product::setPrice(double price) {
    mPrice = price;
}

Product &Product::operator=(const Product &rhs) {
    delete[] mName;
    unsigned int length = strlen(rhs.mName);
    mName = new char[length];
    strcpy(mName, rhs.mName);

    mPrice = rhs.mPrice;

    return *this;
}

Product &Product::operator=(Product &&rhs) {
    delete[] mName;
    unsigned int length = strlen(rhs.mName);
    mName = new char[length];
    strcpy(mName, rhs.mName);

    mPrice = rhs.mPrice;

    delete[] rhs.mName;
    rhs.mPrice = NULL;

    return *this;
}

bool Product::operator==(const Product &rhs) {
    if (strcmp(mName, rhs.mName) == 0 && mPrice == rhs.mPrice) {
        return true;
    } else {
        return false;
    }
}

std::ostream &operator<<(std::ostream& out, const Product& p) {
    out << "Product Name: " << p.getName() << "\tPrice: " << p.getPrice();
    return out;
}
