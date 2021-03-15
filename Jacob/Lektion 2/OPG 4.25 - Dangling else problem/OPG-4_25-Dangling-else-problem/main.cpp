#include <iostream>

int main()
{
    // a)
    std::cout << "a)" << std::endl;
    int x = 5;
    int y = 9;

    if (y % 2) {
    if (x % 2) {
    std::cout << "XxXxX" << std::endl;
    } else {
    std::cout << "OxOxO" << std::endl;
    std::cout << "YyYyY" << std::endl;
    }
    std::cout << "-!-!-" << std::endl;
    }

    // b)
    std::cout << "\nb)" << std::endl;
    x = 5;
    y = 8;

    if (y % 2) {
    if (x % 2) {
    std::cout << "XxXxX" << std::endl;
    } else {
    }
    }
    std::cout << "OxOxO" << std::endl;
    std::cout << "YyYyY" << std::endl;
    std::cout << "-!-!-" << std::endl;

    // c)
    std::cout << "\nc)" << std::endl;

    x = 5;
    y = 9;

    if (y % 2) {
    if (x % 2) {
    std::cout << "XxXxX" << std::endl;
    } else {
    std::cout << "OxOxO" << std::endl;
    std::cout << "YyYyY" << std::endl;
    std::cout << "-!-!-" << std::endl;
    }
    }

    // d)
    std::cout << "\nd)" << std::endl;

    x = 5;
    y = 8;

    if (y % 2) {
    if (x % 2) {
    std::cout << "XxXxX" << std::endl;
    } else {
    std::cout << "OxOxO" << std::endl;
    std::cout << "YyYyY" << std::endl;
    }
    }
    std::cout << "-!-!-" << std::endl;

}
