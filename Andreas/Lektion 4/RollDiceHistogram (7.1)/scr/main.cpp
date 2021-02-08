#include <iostream>
#include <ctime>
#include <cstdlib>

using namespace std;

int main(int argc, char const *argv[])
{
	srand(time(NULL));

	double n;
	int numDice = 5;
	cout << "How many times do you want to simulate dice throw?: ";
	cin >> n;

	double sum = 0;

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < numDice; j++)
		{
			int roll = std::rand() % 6 + 1;
			sum += roll;
		}
		// cout << "Gennemsnittet af alle omgange er: " << sum[i] / static_cast<double>(numDice) << endl;
	}
	cout << "Gennemsnittet af alle omgange er: " << sum / n / static_cast<double>(numDice) << endl;

	return 0;
}
