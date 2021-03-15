#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <iomanip>
#include <vector>
#include <algorithm>

using namespace std;

int checkForFail();

int main()
{
    // Open tiggerWords.txt
    std::ifstream ifs;
    std::string triggerWords("../triggerWords.txt");
    ifs.open(triggerWords);
    checkForFail();

    // Save produkt and category from tiggerWords.txt
    std::vector<std::vector<std::string>> vecProductCategory;
    while (!ifs.eof()) {
        std::string line;
        std::getline(ifs, line);
        std::istringstream sline{line};

        // Skip empty lines
        if (line.size() == 0) {
            continue;
        }

        std::string product;
        std::getline(sline, product, ';');

        std::string category;
        std::getline(sline, category);

        std::vector<std::string> secondVec{product, category};
        vecProductCategory.push_back(secondVec);


        if (ifs.fail()) {
            ifs.clear(ifs.rdstate() & ~std::ios_base::failbit);
        }
    }

    for (size_t i = 0; i < vecProductCategory.size(); i++) {
      cout << "Product: " << setw(10) << vecProductCategory[i][0] << "\t";
      cout << "Category: " << vecProductCategory[i][1] << std::endl;
    }

    // Close tiggerWords.txt
    ifs.close();


    // Open shops.txt
    std::string shops("../shops.txt");
    ifs.open(shops);
    checkForFail();

    // Save shops from shops.txt
    std::vector<std::string> vecShops;
    while (!ifs.eof()) {

        std::string line;
        std::getline(ifs, line);
        std::istringstream sline{line};

        // Skip empty lines
        if (line.size() == 0) {
            continue;
        }

        std::string shop;
        std::getline(sline, shop);

        vecShops.push_back(shop);
    }

    for (size_t i = 0; i < vecShops.size(); i++) {
      cout << "Shop: " << vecShops[i] << std::endl;
    }

    // Close shops.txt
    ifs.close();


    // Open receipt - Which receipt?
    std::string receiptName;
    cout << "Enter receipt name: ";
    std::cin >> receiptName;

    std::string receipt("../" + receiptName + ".txt");
    ifs.open(receipt);
    checkForFail();

    // Find what kind of shop from shops.txt
    std::string receiptShop;
    while (!ifs.eof()) {
        while (ifs >> receiptShop) {
            for (size_t i = 0; i < vecShops.size(); i++) {
              if (receiptShop.compare(vecShops[i]) == 0) {
                  receiptShop = vecShops[i];
                  goto theend;
              }
            }

            if (ifs.fail()) {
                ifs.clear(ifs.rdstate() & ~std::ios_base::failbit);
            }
        }
    }
    theend:

    std::cout << "Receipt Shop: " << receiptShop << std::endl;

    ifs.close();

    ifs.open(receipt);
    checkForFail();

    // Add distinct categories to new vec with categories and total price
    std::vector<std::vector<std::string>> vecCategoryTotalPrice;
    std::vector<std::string> secondVec{vecProductCategory[0][1], "0"};
    vecCategoryTotalPrice.push_back(secondVec);
    for (size_t i = 1; i < vecProductCategory.size(); i++) {
        bool addNewCategory = false;
        for (size_t j = 0; j < vecCategoryTotalPrice.size(); j++) {
            if (vecCategoryTotalPrice[j][0].compare(vecProductCategory[i][1]) == 0) {
                addNewCategory = false;
                break;
            } else {
                addNewCategory = true;
            }
        }
        if (addNewCategory) {
            std::vector<std::string> innerVec{vecProductCategory[i][1], "0"};
            vecCategoryTotalPrice.push_back(innerVec);
        }
    }


    // Calc expenses into categories depending on shop
    std::string matchingProduct;
    if (receiptShop.compare("REMA1000") == 0) {
        while (!ifs.eof()) {
            while (ifs >> matchingProduct) {
                for (size_t i = 0; i < vecProductCategory.size(); i++) {
                  if (matchingProduct.compare(vecProductCategory[i][0]) == 0) {
                      cout << "Matching product: " << matchingProduct << std::endl;

                      std::string line;
                      std::getline(ifs, line);
                      std::istringstream sline{line};

                      // Skip empty lines
                      if (line.size() == 0) {
                          continue;
                      }

                      // Get amount and price
                      std::string int1;
                      std::getline(sline, int1, ',');
                      int1.erase(std::remove(int1.begin(), int1.end(), ' '), int1.end());

                      std::string int2;
                      std::getline(sline, int2, ' ');
                      int2.erase(std::remove(int2.begin(), int2.end(), ' '), int2.end());

                      std::string int3;
                      std::getline(sline, int3, ',');
                      int3.erase(std::remove(int3.begin(), int3.end(), ' '), int3.end());

                      std::string int4;
                      std::getline(sline, int4);
                      int4.erase(std::remove(int4.begin(), int4.end(), ' '), int4.end());

                      double amount = std::stod(int1) + (std::stod(int2) / 100);
                      double price = std::stod(int3) + (std::stod(int4) / 100);

                      cout << "Amount: " << amount << std::endl;
                      cout << "Price: " << price << std::endl;

                      for (size_t j = 0; j < vecCategoryTotalPrice.size(); j++) {
                          if (vecProductCategory[i][1] == vecCategoryTotalPrice[j][0]) {
                              vecCategoryTotalPrice[j][1] = to_string(std::stod(vecCategoryTotalPrice[j][1]) + price);
                          }
                      }
                  }
                }

                if (ifs.fail()) {
                    ifs.clear(ifs.rdstate() & ~std::ios_base::failbit);
                }

            }
        }

        for (size_t i = 0; i < vecCategoryTotalPrice.size(); i++) {
            cout << "Category: " << vecCategoryTotalPrice[i][0] << std::endl;
            cout << "Price: " << vecCategoryTotalPrice[i][1] << std::endl;
        }
    }

    if (receiptShop.compare("NETTO") == 0)
        {
            std::vector<std::vector<std::string>> receiptItems;
            bool firstPartRemoved = false;
            while (!ifs.eof())
            {
                if (ifs.fail())
                {
                    ifs.clear(ifs.rdstate() & ~std::ios_base::failbit);
                }

                std::string line;
                std::getline(ifs, line);
                std::istringstream sline{line};

                // Skip empty lines
                if (line.size() == 0)
                {
                    continue;
                }

                if (!firstPartRemoved)
                {
                    std::string item;
                    std::getline(sline, item, '.');
                    std::string line;
                    std::getline(ifs, line);
                    std::istringstream sline{line};
                    firstPartRemoved = true;
                }
                else
                {
                    // Skip empty lines
                    if (line.size() == 0)
                    {
                        continue;
                    }

                    std::string item;
                    std::getline(sline, item, '-');
                    if (item.find("RABAT") != string::npos)
                    {
                        receiptItems[receiptItems.size() - 1].push_back(item);
                    }
                    else if (item.find("TOTAL") != string::npos)
                    {
                        break;
                    }
                    else
                    {
                        std::vector<std::string> tempVec{item};
                        receiptItems.push_back(tempVec);
                    }
                }
            }


            for (size_t i = 0; i < receiptItems.size(); i++)
            {
                std::string itemAndPrice = receiptItems[i][0];
                std::string discountNameAndValue = receiptItems[i][1];

                std::string tempString = itemAndPrice.substr(itemAndPrice.find(",") - 2, 5);
                tempString.replace(tempString.find(","), 1, ".");
                double itemPrice = std::stod(tempString);

                tempString = discountNameAndValue.substr(discountNameAndValue.find(",") - 2, 5);
                tempString.replace(tempString.find(","), 1, ".");
                double dicsountValue = std::stod(tempString);

                double itemTotalPrice = itemPrice - dicsountValue;

                for (size_t i = 0; i < vecProductCategory.size(); i++)
                {
                    if (itemAndPrice.find(vecProductCategory[i][0]) != std::string::npos)
                    {
                        for (size_t j = 0; j < vecCategoryTotalPrice.size(); j++)
                        {
                            if (vecCategoryTotalPrice[j][0].find(vecProductCategory[i][1]) != std::string::npos)
                            {
                                vecCategoryTotalPrice[j][1] = std::to_string(std::stod(vecCategoryTotalPrice[j][1]) + itemTotalPrice);
                            }
                        }
                    }
                }
            }
            std::cout << std::endl;
            for (size_t i = 0; i < vecCategoryTotalPrice.size(); i++)
            {
                std::cout << "Category: '" << vecCategoryTotalPrice[i][0] << "' with total Price: '" << vecCategoryTotalPrice[i][1] << "'" << std::endl;
            }
        }

    // Close receipt
    ifs.close();

    return 0;
}

int checkForFail() {
    std::ifstream ifs;
    if (ifs.fail()) {
        std::cerr << "Failed to open receipt. Closing program." << std::endl;
        return 1;
    }
    return 0;
}
