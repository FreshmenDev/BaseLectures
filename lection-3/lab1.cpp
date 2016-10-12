#include <iostream>
#include <cmath>
#include <iomanip>	// подключаю заголовок для использования манипулятора setprecision

const int NEWS_COUNT = 4;
const double RADIUS = 10.0;

struct News
{
	char* news;
	double lats;
	double lons;
	double finalDistance;	// расстояние от места событий до пользователя
};


int main()
{
	setlocale(LC_CTYPE, "Rus");

	News allNews[NEWS_COUNT];
	
	allNews[0] = { "Пожар", 45.5, 40.5 };
	allNews[1] = { "Наводнение", 48.6, 47.6 };
	allNews[2] = { "Метеорит", 58.6, 56.6 };
	allNews[3] = { "День города", 60.6, 43.6 };

	std::cout << "Новости в Вашем регионе:" << std::endl << std::endl;

	float myLat, myLon;

	std::cout << "Введите Вашу позицию" << std::endl;

	std::cin >> myLat >> myLon;

	bool hasNews = false;

	for (int i = 0; i < NEWS_COUNT; ++i)
	{
		double distance = std::sqrt(std::pow((myLat - allNews[i].lats), 2) + std::pow((myLon - allNews[i].lons), 2));
						
		if (distance < RADIUS) 
		{
			allNews[i].finalDistance = distance;
			hasNews = true;
		}
		else
		{
			allNews[i].finalDistance = 0;	// если новости не в радиусе 10, то записать 0
		}
	}
	
	for (int i = 0; i < NEWS_COUNT; ++i)
	{
		for (int j = 1; j < NEWS_COUNT; ++j)
		{
			News temporaryStruct = allNews[j - 1];	// использую промежуточную структуру для сортировки

			if (allNews[j - 1].finalDistance > allNews[j].finalDistance)
			{
				allNews[j - 1] = allNews[j];
				allNews[j] = temporaryStruct;
			}
		}
	}

	for (int i = 0; i < NEWS_COUNT; ++i)
	{
		if (allNews[i].finalDistance != 0)
		{
			std::cout << allNews[i].news << " - " << std::setprecision(2) 
				  << allNews[i].finalDistance << std::endl;
		}
	}
	if (hasNews) {
		std::cout << "Надеюсь, информация была полезна" << std::endl;
	}
	else {
		std::cout << "Новостей в ближайшем радиусе не было найдено" << std::endl;
	}

	return 0;
}
