#include <iostream>
#include <cmath>

#include "QuadraticEquation.h"
using namespace std;

int main()
{
    bool s = true;
    while (s == true){
        double a, b, c, dis;
        cout << "Please enter a,b and c: ";
        cin >> a >> b >> c;
        dis = b*b - 4*a*c;


        if (dis >= 0){
            double solve1 = (-b + sqrt(b*b - 4*a*c))/ 2*a;
            double solve2 = (-b - sqrt(b*b - 4*a*c))/ 2*a;
            cout <<"Root one is: " << solve1 << " Root 2 is: "<< solve2 << endl;
        }
        else {
            double real = -b/ (2*a);
            double img  = sqrt(-dis)/(2*a);
            cout << "Roots are complex. " <<"The real part is: " << real <<" and the imaginary part is: " << img << endl;
        }
        cout << "Do you want to continue? 1 for yes 0 for no: ";
        cin >> s;
    }
    return 0;
}
