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
    std::ifstream triggerStream;
    std::string triggerWords("../triggerWords.txt");
    triggerStream.open(triggerWords);
    checkForFail();
    std::vector<std::vector<std::string>> triggerWordCategories;
    while (!triggerStream.eof())
    {
        std::string line;
        std::getline(triggerStream, line);
        std::istringstream sline{line};

        // Skip empty lines
        if (line.size() == 0)
        {
            continue;
        }

        std::string product;
        std::getline(sline, product, ';');

        std::string category;
        std::getline(sline, category);

        std::vector<std::string> tempVec{product, category};
        triggerWordCategories.push_back(tempVec);
    }

    triggerStream.close();

    std::vector<std::vector<std::string>> categorySumPrice;
    std::vector<std::string> tempVec{triggerWordCategories[0][1], "0"};
    categorySumPrice.push_back(tempVec);

    for (size_t i = 1; i < triggerWordCategories.size(); i++)
    {
        bool addNewCategory = false;
        for (size_t j = 0; j < categorySumPrice.size(); j++)
        {
            // if a category is not already in categorySumPrice
            if ((categorySumPrice[j][0].compare(triggerWordCategories[i][1]) == 0))
            {
                addNewCategory = false;
                break;
            }
            else
            {
                addNewCategory = true;
            }
        }
        if (addNewCategory)
        {
            std::vector<std::string> tempVec{triggerWordCategories[i][1], "0"};
            categorySumPrice.push_back(tempVec);
        }
    }

    // Open shops.txt
    std::string shops("../shops.txt");
    std::ifstream shopStream;
    shopStream.open(shops);
    checkForFail();

    // Save shops from shops.txt
    std::vector<std::string> vecShops;
    while (!shopStream.eof())
    {

        std::string line;
        std::getline(shopStream, line);
        std::istringstream sline{line};

        // Skip empty lines
        if (line.size() == 0)
        {
            continue;
        }

        std::string shop;
        std::getline(sline, shop);

        vecShops.push_back(shop);
    }

    // Close shops.txt
    shopStream.close();

    // std::string receiptName;
    // cout << "Enter receipt name (filename of receipt txt-file e.g. 'netto'): ";
    // std::cin >> receiptName;

    // std::string receipt("../" + receiptName + ".txt");
    // std::string receipt("../nettoRename.txt");
    std::string receipt("../rema1000.txt");
    std::ifstream categorySumStream;
    categorySumStream.open(receipt);
    checkForFail();

    // Open receipt - Which receipt?
    std::ifstream receiptShopStream;
    receiptShopStream.open(receipt);
    checkForFail();

    // Find what kind of shop from shops.txt
    std::string receiptShop;
    while (!receiptShopStream.eof())
    {
        while (receiptShopStream >> receiptShop)
        {
            for (size_t i = 0; i < vecShops.size(); i++)
            {
                if (receiptShop.compare(vecShops[i]) == 0)
                {
                    receiptShop = vecShops[i];
                    goto theend;
                }
            }

            if (receiptShopStream.fail())
            {
                receiptShopStream.clear(receiptShopStream.rdstate() & ~std::ios_base::failbit);
            }
        }
    }
theend:;

    receiptShopStream.close();

    if (receiptShop.compare("NETTO") == 0)
    {
        std::vector<std::vector<std::string>> receiptItems;
        bool firstPartRemoved = false;
        while (!categorySumStream.eof())
        {
            if (categorySumStream.fail())
            {
                categorySumStream.clear(categorySumStream.rdstate() & ~std::ios_base::failbit);
            }
            std::string line;
            std::getline(categorySumStream, line);
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
                std::getline(categorySumStream, line);
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

            for (size_t i = 0; i < triggerWordCategories.size(); i++)
            {
                if (itemAndPrice.find(triggerWordCategories[i][0]) != std::string::npos)
                {
                    for (size_t j = 0; j < categorySumPrice.size(); j++)
                    {
                        if (categorySumPrice[j][0].find(triggerWordCategories[i][1]) != std::string::npos)
                        {
                            categorySumPrice[j][1] = std::to_string(std::stod(categorySumPrice[j][1]) + itemTotalPrice);
                        }
                    }
                }
            }
        }
        std::cout << std::endl;
        for (size_t i = 0; i < categorySumPrice.size(); i++)
        {
            std::cout << "Category: '" << categorySumPrice[i][0] << "' with total Price: '" << categorySumPrice[i][1] << "'" << std::endl;
        }
    }
    else if (receiptShop.compare("REMA1000") == 0)
    {
        std::string matchingProduct;
        while (!categorySumStream.eof())
        {
            while (categorySumStream >> matchingProduct)
            {
                for (size_t i = 0; i < triggerWordCategories.size(); i++)
                {
                    if (matchingProduct.compare(triggerWordCategories[i][0]) == 0)
                    {
                        std::string line;
                        std::getline(categorySumStream, line);
                        std::istringstream sline{line};

                        // Skip empty lines
                        if (line.size() == 0)
                        {
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

                        for (size_t j = 0; j < categorySumPrice.size(); j++)
                        {
                            if (triggerWordCategories[i][1] == categorySumPrice[j][0])
                            {
                                categorySumPrice[j][1] = to_string(std::stod(categorySumPrice[j][1]) + price);
                            }
                        }
                    }
                }

                if (categorySumStream.fail())
                {
                    categorySumStream.clear(categorySumStream.rdstate() & ~std::ios_base::failbit);
                }
            }
        }

        for (size_t i = 0; i < categorySumPrice.size(); i++)
        {
            std::cout << "Category: '" << categorySumPrice[i][0] << "' with total Price: '" << categorySumPrice[i][1] << "'" << std::endl;
        }
    }

    categorySumStream.close();

    return 0;
}

int checkForFail()
{
    std::ifstream ifs;
    if (ifs.fail())
    {
        std::cerr << "Failed to open receipt. Closing program." << std::endl;
        return 1;
    }
    return 0;
}