#include <iostream>
#include <ctime>
#include <cstdlib>

using namespace std;

int main()
{
    srand(time(NULL));

    int n;
    std::cout << "Number of rolls?: ";
    std::cin >> n;

    double totalSum = 0;
    for (int i = 0; i < n; i++) {
        int sum = 0;
        for (int j = 0; j < 5; j++) {
            sum += std::rand() % 6 + 1;
        }
        totalSum += sum;
        cout << "Sum (Roll " << i + 1 << "): " << sum << endl;
    }

    cout << "Average (1 die): " << totalSum / n / 5 << endl;
    cout << "Average (5 dice): " << totalSum / n << endl;

    return 0;
}
