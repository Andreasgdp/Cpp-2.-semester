#include <map>
#include <ctime>
#include <cstdlib>
#include <iostream>

int main(int argc, char const *argv[])
{
	const int simTimes = 1000000;

	srand(time(NULL));

	int doorPicked;

	int won = 0;
	int lost = 0;

	std::cout << "Do you want to keep door picked for this simulation? (0 for no, 1 for yes): ";
	bool selectFirstDoor;
	std::cin >> selectFirstDoor;

	for (int i = 0; i < simTimes; i++)
	{
		bool door[3] = {false, false, false};

		int winningDoor = (rand() % 3);
		door[winningDoor] = true;

		int doorPicked = (rand() % 3);

		if (door[doorPicked])
		{
			won += 1;
		}
		else if (selectFirstDoor)
		{
			lost += 1;
		}
		else
		{
			for (int j = 0; j < 3; j++)
			{
				if (door[j])
				{
					won += 1;
					break;
				}
				else if (j != doorPicked)
				{
					lost += 1;
					break;
				}
			}
		}
	}

	std::cout << "The simulation won " << (static_cast<double>(won) / simTimes) * 100 << "\% of the times times and lost " << (static_cast<double>(lost) / simTimes) * 100 << "\% of the times.";

	return 0;
}
