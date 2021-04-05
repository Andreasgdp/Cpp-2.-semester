#include <Vector.h>
#include <iostream>
#include <sstream>

using namespace std;

int main()
{
    Vector v1(3);
    Vector v2(v1);
    Vector v3(4);

    cout << "v1: " << v1 << endl;
    cout << "v2: " << v2 << endl;
    cout << "v3: " << v3 << endl;

    string s1 = "1 2 3";
    string s3 = "4 5 6 7";
    istringstream iss1(s1);
    istringstream iss3(s3);
    iss1 >> v1;
    v2 = v1;
    iss3 >> v3;

    cout << "v1: " << v1 << endl;
    cout << "v2: " << v2 << endl;
    cout << "v3: " << v3 << endl;

    cout << "v1 == v2: " << (v1 == v2) << endl;
    cout << "v1 == v3: " << (v1 == v3) << endl;
    cout << "v3 == v1: " << (v3 == v1) << endl;

    cout << "v1 != v2: " << (v1 != v2) << endl;
    cout << "v1 != v3: " << (v1 != v3) << endl;
    cout << "v3 != v1: " << (v3 != v1) << endl;

    // Memory probelem? - Delete memory?
    cout << "v1 + v2: " << (v1 + v2) << endl;
    cout << "v1 + v3: " << (v1 + v3) << endl; // Returns vector size of 3

    cout << "v1 - v2: " << (v1 - v2) << endl;
    cout << "v1 - v3: " << (v1 - v3) << endl; // Returns vector size of 3

    cout << "v1 += v2: " << (v1 += v2) << endl;
    cout << "v1 += v3: " << (v1 += v3) << endl; // ?

    cout << "v1 -= v2: " << (v1 -= v2) << endl;
    cout << "v1 -= v3: " << (v1 -= v3) << endl; // ?

    cout << "dot(v1, v2): " << dot(v1, v2) << endl;
    cout << "dot(v1, v3): " << dot(v1, v3) << endl;

    return 0;
}
