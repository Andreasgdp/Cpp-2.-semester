#include <cstdio>
#include <iostream>

using namespace std;

int main()
{
    // A)
    cout << "A\n" << endl;

    int y = 9;
    int x = 5;

    if (y % 2) {
    if (x % 2) {
    cout << "XxXxX" << endl;
    }
    else {
    cout << "OxOxO" << endl;
    cout << "YyYyY" << endl;
    }
    cout << "-!-!-" << endl;
    }
    
    // B)
    cout << "B\n" << endl;
    y = 8;
    x = 5;

    if (y % 2){
    if (x % 2) {
    cout << "XxXxX" << endl;
    }
    }
    else {}
    cout << "OxOxO" << endl;
    cout << "YyYyY" << endl;
    cout << "-!-!-" << endl;

    // C)
    cout << "C\n" << endl;
    y = 9;
    x = 5;

    if (y % 2) {
    if (x % 2) {
    cout << "XxXxX" << endl;
    }
    }
    else {
    cout << "OxOxO" << endl;
    cout << "YyYyY" << endl;
    cout << "-!-!-" << endl;
    }

    // D)
    cout << "D\n" << endl;
    y = 8;
    x = 5;

    if (y % 2) {
    if (x % 2) {
    cout << "XxXxX" << endl;
    }
    else {
    cout << "OxOxO" << endl;
    cout << "YyYyY" << endl;
    }
    }
    cout << "-!-!-" << endl;



    return 0;
}