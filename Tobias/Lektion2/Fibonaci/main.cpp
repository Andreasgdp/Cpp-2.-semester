#include <iostream>

using namespace std;

int main()
{
    bool run = true;
    int weight, days;
    double F1,F2;
    double final;

    while (run) {
        cout << "Please input weight and amount of days: ";
        cin >> weight >> days;
        int rates = days/5;
        F1 = weight;
        F2 = 0;
        final = 0;
        for (int i = 0; i < rates ; i++ ) {

            final = (F1+F2);
            F2 = F1;
            F1 = final;
        }
        cout << "The green crud will weigh " << final << " pounds after " << days << " days" << endl;

        cout << "Do you want to continue? 1 for yes 0 for no: ";
        cin >> run;

    }
}
