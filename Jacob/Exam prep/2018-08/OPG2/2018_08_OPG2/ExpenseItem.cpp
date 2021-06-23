#include "ExpenseItem.h"

ExpenseItem::ExpenseItem() {
    _id = 0;
    _size = 0;
    _amount = 0;
    _price = 0;
    _variant = "";
}

ExpenseItem::ExpenseItem(int id, int size, int amount, double price, std::string variant) {
    _id = id;
    _size = size;
    _amount = amount;
    _price = price;
    _variant = variant;
}

int ExpenseItem::getId() const {
    return _id;
}

void ExpenseItem::setId(int id) {
    _id = id;
}

int ExpenseItem::getSize() const {
    return _size;
}

void ExpenseItem::setSize(int size) {
    _size = size;
}

int ExpenseItem::getAmount() const {
    return _amount;
}

void ExpenseItem::setAmount(int amount) {
    _amount = amount;
}

double ExpenseItem::getPrice() const {
    return _price;
}

void ExpenseItem::setPrice(double price) {
    _price = price;
}

std::string ExpenseItem::getVariant() const {
    return _variant;
}

void ExpenseItem::setVariant(const std::string &variant) {
    _variant = variant;
}

double ExpenseItem::getTotalPrice() const {
    return _amount * _price;
}
