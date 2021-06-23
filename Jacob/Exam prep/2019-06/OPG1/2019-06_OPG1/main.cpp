#include <iostream>
#include "Product.h"

int main()
{
    std::cout << "--------------------" << std::endl;
    std::cout << "-- Test Opgave 1a --" << std::endl;
    std::cout << "--------------------" << std::endl;
    char productname[] = "Product 1";
    Product p1(productname, 15.1);
    Product p2;
    productname[8] = '2';
    p2.setName(productname);
    p2.setPrice(30.2);
    Product p3;
    p3.setName("Product 3");
    p3.setPrice(10.3);
    Product p4("Product 4", 14.4);
    Product p5(p4);
    Product p6(std::move(p3));
    std::cout << "Product name | Price" << std::endl;
    std::cout << p1.getName() << " " << p1.getPrice() << std::endl;
    std::cout << p2.getName() << " " << p2.getPrice() << std::endl;
    std::cout << p3.getName() << " " << p3.getPrice() << std::endl;
    std::cout << p4.getName() << " " << p4.getPrice() << std::endl;
    std::cout << p5.getName() << " " << p5.getPrice() << std::endl;
    std::cout << p6.getName() << " " << p6.getPrice() << std::endl;
    std::cout << std::endl;

    std::cout << "--------------------" << std::endl;
    std::cout << "-- Test Opgave 1b --" << std::endl;
    std::cout << "--------------------" << std::endl;
    Product p7("Product 7", 14.7);
    Product p8;
    p8 = p7;
    p5 = std::move(p4);
    bool p7ep8 = (p7==p8);
    bool p6ep2 = (p6==p2);
    std::cout << "Product name | Price" << std::endl;
    std::cout << p2.getName() << " " << p2.getPrice() << std::endl;
    std::cout << p5.getName() << " " << p5.getPrice() << std::endl;
    std::cout << p7.getName() << " " << p7.getPrice() << std::endl;
    std::cout << p8.getName() << " " << p8.getPrice() << std::endl;
    std::cout << std::boolalpha << p7ep8 << std::endl;
    std::cout << std::boolalpha << p6ep2 << std::endl;
    std::cout << p8 << std::endl;
    std::cout << std::endl;
}
