#include <iostream>
#include <BasicTicket.h>
#include <FloorTicket.h>

using namespace std;

int main()
{
    BasicTicket b1;
    b1.setPrice(99.95);
    cout << "b1: " << b1.getPrice() << endl;

    FloorTicket f1;
    cout << "f1: " << f1.getPrice() << endl;


    return 0;
}
