#include "stdafx.h"
#include <iostream>
#include <string>
#include <cmath>
#include <clocale>


using namespace std;

int main() {
    setlocale(LC_ALL,"RUS");

    const int NEWS_COUNT = 4;
    const double RADIUS = 10.0;

    double rasstoianie[NEWS_COUNT];

    char* news[] = {
     "Fire",
     "Flood",
     "Asteroid",
     "City Day"    
    };
    
    double lats[] = {
     45.5,
     48.6,
     58.6,
     60.6
    };
    
    double lons[] = {
     40.5,
     47.6,
     56.6,
     43.6
    };

	char* novosti[NEWS_COUNT];
	char* c;
    
    cout << "Новости в твоем регионе:" << endl << endl;
    
    double myLat, myLon,tmp,distance;
    
    cout << "Введите свои координаты" << endl;
    
    cin >> myLat >> myLon;
       
    
    for(int i = 0; i < NEWS_COUNT; ++i) 
	 {  
	   distance =sqrt(pow((myLat - lats[i]), 2) + pow((myLon - lons[i]), 2));
       if(distance < RADIUS) 
	    {
		 rasstoianie[i] = distance;
		 novosti[i] = news[i];           
        }   
     }
  
	//Метод сортировки пузырька
	for(int i = 0; i < NEWS_COUNT- 1; ++i) // i - номер прохода
    {            
        for(int j = 0; j < NEWS_COUNT- i; ++j) // внутренний цикл прохода
        {     
            if (rasstoianie[j] > rasstoianie[j+1]) 
            {
                tmp = rasstoianie[j + 1]; 
                rasstoianie[j + 1] = rasstoianie[j]; 
                rasstoianie[j] = tmp;

				c = novosti[j + 1]; 
                novosti[j + 1] = novosti[j]; 
                novosti[j] = c;
            }
        }
    }


    
	for(int i = 0; i < NEWS_COUNT; ++i)
	{
        if (rasstoianie[i]>0){
        cout <<novosti[i]<<" - "<<rasstoianie[i]<<endl;
	}
}
 system("pause");
}