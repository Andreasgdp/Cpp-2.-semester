#include <iostream>
#include "ProductionCalculator.h"
#include <sstream>

using namespace std;

int main()
{
    ProductionCalculator pc;
    std::stringstream ss("2012ad,15#15EUR0.01\n17625ac,20#10EUR0.25\n2182af,17#20EUR1.25\n8121ad,17#35EUR2.5\n51221adf,21#32EUR2.1\n24221acf,11#16EUR21.1");
    pc.readData(ss);
    std::cout << pc << std::endl;
    std::cout << "Total production cost: " << pc.totalProductionCost() <<
    std::endl;
}
