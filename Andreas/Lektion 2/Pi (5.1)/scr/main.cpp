#include "../Headers/Pi.h"
#include <iostream>

using namespace std;

int main(int argc, char const *argv[])
{
	Pi pi(100000);
	cout << pi.calcPi() << endl;
	return 0;
}
