#include "Lot.h"
#include <iomanip>
#include <iostream>

Lot::Lot() {
    mAddress = "";
    mMinPrice = 0;
    mSize = 0;
}

Lot::Lot(const std::string& Address, double MinPrice, int Size) {
    mAddress = Address;
    mMinPrice = MinPrice;
    mSize = Size;
}

std::string Lot::getAddress() const {
    return mAddress;
}

void Lot::setAddress(const std::string &address) {
    mAddress = address;
}

double Lot::getMinimumPrice() const {
    return mMinPrice;
}

void Lot::setMinimumPrice(double minPrice) {
    mMinPrice = minPrice;
}

int Lot::getSize() const {
    return mSize;
}

void Lot::setSize(int size) {
    mSize = size;
}

std::ostream &operator<<(std::ostream& out, const Lot& l) {
    out << std::left << std::setw(20) << l.getAddress()
        << std::right << std::setw(9) << l.getMinimumPrice()
        << std::setw(6) << l.getSize();
    return out;
}

std::istream &operator>>(std::istream& in, Lot& l) {
    // Stendyssen 1;965430;703\n
    std::string address;
    getline(in, address, ';');
    //std::cout << "Address: " << address << "\t";
    l.mAddress = address;

    std::string minPrice;
    getline(in, minPrice, ';');
    //std::cout << "minPrice: " << minPrice << "\t";
    l.mMinPrice = std::stod(minPrice);

    std::string size;
    getline(in, size);
    //std::cout << "size: " << size << "\t" << std::endl;
    l.mSize = std::stoi(size);

    return in;
}
