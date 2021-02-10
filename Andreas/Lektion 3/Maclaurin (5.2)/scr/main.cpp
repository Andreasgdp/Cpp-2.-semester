#include "../Headers/Maclaurin.h"
#include <iostream>

using namespace std;

int main(int argc, char const *argv[])
{
	Maclaurin m(2, 20);

	cout << m.calcAproxOfEx();
	return 0;
}
