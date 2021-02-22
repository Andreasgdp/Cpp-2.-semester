#include "../Headers/Date.h"
#include <iostream>

using namespace std;

int main(int argc, char const *argv[])
{
	Date d(2021, 2, 16);
	cout << d.getDayOfWeek();

	return 0;
}
