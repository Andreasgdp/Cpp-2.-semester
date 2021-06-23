#ifndef CART_H
#define CART_H
#include <string>
#include "CartItem.h"
#include <vector>

class Cart
{
public:
    Cart();
    Cart(const Cart& cart);
    void addItem(const CartItem& item);
    void removeItem(const std::string& item_no);
    double getTotalAmount() const;
    std::vector<CartItem> getItems() const;

private:
    std::vector<CartItem> _vecCartItem;
};

#endif // CART_H
