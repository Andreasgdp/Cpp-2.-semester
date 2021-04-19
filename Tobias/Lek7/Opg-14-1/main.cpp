#include <iostream>
#include <fstream>
#include <iomanip>
#include <array>

using namespace std;

int main()
{
    std::array<std::string, 3> names{"Hans", "Preben", "Thomas"};

    std::ofstream ofs;
    std::string file = "../Opg-14-1/out.txt";
    ofs.open(file);

    if (ofs.fail()) {
        cerr << "Failed to open " << file << endl;
        return 1;
    }

    for (size_t i = 0; i < names.size() ; i++ ) {
        cout << names[i] << endl;
        ofs << names[i] << endl;
    }

    ofs.close();
    return 0;
}
