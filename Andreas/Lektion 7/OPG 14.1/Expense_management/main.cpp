#include <iostream>
#include <fstream>

using namespace std;

int main()
{
    std::string receiptName;
    cout << "Enter receipt name: ";
    std::cin >> receiptName;

    std::ifstream ifs;
    std::string receipt("../" + receiptName + ".txt");
    ifs.open(receipt);

    if (ifs.fail()) {
        std::cerr << "Failed to open receipt. Closing program." << std::endl;
        return 1;
    }

    ifs.close();
}
