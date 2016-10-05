
#include "stdafx.h"
#include <iostream>
#include <string>  //Все подключенные библиотеки
#include <cmath>
#include <clocale>

using namespace std; //Чтобы не писать постоянно std::

const int NEWS_COUT = 4; //Константы
const double RADIUS =10.0;

struct News //Описание структуры
 {
	 char* description;
	 double lat;
	 double lon;
	 double distance;
 };

int main()
	setlocale(LC_ALL,"RUS"); //Подключение поддержки русского языка

    News news [NEWS_COUT]; //Создание структуры данных

	   news[1].description = "Fire"; //Записывает названия новостей в структуру
	   news[2].description = "Flood";
	   news[3].description = "Asteroid";
	   news[4].description = "Citi day";

	   news[1].lat = 45.5; //Записывает долготу в структуру
	   news[2].lat = 48.6;
	   news[3].lat = 58.6;
	   news[4].lat = 60.6;
    
	   news[1].lon = 40.5; //Записывает широту в структуру
	   news[2].lon = 47.6; 
	   news[3].lon = 56.6; 
	   news[4].lon = 43.6; 

	char* c;
	double myLat,myLon,tmp,distance; //Остальные необходимые переменные 

	cout <<"Новости в твоем регионе" << endl << endl;
	cout <<"Введите свои координаты" << endl;
	cin >>myLat >>myLon;
	
	for(int i = 0; i < NEWS_COUT; ++i)
	  {
	     distance=sqrt(pow(myLat-news[i].lat),2)+pow((myLon-news[i].lon),2));
	     if(distance < RADIUS)   //Если расстояние о новости входит в наш радиус,то записать его под соответствующим индексом
	      {
		     news[i].distance = distance;
	     }
	   }






	 


