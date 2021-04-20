#include <iostream>
#include <set>
#include <fstream>
#include <sstream>
#include <string>
#include <iomanip>
#include <vector>
#include <algorithm>


using namespace std;

int main()
{

    std::multiset<std::string, std::less<std::string>> dkDictionary;
    std::ifstream strStream;
    std::string dkWords("../da.wl");
    strStream.open(dkWords);
    while (!strStream.eof())
    {
        std::string line;
        std::getline(strStream, line);
        std::istringstream sline{line};

        // Skip empty lines
        if (line.size() == 0)
        {
            continue;
        }

        std::string word;
        std::getline(sline, word);

        dkDictionary.insert(word); // insert from files
    }
    strStream.close();

    std::multiset<std::string, std::less<std::string>> enDictionary;
    std::string enWords("../en.wl");
    strStream.open(enWords);
    while (!strStream.eof())
    {
        std::string line;
        std::getline(strStream, line);
        std::istringstream sline{line};

        // Skip empty lines
        if (line.size() == 0)
        {
            continue;
        }

        std::string word;
        std::getline(sline, word);

        enDictionary.insert(word); // insert from files
    }
    strStream.close();

    std::multiset<std::string, std::less<std::string>> deDictionary;
    std::string deWords("../de.wl");
    strStream.open(deWords);
    while (!strStream.eof())
    {
        std::string line;
        std::getline(strStream, line);
        std::istringstream sline{line};

        // Skip empty lines
        if (line.size() == 0)
        {
            continue;
        }

        std::string word;
        std::getline(sline, word);

        deDictionary.insert(word); // insert from files
    }
    strStream.close();

    string input;
    cout << "Enter string to find in dictionary: ";
    std::cin >> input;
    int n = input.length();
    // Pick starting point
    for (int len = 1; len <= n; len++)
    {   
        // Pick ending point
        for (int i = 0; i <= n - len; i++)
        {
            std::string s = "";

            int j = i + len - 1;           
            for (int k = i; k <= j; k++)
                s.push_back(input[k]);

            if (dkDictionary.find(s) != dkDictionary.end()) {
                std::cout << "Found '" << s << "' in dkDictionary!" << std::endl;
            } else {
                std::cout << "Could not find '" << s << "'" << std::endl;
            }
            if (enDictionary.find(s) != enDictionary.end()) {
                std::cout << "Found '" << s << "' in enDictionary!" << std::endl;
            } else {
                std::cout << "Could not find '" << s << "'" << std::endl;
            }
            if (deDictionary.find(s) != deDictionary.end()) {
                std::cout << "Found '" << s << "' in deDictionary!" << std::endl;
            } else {
                std::cout << "Could not find '" << s << "'" << std::endl;
            }
            
        }
    }


    return 0;
}
