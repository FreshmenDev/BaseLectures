
#include <iostream>
#include <string>
#include <cmath>
#include <locale>
#include <stdio.h>

using std::cout; //определяем только те операций,
using std::cin; //которые нам нужны (избежение конфликтов)


const int NEWS_COUNT = 4;
const double RADIUS = 10.0;

 struct Help // определяем базу данных и массив news
    {
        char* description;
        float lon;
        float lat;
        double distance;
    }
    news[NEWS_COUNT] = {
                            {"Fire", 45.5, 40.5},
                            {"Flood", 48.6, 47.6},
                            {"Asteroid", 58.6, 56.6},
                            {"City Day", 60.6, 43.6}
                        };
						
						
int main()
{
    setlocale(0, "RUS");


    cout << "News in your region: \n\n";
    
    float myLat, myLon;
    
    cout << "Enter your position (Latitude, Longtitude)" << '\n';
    
    cin >> myLat >> myLon;
    
    bool hasNews = false;
    float dist[NEWS_COUNT];

    for(int i = 0; i < NEWS_COUNT; ++i) // Вопрос: играет ли в данном случае какую-то роль место оператора ++ ?
										// Если да, как можно написать всё определение 
    {									// цикла используя постфиксный вариант?
        double distance = sqrt(pow((myLat - news[i].lat), 2) + pow((myLon - news[i].lon), 2));   
       
        if(distance < RADIUS) 
        {
            dist[i] = distance;
            hasNews = true;
        }   
    }

	// определение времменых переменых для использования в сортировки
    float temp_num; 
    char* temp_str;

    for (int i = 0; i < NEWS_COUNT; ++i) // сортировка (по порядку возрастания)
    {
        for (int j = i + 1; j < NEWS_COUNT; ++j)
        {
            if (dist[i] > dist [j])
            {
                temp_num = dist[j];
                dist[j] = dist[i];
                dist[i] = temp_num;

                temp_str = news[j].description;
                news[j].description = news[i].description;
                news[i].description = temp_str;

            }
        }
    }

    // вывод на экран
    cout << "NEWS        DISTANCE\n\n";

    if (hasNews) 
    {
        for (int i = 0; i < NEWS_COUNT; ++i)
        {
            printf(news[i].description);
            cout << "        ";
            printf("%.2f", dist[i]);
			cout << '\n';
        }
        cout << "I was glad to help you." << '\n';
    } 
    else {
        cout << "Sorry, there are no news." << '\n';
    }
	
    return 0;
}
