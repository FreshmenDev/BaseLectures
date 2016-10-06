#include <iostream>
#include <string>
#include <cmath>

int main() {
	const int NEWS_COUNT = 4;
	const double RADIUS = 10.0;

	char* news[] = {
		"Fire",
		"Flood",
		"Asteroid",
		"City Day"
	};

	float lats[] = {
		45.5,
		48.6,
		58.6,
		60.6
	};

	float lons[] = {
		40.5,
		47.6,
		56.6,
		43.6
	};

	std::cout << "News in your region:" << std::endl << std::endl;

	float myLat, myLon;

	std::cout << "Enter your position" << std::endl;

	std::cin >> myLat >> myLon;

	bool hasNews = false;
	double dis[NEWS_COUNT];
	double variable;
	char* variable1;
	int adition = 0;

	for (int i = 0; i < NEWS_COUNT; ++i) {
		double distance = std::sqrt(std::pow((myLat - lats[i]), 2) + std::pow((myLon - lons[i]), 2));

		if (distance < RADIUS) {
			dis[i] = distance;
			adition += 1;
			hasNews = true;
		}
	}
	for (int i = 0;i < adition;++i) {
		for (int j = i + 1;j < adition;++j) {
			if (dis[i] > dis[j]) {
				variable = dis[j];
				dis[j] = dis[i];
				dis[i] = variable;
				variable1 = news[j];
				news[j] = news[i];
				news[i] = variable1;
			}
		}
	}
	for (int i = 0;i<adition;++i)
		std::cout << news[i] << "-" << dis[i] << std::endl;


	if (hasNews) {
		std::cout << "I hope, I helped you" << std::endl;
	}
	else {
		std::cout << "Sorry, there are no news (((" << std::endl;
	}
}
