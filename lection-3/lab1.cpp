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

	float result[NEWS_COUNT];


	std::cout << "News in your region:" << std::endl << std::endl;

	float myLat, myLon;

	std::cout << "Enter your position" << std::endl;

	std::cin >> myLat >> myLon;
	std::cin.ignore();

	bool hasNews = false;

	for (int i = 0; i < NEWS_COUNT; i++)
	{
		double distance = std::sqrt(std::pow((myLat - lats[i]), 2) + std::pow((myLon - lons[i]), 2));
		result[i] = distance;
	}

	float temp = 0;
	// Сортировка массива пузырьком
	for (int i = 0; i < NEWS_COUNT; i++)
	{
		double distance = std::sqrt(std::pow((myLat - lats[i]), 2) + std::pow((myLon - lons[i]), 2));
		for (int j = 0; j < NEWS_COUNT - i - 1; j++)
		{
			if (result[j] > result[j + 1])
			{
				temp = result[j];
				result[j] = result[j + 1];
				result[j + 1] = temp;
			}
		}
	}

	for (int i = 0; i < NEWS_COUNT; i++)
	{
		for (int j = 0; j < NEWS_COUNT; j++)
		{
			double distance = std::sqrt(std::pow((myLat - lats[j]), 2) + std::pow((myLon - lons[j]), 2));
			if (distance == result[i] && distance < RADIUS)
			{
				std::cout << news[j] << " - " << result[i] << std::endl;
				hasNews = true;
				break;
			}
		}
	}

	if (hasNews)
	{
		std::cout << "I hope, I helped you" << std::endl;
	}
	else
	{
		std::cout << "Sorry, there are no news (((" << std::endl;
	}
	std::cin.get();
}

