#include <iostream>
#include <set>
#include <fstream>
#include <sstream>
#include <string>

using namespace std;

int main()
{
    std::ifstream ifs;
    std::string da("../da.wl");
    ifs.open(da);

    std::multiset<std::string, std::less<std::string>> dkdictionary;
    while (!ifs.eof()) {
        std::string line;
        std::getline(ifs, line);
        std::istringstream sline{line};

        // Skip empty lines
        if (line.size() == 0) {
            continue;
        }

        std::string word;
        std::getline(sline, word);

        dkdictionary.insert(word); // insert from files

        if (ifs.fail()) {
            ifs.clear(ifs.rdstate() & ~std::ios_base::failbit);
        }
    }
    ifs.close();

    std::string en("../en.wl");
    ifs.open(en);

    std::multiset<std::string, std::less<std::string>> endictionary;
    while (!ifs.eof()) {
        std::string line;
        std::getline(ifs, line);
        std::istringstream sline{line};

        // Skip empty lines
        if (line.size() == 0) {
            continue;
        }

        std::string word;
        std::getline(sline, word);

        endictionary.insert(word); // insert from files

        if (ifs.fail()) {
            ifs.clear(ifs.rdstate() & ~std::ios_base::failbit);
        }
    }
    ifs.close();

    std::string de("../de.wl");
    ifs.open(de);

    std::multiset<std::string, std::less<std::string>> dedictionary;
    while (!ifs.eof()) {
        std::string line;
        std::getline(ifs, line);
        std::istringstream sline{line};

        // Skip empty lines
        if (line.size() == 0) {
            continue;
        }

        std::string word;
        std::getline(sline, word);

        dedictionary.insert(word); // insert from files

        if (ifs.fail()) {
            ifs.clear(ifs.rdstate() & ~std::ios_base::failbit);
        }
    }
    ifs.close();

    /*
    // Print
    for (const std::string& elem : dictionary) {
        std::cout << elem << std::endl;
    }
    */

    // User input
    std::string inputString;
    cout << "Enter word to search for: ";
    std::cin >> inputString;

    int n = inputString.length();

    // Pick starting point
    for (int len = 1; len <= n; len++)
    {
        // Pick ending point
        for (int i = 0; i <= n - len; i++)
        {
            //  Print characters from current
            // starting point to current ending
            // point.
            std::string tmp = "";

            int j = i + len - 1;
            for (int k = i; k <= j; k++)
                tmp.push_back(inputString[k]);

            if (dkdictionary.find(tmp) != dkdictionary.end()) {
                std::cout << "Found " + tmp << " in DK dictionary!" << std::endl;
            } else {
                std::cout << "Could not find " + tmp << " in DK dictionary!" << std::endl;
            }

            if (endictionary.find(tmp) != endictionary.end()) {
                std::cout << "Found " + tmp << " in ENG dictionary!" << std::endl;
            } else {
                std::cout << "Could not find " + tmp << " in ENG dictionary!" << std::endl;
            }

            if (dedictionary.find(tmp) != dedictionary.end()) {
                std::cout << "Found " + tmp << " in DE dictionary!" << std::endl;
            } else {
                std::cout << "Could not find " + tmp << " in DE dictionary!" << std::endl;
            }
        }
    }

    return 0;
}

