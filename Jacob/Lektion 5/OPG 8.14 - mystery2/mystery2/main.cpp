/*
 * Dette program tager en string som input. Denne bruges i funktionen mystery2() som parameter.
 * I funktioen laves en pointer til strengen. For-loopet løber igennem string1's pointer plus 1 så længe at
 * pointeren ikke peger på slutningen af string1. For hver gang for-loopet løber igennem lægges der 1 til variablen x.
 * Dermed tælles der hvor mange karaktere at der er i string1 før at slutningen (\0) nås.
 * Længden af string1 returneres og udskrives.
 */

// Ex. 8.14: ex08_14.cpp
// What does this program do?
#include <iostream>
using namespace std;

int mystery2(const char*); // prototype

int main() {
    char string1[80];

    cout << "Enter a string: ";
    cin >> string1;
    cout << mystery2(string1) << endl;
}

    // What does this function do?
    int mystery2(const char* s) {
        unsigned int x;

        for (x = 0; *s != '\0'; ++s) {
            ++x;
        }

        return x;
}
