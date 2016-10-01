#include <iostream>
#include <string>
#include <cmath>


using namespace std;

int main() {
    const int NEWS_COUNT = 4;
    const double RADIUS = 10.0;
    float a[NEWS_COUNT];
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

	char* b[NEWS_COUNT];
	char* c;
    
    cout << "News in your region:" << endl << endl;
    
    float myLat, myLon,tmp,distance;
    
    cout << "Enter your position" << endl;
    
    cin >> myLat >> myLon;
    
    bool hasNews = false;
    
    
    for(int i = 0; i < NEWS_COUNT; ++i) 
	 {  
	   distance =sqrt(pow((myLat - lats[i]), 2) + pow((myLon - lons[i]), 2));
       if(distance < RADIUS) 
	    {
		 a[i] = distance;
		 b[i] = news[i];           
        }   
     }
  
	//Метод сортировки пузырька
	for(int i = 0; i < NEWS_COUNT- 1; ++i) // i - номер прохода
    {            
        for(int j = 0; j < NEWS_COUNT- 1; ++j) // внутренний цикл прохода
        {     
            if (arr[j + 1] < arr[j]) 
            {
                tmp = a[j + 1]; 
                a[j + 1] = a[j]; 
                a[j] = tmp;

				c = b[j + 1]; 
                b[j + 1] = b[j]; 
                b[j] = c;
            }
        }
    }


}