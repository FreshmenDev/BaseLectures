#include "stdafx.h"
#include <iostream>
#include <string>     //Все подключенные библеотеки
#include <cmath>
#include <clocale>

using namespace std; // чтобы не писать постоянно std::

const int NEWS_COUNT = 4;  //Константы
const double RADIUS = 10.0;

struct News   //Описание структуры 
	{
		char* description;
		double lat;
		double lon;
		double rasstoianie;
	};

int main()
{
    setlocale(LC_ALL,"RUS"); //подключение поддержки русского языка

    News  news [NEWS_COUNT]; //Создание стуркуры данных 

	 news[1].description = "Fire"; //записывание названия в структуру
	 news[2].description = "Flood";
	 news[3].description = "Asteroid";
	 news[4].description = "City Day";

	 news[1].lat = 45.5; //записывание долготы в структуру
	 news[2].lat = 48.6;
	 news[3].lat = 58.6;
	 news[4].lat = 60.6;

	 news[1].lon = 40.5; //записывание ширины в структуру
	 news[2].lon = 47.6;
	 news[3].lon = 56.6;
	 news[4].lon = 43.6;
	     
	char* c;
	double myLat, myLon,tmp,distance;
    
    cout << "Новости в твоем регионе:" << endl << endl; 
    cout << "Введите свои координаты" << endl;
    cin >> myLat >> myLon;
      
	for(int i = 0; i < NEWS_COUNT; ++i) 
	 {  
	   distance =sqrt(pow((myLat - news[i].lat), 2) + pow((myLon - news[i].lon), 2));
        if(distance < RADIUS)  //если расстояние о новости входит в наш радиус,то записать его под соотвествующим индексом в структуру
	     {
		   news[i].rasstoianie = distance;           
         }   
     }
	//Метод сортировки пузырька
	for(int i = 0; i < NEWS_COUNT- 1; ++i) // i - номер прохода
     {            
       for(int j = 0; j < NEWS_COUNT- i; ++j) // внутренний цикл прохода
        {     
           if (news[j].rasstoianie > news[j+1].rasstoianie) 
             {
                tmp = news[j + 1].rasstoianie; 
                news[j + 1].rasstoianie = news[j].rasstoianie; //перестановка расстояний внутри структуры
                news[j].rasstoianie = tmp;

				c = news[j + 1].description; 
                news[j + 1].description = news[j].description;  //перестановка названия новостей внутри структуры
                news[j].description = c;
             }
        }
     }

	for(int i = 0; i < NEWS_COUNT; ++i) //Вывод поусловию задачи
	 {
       if (news[i].rasstoianie>0)
		{
         cout <<news[i].description<<" - "<<news[i].rasstoianie<<endl;
	    }
     } 

    system("pause"); //Добавил,чтобы не улетало меню с выводом данных

}