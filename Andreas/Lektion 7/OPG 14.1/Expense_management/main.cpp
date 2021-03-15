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
        std::cout << std::setw(20) << std::left << product;

        std::string category;
        std::getline(sline, category);
        std::cout << std::setw(20) << std::left << category << std::endl;

        std::vector<std::string> tempVec{product, category};
        productCategory.push_back(tempVec);
    }

    triggerStream.close();

    // std::string receiptName;
    // cout << "Enter receipt name: ";
    // std::cin >> receiptName;

    // std::string receipt("../" + receiptName + ".txt");
    std::string receipt("../netto.txt");
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

    for (size_t i = 0; i < vecShops.size(); i++)
    {
        cout << "Shop: " << vecShops[i] << std::endl;
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
theend:

    std::cout << "Receipt Shop: " << receiptShop << std::endl;
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
                std::cout << "---------" << std::setw(20) << std::left << item << std::endl;
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
            std::cout << "Item: " << receiptItems[i][0] << std::endl;
            std::cout << "Discount: " << receiptItems[i][1] << std::endl
                      << std::endl;
        }

        categoryStream.close();
        std::vector<std::string> tempVec{productCategory[0][1]};
        categorySumPrice.push_back(tempVec);
        for (size_t i = 1; i < productCategory.size(); i++)
        {
            for (size_t j = 0; j < categorySumPrice.size(); j++)
            {

                // if a category is not already in categorySumPrice
                if (!(categorySumPrice[j][0].compare(productCategory[i][1]) != 0))
                {
                    std::vector<std::string> tempVec{productCategory[i][0], 0};
                    categorySumPrice.push_back(tempVec);
                }
            }
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
            stringstream geek1(itemPriceString);
            double itemPrice = 0;
            geek1 >> itemPrice;

            std::string s = discountNameAndValue;
            std::string delimiter = "RABAT";
            s.erase(0, 0 + delimiter.length());
            delimiter = " ";

            size_t pos = 0;
            std::string token;
            while ((pos = s.find(delimiter)) != std::string::npos)
            {
                token = s.substr(0, pos);
                s.erase(0, pos + delimiter.length());
            }
            s.replace(s.find(","), 1, ".");
            stringstream geek2(s);
            double dicsountValue = 0;
            geek2 >> dicsountValue;

            double itemTotalPrice = itemPrice - dicsountValue;
            std::cout << "Item: " << item << std::endl;
            std::cout << "Item total price: " << itemTotalPrice << std::endl;

            for (size_t i = 0; i < productCategory.size(); i++)
            {
                if (item.find(productCategory[i][0]) != std::string::npos)
                {
                    for (size_t j = 0; j < categorySumPrice.size(); j++)
                    {
                        if (categorySumPrice[j][0].find(productCategory[j][1]) != std::string::npos)
                        {
                            categorySumPrice[j][1] = std::stod(categorySumPrice[j][1]) + itemTotalPrice;
                        }
                    }
                }
            }
        }
        std::cout << "/* message */" << std::endl;
        for (size_t i = 0; i < categorySumPrice.size(); i++)
        {
            std::cout << "Cat: " << categorySumPrice[i][0] << std::endl;
            std::cout << "Price: " << categorySumPrice[i][1] << std::endl;
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