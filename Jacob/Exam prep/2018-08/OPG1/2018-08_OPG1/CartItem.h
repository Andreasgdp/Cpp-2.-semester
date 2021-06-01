#ifndef CARTITEM_H
#define CARTITEM_H
#include <string>

class CartItem {
public:
    CartItem();
    CartItem(const std::string& item_no, int quantity);
    void setItemNo(const std::string& item_no);
    void setQuantity(int qty);
    void setPrice(double price);
    const std::string& getItemNo() const;
    int getQuantity() const;
    double getPrice() const;
    double getTotalPrice() const;

private:
    std::string _item_no;
    int _quantity;
    double _price;
};

#endif // CARTITEM_H
