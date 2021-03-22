#ifndef RECEIPT_H
#define RECEIPT_H
#include <string>
#include <vector>


class Receipt
{
public:
    Receipt();
    std::vector<std::vector<std::string>> saveTriggerwords();
    std::vector<std::string> saveShops();
    std::string findKindOfShop();
    std::vector<std::vector<std::string>> calcExpenses;


private:
    std::vector<std::vector<std::string>> _vecProductCategory;
    std::vector<std::string> _vecShops;
    std::string _receiptShop;
    std::vector<std::vector<std::string>> _vecCategoryTotalPrice;
};

#endif // RECEIPT_H
