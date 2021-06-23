#ifndef EXPENSEITEM_H
#define EXPENSEITEM_H
#include <string>

class ExpenseItem
{
public:
    ExpenseItem();
    ExpenseItem(int id, int size, int amount, double price, std::string variant);

    int getId() const;
    void setId(int id);

    int getSize() const;
    void setSize(int size);

    int getAmount() const;
    void setAmount(int amount);

    double getPrice() const;
    void setPrice(double price);

    std::string getVariant() const;
    void setVariant(const std::string &variant);

    double getTotalPrice() const;

private:
    int _id, _size, _amount;
    double _price;
    std::string _variant;
};

#endif // EXPENSEITEM_H
