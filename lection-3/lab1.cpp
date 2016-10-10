#include <iostream>
#include <string>
#include <cmath>
#include <stdlib.h>

using namespace std;
float myLat, myLon;
const int NEWS_COUNT = 4;
const double RADIUS = 10.0;
struct News {
	char* des;
	float lats;
	float lons;
	double zone;
};
int main() {

	News news[NEWS_COUNT];

	news[0].des = "Fire";
	news[0].lats = 45.5;
	news[0].lons = 45.5;

	news[1].des = "Flood";
	news[1].lats = 48.6;
	news[1].lons = 47.6;

	news[2].des = "Asteroid";
	news[2].lats = 58.6;
	news[2].lons = 56.6;

	news[3].des = "City Day";
	news[3].lats = 60.6;
	news[3].lons = 43.6;

	cout << "News in your region:" << endl;

	float myLat, myLon;

	cout << "Enter your position" << endl;

	cin >> myLat >> myLon;

	bool hasNews = false;

	for (int i = 0; i < NEWS_COUNT; ++i) {
		news[i].zone = sqrt(pow((myLat - news[i].lats), 2) + pow((myLon - news[i].lons), 2));

		if (news[i].zone < RADIUS) {
			hasNews = true;
		}
	}

	for (int i = 1; i < NEWS_COUNT; ++i) {
		News key = news[i];
		int j = i - 1;

		while (j > -1 && news[j].zone > key.zone) {
			news[j + 1] = news[j];
			--j;
		}

		news[j + 1] = key;
	}

	for (int k = 0; k < NEWS_COUNT; ++k) {
		if (news[k].zone > RADIUS) break;
		cout << news[k].des << '-' << news[k].zone << endl;
	}

	if (hasNews) {
		cout << "I hope, I helped you" << endl;
	}
	else {
		cout << "Sorry, there are no news (((" << endl;
	}

	system("pause");
	return 0;
 }