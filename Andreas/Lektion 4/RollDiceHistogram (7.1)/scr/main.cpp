#include <iostream>
#include <ctime>
#include <array>
#include <random>

using namespace std;

int main(int argc, char const *argv[])
{

	const int n = 10000;
	int numDice = 5;

	double sum = 0;

	array<int, n> rolls{};
	array<int, 26> histogram{};

	default_random_engine engine{static_cast<unsigned int>(time(0))};
	uniform_int_distribution<unsigned int> random{1, 6};

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < numDice; j++)
		{
			int roll = random(engine);
			sum += roll;
			rolls[i] += roll;
		}
	}
	cout << "Gennemsnittet af alle omgange af " << n << " omgange totalt er: " << sum / n / static_cast<double>(numDice)
		 << ". Herunder er et histogram over de forskellige udkom:" << endl;

	for (size_t i = 0; i < rolls.size(); i++)
	{
		int shiftedIndex = rolls[i] - 5;
		histogram[shiftedIndex] += 1;
	}

	for (size_t i = 0, j = 5; i < histogram.size(); i++, j++)
	{
		cout << j << ": " << histogram[i] << endl;
	}

	return 0;
}
