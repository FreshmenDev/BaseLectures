#include <iostream>
#include <cmath>
#include <iomanip>	// подключаю заголовок для использования манипулятора setprecision

const int NEWS_COUNT = 4;
const double RADIUS = 10.0;

struct News	// задаю структуру данных для удобной работы с начальными значениями
{
	char* news;
	double lats;
	double lons;
	double finalDistance;	// расстояние от места событий до пользователя
};


int main()
{
	setlocale(LC_CTYPE, "Rus");	// вывод русских символов на экран

	News allNews[NEWS_COUNT];	// создаю объект allNews[] типа News
	
	allNews[0] = { "Пожар", 45.5, 40.5 };		// инициализирую начальные значения для всех
	allNews[1] = { "Наводнение", 48.6, 47.6 };	// четырех элементов массива allNews
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
						// расчитываем расстояние от пользователя до места событий для каждой новости
		if (distance < RADIUS) 
		{
			allNews[i].finalDistance = distance;
			hasNews = true;
		}
		else
		{
			allNews[i].finalDistance = 0;	// если новости не в радиусе 10, то записать в i элемент массива число 0
		}
	}

	for (int i = 0; i < NEWS_COUNT; ++i)	// сортировка расстояний по возрастанию
	{
		for (int j = 1; j < NEWS_COUNT; ++j)
		{
			if (allNews[j].finalDistance < allNews[j - 1].finalDistance)
			{
				double temporaryInt;	// промежуточная переменная для запоминания расстояний
				char* temporaryStr;		// ==//== для названий новостных событий

				temporaryInt = allNews[j - 1].finalDistance;	// замена расстояний местами, если выполняется условие 
				allNews[j - 1].finalDistance = allNews[j].finalDistance;
				allNews[j].finalDistance = temporaryInt;

				temporaryStr = allNews[j - 1].news;		// замена новостных событий согласно их расстояниям
				allNews[j - 1].news = allNews[j].news;
				allNews[j].news = temporaryStr;
			}
		}
	}

	for (int i = 0; i < NEWS_COUNT; ++i)
	{
		if (allNews[i].finalDistance != 0)						// вывод результатов на экран
			std::cout << allNews[i].news << " - " << std::setprecision(2) << allNews[i].finalDistance << std::endl;
	}
	if (hasNews) {
		std::cout << "Надеюсь, информация была полезна" << std::endl;
	}
	else {
		std::cout << "Новостей в ближайшем радиусе не было найдено" << std::endl;
	}

	return 0;
}
