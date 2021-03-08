#include <iostream>
#include <ctime>
#include <cstdlib>
#include <array>
#include <iomanip>

using namespace std;

int main() {
    srand(time(NULL));

    int n;
    std::cout << "Number of rolls?: ";
    std::cin >> n;

    array<int, 30> histogram{};
    histogram[30] = 0;

    double totalSum = 0;
    for (int i = 0; i < n; i++) {
        int sum = 0;
        for (int j = 0; j < 5; j++) {
            sum += std::rand() % 6 + 1;
        }
        histogram[sum] += 1;
        totalSum += sum;
        //cout << "Sum (Roll " << i + 1 << "): " << sum << endl;
    }

    cout << "Average (1 die): " << totalSum / n / 5 << endl;
    cout << "Average (5 dice): " << totalSum / n << endl << endl;

    // Find largest amount of same die throw
    int max = histogram[0];
    for (int i = 1; i <= 30; i++)
        if (histogram[i] > max)
            max = histogram[i];

    // Print histogram
    for(int i = max; i >= 1; i--) {
        cout << setw(3) << right << i;
        for(int j = 1; j <= 30; j++)
            if (histogram[j] < i) {
                cout << setw(3) << '.';
            } else {
                cout << setw(3) << '|';
        }
        cout << endl;
    }
    cout << "     ";
    for(int j = 1; j <= 30; j++) {
        cout << setw(3) << left << j;
    }

    cout << endl << endl;
    for (int i = 1; i <= 30; i++) {
        cout << i << ": " << histogram[i] << endl;
    }

    return 0;
}
