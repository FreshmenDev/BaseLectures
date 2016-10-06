
#include <iostream>
#include <string>
#include <cmath>
#include <iomanip>

using std::cout; //определяем только те операций,
using std::cin; //которые нам нужны (избежение конфликтов)


const int NEWS_COUNT = 4;
const double RADIUS = 10.0;

 struct Help // определяем структуру данных и массив news
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
	
    cout << "News in your region: \n\n";
    
    float myLat, myLon;
    
    cout << "Enter your position (Latitude, Longtitude)" << '\n';
    
    cin >> myLat >> myLon;
    
    bool hasNews = false;
    float dist[NEWS_COUNT];

    for (int i = 0; i < NEWS_COUNT; ++i) 
		
    {
        double distance = sqrt(pow((myLat - news[i].lat), 2) + pow((myLon - news[i].lon), 2));   
       
        if (distance < RADIUS) 
        {
            dist[i] = distance;
            hasNews = true;
        }   
        else {
            dist[i] = 0;
        }
    }
	
	// определение времменых переменых для использования в сортировки
    float tempNum;
    char* tempStr;

    for (int i = 0; i < NEWS_COUNT; ++i)  // сортировка (по порядку возрастания)
    {
        for (int j = i + 1; j < NEWS_COUNT; ++j)
        {
            if (dist[i] > dist [j])
            {
                tempNum = dist[j];
                dist[j] = dist[i];
                dist[i] = tempNum;

                tempStr = news[j].description;
                news[j].description = news[i].description;
                news[i].description = tempStr;

            }
        }
    }

    
    if (hasNews) // вывод на экран
    {
        cout << "NEWS        DISTANCE\n\n";
        for (int i = 0; i < NEWS_COUNT; ++i)
        {
            if (dist[i] != 0) 
            {
                cout << news[i].description;
                cout << "        ";
                cout << std::setprecision(3) << dist[i];
                cout << '\n';
            }
        }
        cout << "\nI was glad to help you" << '\n';
    } 
    else {
        cout << "Sorry, there are no news " << '\n';
    }
	
    return 0;
}
