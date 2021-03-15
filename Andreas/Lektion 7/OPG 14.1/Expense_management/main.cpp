#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <iomanip>
#include <vector>

using namespace std;

int checkForFail();

int main()
{
    std::ifstream ifs;
    std::string triggerWords("../triggerWords.txt");
    ifs.open(triggerWords);
    checkForFail();
    std::vector<std::vector<std::string>> productCategory;
    while (!ifs.eof())
    {
        std::string line;
        std::getline(ifs, line);
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
        std::getline(sline, category, ';');
        std::cout << std::setw(20) << std::left << category << std::endl;

        std::vector<std::string> tempVec{product, category};
        productCategory.push_back(tempVec);
    }

    
    ifs.close();

    std::string receiptName;
    cout << "Enter receipt name: ";
    std::cin >> receiptName;

    std::string receipt("../" + receiptName + ".txt");
    ifs.open(receipt);
    checkForFail();

    /*
    while (!ifs.eof()) {


        if (ifs.fail()) {
            ifs.clear(ifs.rdstate() & ~std::ios_base::failbit);
        }
    }
    */

    ifs.close();

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