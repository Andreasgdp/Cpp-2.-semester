#include "Cart.h"
#include <iostream>

Cart::Cart() {}

Cart::Cart(const Cart &cart) {
    _vecCartItem = cart._vecCartItem;
}

void Cart::addItem(const CartItem &item) {
    if (item.getQuantity() == 0) {
        return;
    }

    bool notfound = true;
    for (size_t i = 0; i < _vecCartItem.size(); i++) {
        if (_vecCartItem[i].getItemNo() == item.getItemNo()) {
            _vecCartItem[i].setQuantity(_vecCartItem[i].getQuantity() + item.getQuantity());
            notfound = false;
            break;
        } else {
            notfound = true;
        }
    }

    if (notfound) {
        _vecCartItem.push_back(item);
    }
}

void Cart::removeItem(const std::string &item_no) {
    for (size_t i = 0; i < _vecCartItem.size(); i++) {
        if (_vecCartItem[i].getItemNo() == item_no) {
            _vecCartItem.erase(_vecCartItem.begin() + i);
            break;
        }
    }
}

double Cart::getTotalAmount() const {
    double total = 0;
    for (size_t i = 0; i < _vecCartItem.size(); i++) {
        total +=_vecCartItem[i].getTotalPrice();
    }
    return total;
}

std::vector<CartItem> Cart::getItems() const {
    return _vecCartItem;
}
