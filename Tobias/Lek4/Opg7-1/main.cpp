#include <iostream>
#include <cstdlib>
#include <ctime>
#include <array>
#include <iomanip>

using namespace std;

int main()
{
    srand(time(NULL));

    int n;
    cout << "Please insert number of rools: ";
    cin >> n;
    double nSum = 0;
    array<int, 30> histogram{};
    histogram[30] = 0;
    for (int i = 0; i < n; i++) {
        int r1, r2, r3, r4, r5;
        r1 = rand() % 6 +1;
        r2 = rand() % 6 +1;
        r3 = rand() % 6 +1;
        r4 = rand() % 6 +1;
        r5 = rand() % 6 +1;
        double sum = r1+r2+r3+r4+r5;
        histogram[sum] += 1;
    }
    //finding max
    int max = histogram[0];
    for (int i = 1; i <= 30; i++)
        if (histogram[i] > max)
            max = histogram[i];
    //printing
    for(int i = max; i >= 1; i--) {
        cout << setw(3) << right << i;
        for(int j = 1; j <= 30; j++)
            if (histogram[j] < i) {
                cout << setw(3) << ' ';
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

    return 0;
}
