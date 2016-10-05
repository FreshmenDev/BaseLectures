
#include "stdafx.h"
#include <iostream>
#include <string>  //Все подключенные библиотеки
#include <cmath>
#include <clocale>

using namespace std; //Чтобы не писать постоянно std::

const int NEWS_COUNT = 4; //Константы
const double RADIUS =10.0;

struct News //Описание структуры
 {
	 char* description;
	 double lat;
	 double lon;
	 double distance;
 };

int main()
{
    setlocale(LC_ALL,"RUS"); //Подключение поддержки русского языка

    News news [NEWS_COUNT]; //Создание структуры данных
	News Type;

    news[0].description = "Fire"; //Записывает названия новостей в структуру
    news[1].description = "Flood";
	news[2].description = "Asteroid";
	news[3].description = "Citi day";

	news[0].lat = 45.5; //Записывает долготу в структуру
	news[1].lat = 48.6;
	news[2].lat = 58.6;
	news[3].lat = 60.6;
    
	news[0].lon = 40.5; //Записывает широту в структуру
	news[1].lon = 47.6; 
	news[2].lon = 56.6; 
	news[3].lon = 43.6; 

    double myLat,myLon; //Остальные необходимые переменные 

	cout<<"Новости в твоем регионе"<<endl<<endl;
	cout<<"Введите свои координаты"<<endl;
	cin>>myLat>>myLon;

	for(int i = 0; i < NEWS_COUNT; ++i)
	  {
	    news[i].distance = sqrt(pow((myLat-news[i].lat),2)+pow((myLon-news[i].lon),2));
	  }

	for(int i = 0; i < NEWS_COUNT; ++i) //Метод пузырька
	  {
		for(int j = 0; j< NEWS_COUNT - i; ++j)
		  {
			if(news[j].distance > news[j+1].distance)
			  {
				Type = news[j];
				news[j]=news[j+1];
				news[j+1]=Type;
			  }
		  }
	  }

	for(int i = 0; i < NEWS_COUNT; ++i) //Вывод по условию задачи
	  {
		if(news[i].distance < RADIUS)
		  {
			cout<<news[i].description<<" - "<<news[i].distance<<endl;
		  }
	  }

	system("pause"); //Добавил,чтобы не улетало меню с выводом данных

}
