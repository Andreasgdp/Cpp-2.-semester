#ifndef PRODUCTIONCALCULATOR_H
#define PRODUCTIONCALCULATOR_H
#include <iostream>
#include <vector>
#include "ExpenseItem.h"

class ProductionCalculator
{
public:
    ProductionCalculator();
    void readData(std::istream& is);
    double totalProductionCost();
    friend std::ostream& operator<<(std::ostream& out, const ProductionCalculator& p);
private:
    std::vector<ExpenseItem> _vecExpenseItem;
};

#endif // PRODUCTIONCALCULATOR_H
