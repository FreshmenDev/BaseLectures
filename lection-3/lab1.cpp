#include <iostream>
#include <string>
#include <cmath>

int main() {
	const int NEWS_COUNT = 10;
	const double RADIUS = 10.0;

	char* news[] = {
		"Fire",
		"Flood",
		"Asteroid",
		"City Day",
		"Asteroid",
		"Birthday",
		"Teachers Day",
		"New Year",
		"Christmas",
		"Easter"
	};

	float lats[] = {
		45.5,
		48.6,
		58.6,
		60.6,
		54.6,
		55.1,
		62.6,
		60.9,
		47.6,
		57.4
	};

	float lons[] = {
		40.5,
		47.6,
		56.6,
		43.6,
		54.6,
		55.1,
		62.6,
		60.9,
		47.6,
		57.4
	};

	int indexes[NEWS_COUNT];
	for (int i = 0; i<NEWS_COUNT; i++)
		indexes[i] = -1;

	std::cout << "News in your region:" << std::endl << std::endl;

	float myLat, myLon;

	std::cout << "Enter your position" << std::endl;

	std::cin >> myLat >> myLon;

	bool hasNews = false;

	for (int t = 0; t<NEWS_COUNT; t++)
	{
		for (int i = 0; i < NEWS_COUNT; i++) {
			int min = 9999999;
			double distance = std::sqrt(std::pow((myLat - lats[i]), 2) + std::pow((myLon - lons[i]), 2));
			if (distance < RADIUS)
			{
				if (distance < min)
				{
					bool was = false;
					for (int j = 0; j < NEWS_COUNT; j++)
					{
						if (indexes[j] == i)
						{
							was = true;
							break;
						}
					}
					if (!was)
					{
						min = distance;
						indexes[t] = i;
					}
				}
			}
		}
	}

	for (int i = 0; i < NEWS_COUNT; i++) {
		if (indexes[i] != -1)
		{
			std::cout << news[indexes[i]]<<std::endl;
			hasNews = true;
		}
	}

	if (hasNews) {
		std::cout << "I hope, I helped you" << std::endl;
	}
	else {
		std::cout << "Sorry, there are no news (((" << std::endl;
	}
	std::cin.get();
	std::cin.get();
}

