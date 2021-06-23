#include <iostream>
#include "Cart.h"

int main()
{
    CartItem ci1("271845", 15);
    ci1.setPrice(20);
    CartItem ci2, ci3, ci4, ci5;
    ci2.setItemNo("183416");
    ci2.setQuantity(15);
    ci2.setPrice(15.251);
    ci4.setItemNo("12345");
    ci5.setItemNo("18no2p1");
    ci5.setQuantity(10);
    CartItem ci6("18no2p2", 19);
    CartItem ci7(ci2);
    ci7.setQuantity(3);
    Cart c;
    c.addItem(ci1);
    c.addItem(ci2);
    c.addItem(ci3);
    c.addItem(ci4);
    c.addItem(ci5);
    c.addItem(ci6);
    c.addItem(ci7);
    c.removeItem("12345");
    std::vector<CartItem> cis = c.getItems();
    std::cout.width(8);
    std::cout << "Antal" << " ";
    std::cout.width(10); std::cout << "Varenr." << " ";
    std::cout.width(8); std::cout << "Pris" << " ";
    std::cout.width(12); std::cout << "Total" << std::endl;
    std::cout.setf(std::ios::fixed);
    std::cout.setf(std::ios::showpoint);
    std::cout.precision(2);
    for (unsigned int i = 0; i < cis.size(); ++i) {
    std::cout.width(8); std::cout << cis[i].getQuantity() << " ";
    std::cout.width(10); std::cout << cis[i].getItemNo() << " ";
    std::cout.width(8); std::cout << cis[i].getPrice() << " ";
    std::cout.width(12); std::cout << cis[i].getTotalPrice() << std::endl;
    }
    std::cout << std::endl << "Total amount " << c.getTotalAmount() << std::endl << std::endl;
}
