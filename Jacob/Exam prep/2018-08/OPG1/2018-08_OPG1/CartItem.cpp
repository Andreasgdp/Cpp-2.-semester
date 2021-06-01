#include "CartItem.h"

CartItem::CartItem() {
    _item_no = "";
    _quantity = 0;
    _price = 0;
}

CartItem::CartItem(const std::string& item_no, int quantity) {
    _item_no = item_no;
    _quantity = quantity;
    _price = 0;
}

void CartItem::setItemNo(const std::string& item_no) {
    _item_no = item_no;
}

void CartItem::setQuantity(int qty) {
    _quantity = qty;
}

void CartItem::setPrice(double price) {
    _price = price;
}

const std::string& CartItem::getItemNo() const {
    return _item_no;
}

int CartItem::getQuantity() const {
    return _quantity;
}

double CartItem::getPrice() const {
    return _price;
}

double CartItem::getTotalPrice() const {
    return _quantity * _price;
}
