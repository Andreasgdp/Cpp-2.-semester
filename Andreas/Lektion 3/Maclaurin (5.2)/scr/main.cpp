#include "../Headers/Maclaurin.h"
#include <iostream>

using namespace std;

int main(int argc, char const *argv[])
{
	Maclaurin m(13, 100);

	cout << m.calcAproxOfEx();
	return 0;
}
