#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

int main()
{
    srand(time(NULL));

    int n;
    cout << "Please insert number of rools: ";
    cin >> n;
    double nSum = 0;
    for (int i = 0; i < n; i++) {
           int r1, r2, r3, r4, r5;
           r1 = rand() % 6 +1;
           r2 = rand() % 6 +1;
           r3 = rand() % 6 +1;
           r4 = rand() % 6 +1;
           r5 = rand() % 6 +1;
           double sum = r1+r2+r3+r4+r5;
           //cout <<"The sum of the 5 dice: "<< sum << endl;
           //cout <<"The average is: " << sum/5 << endl;
           nSum += sum;
    }
    cout << "The average is: " << nSum/5/n << endl;
}
