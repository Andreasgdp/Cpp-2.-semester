#include "../Headers/Date.h"
#include <iostream>

using namespace std;

int main(int argc, char const *argv[])
{
	Date d(2020, 2, 8);
	cout << d.getDayOfWeek();

	return 0;
}
