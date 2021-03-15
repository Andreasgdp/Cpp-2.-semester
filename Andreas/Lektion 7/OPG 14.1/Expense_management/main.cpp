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
    std::vector<std::vector<std::string>> productCategory;
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
        productCategory.push_back(tempVec);
    }

    triggerStream.close();

    // std::string receiptName;
    // cout << "Enter receipt name: ";
    // std::cin >> receiptName;

    // std::string receipt("../" + receiptName + ".txt");
    std::string receipt("../nettoRename.txt");
    std::ifstream categoryStream;
    categoryStream.open(receipt);
    checkForFail();

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

    // Open receipt - Which receipt?
    std::ifstream receiptStream;
    receiptStream.open(receipt);
    checkForFail();

    // Find what kind of shop from shops.txt
    std::string receiptShop;
    while (!receiptStream.eof())
    {
        while (receiptStream >> receiptShop)
        {
            for (size_t i = 0; i < vecShops.size(); i++)
            {
                if (receiptShop.compare(vecShops[i]) == 0)
                {
                    receiptShop = vecShops[i];
                    goto theend;
                }
            }

            if (receiptStream.fail())
            {
                receiptStream.clear(receiptStream.rdstate() & ~std::ios_base::failbit);
            }
        }
    }
theend:;

    receiptStream.close();

    if (receiptShop.compare("NETTO") == 0)
    {
        std::vector<std::vector<std::string>> categorySumPrice;
        std::vector<std::vector<std::string>> receiptItems;
        bool firstPartRemoved = false;
        while (!categoryStream.eof())
        {
            if (categoryStream.fail())
            {
                categoryStream.clear(categoryStream.rdstate() & ~std::ios_base::failbit);
            }
            std::string line;
            std::getline(categoryStream, line);
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
                std::getline(categoryStream, line);
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

        categoryStream.close();
        std::vector<std::string> tempVec{productCategory[0][1]};
        categorySumPrice.push_back(tempVec);
        categorySumPrice[0].push_back("0");

        for (size_t i = 1; i < productCategory.size(); i++)
        {
            for (size_t j = 0; j < categorySumPrice.size(); j++)
            {
                // if a category is not already in categorySumPrice
                if (!(categorySumPrice[j][0].compare(productCategory[i][1]) == 0))
                {
                    std::vector<std::string> tempVec2{productCategory[i][1]};
                    categorySumPrice.push_back(tempVec2);
                    categorySumPrice[j + 1].push_back("0");
                    goto innerForLoop;
                }
            }
        innerForLoop:;
        }

        for (size_t i = 0; i < receiptItems.size(); i++)
        {
            std::string itemAndPrice = receiptItems[i][0];
            std::string discountNameAndValue = receiptItems[i][1];

            string alpha;
            for (int i = 0; i < itemAndPrice.length(); i++)
            {
                if ((itemAndPrice[i] >= 'A' && itemAndPrice[i] <= 'Z') ||
                    (itemAndPrice[i] >= 'a' && itemAndPrice[i] <= 'z') || itemAndPrice[i] == ' ')
                {
                    alpha.push_back(itemAndPrice[i]);
                }
            }

            std::string item = alpha;

            std::string itemPriceString = itemAndPrice.substr(itemAndPrice.find(",") - 2, 5);

            itemPriceString.replace(itemPriceString.find(","), 1, ".");
            double itemPrice = std::stod(itemPriceString);

            std::string s = discountNameAndValue.substr(discountNameAndValue.find(",") - 2, 5);
            s.replace(s.find(","), 1, ".");
            double dicsountValue = std::stod(s);

            double itemTotalPrice = itemPrice - dicsountValue;
            // std::cout << "Item: " << item << std::endl;
            // std::cout << "Item total price: " << itemTotalPrice << std::endl;

            for (size_t i = 0; i < productCategory.size(); i++)
            {
                if (item.find(productCategory[i][0]) != std::string::npos)
                {
                    for (size_t j = 0; j < categorySumPrice.size(); j++)
                    {
                        if (categorySumPrice[j][0].find(productCategory[i][1]) != std::string::npos)
                        {
                            categorySumPrice[j][1] = std::to_string(std::stod(categorySumPrice[j][1]) + itemTotalPrice);
                        }
                    }
                }
            }
        }
        for (size_t i = 0; i < categorySumPrice.size(); i++)
        {
            std::cout << "Category: " << categorySumPrice[i][0] << std::endl;
            std::cout << "Total Price: " << categorySumPrice[i][1] << std::endl;
        }
    }

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