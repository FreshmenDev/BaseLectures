#include <iostream>
#include <string>
#include <cmath>
#include <iomanip>
#include <stdio.h>

using namespace std;

 struct News
 {
        char* des;
        double lats;
        double lons;
        double zone;
    };
int main()
{
    const int NEWS_COUNT = 4;
    const double RADIUS = 10.0;
    
     News news[NEWS_COUNT];
     
    news[1].des = "Fire";
    news[2].des = "Flood";
    news[3].des = "Asteroid";
    news[4].des = "City day";
    
    news[1].lats = 45.5;
    news[2].lats = 48.6;
    news[3].lats = 58.6;
    news[4].lats = 60.6;
    
    news[1].lons = 40.5;
    news[2].lons = 47.6;
    news[3].lons = 56.6;
    news[4].lons = 43.6;
    
    
    cout << "News in your region:" << endl << endl;
    
    double myLat, myLon, q;
    char* k;
    int j;
    
    cout << "Enter your position" << endl;
    
    cin >> myLat >> myLon;
    
    
    for(int i = 0; i < NEWS_COUNT; ++i) {
        double distance = sqrt(pow((myLat - news[i].lats), 2) + pow((myLon - news[i].lons), 2));   
       
        if(distance < RADIUS) {
           news[i].zone = distance;
        }   
        for( i = 0 ; i < NEWS_COUNT - 1; i++)
        {
            for(j = 0; j < NEWS_COUNT - i; j++)
            {
                if(news[j].zone > news[j+1].zone)
                {
                k = news[j+1].des;
                news[j+1].des = news[j].des;
                news[j].des = k;
                
                q = news[j+1].zone;
                news[j+1].zone = news[j].zone;
                news[j].zone = q;
                }
            }
        }    
    
     for(i=0 ; i < NEWS_COUNT ; i++)
     { if(news[i].zone > 0) {

        cout << news[i].des << " - " << news[i].zone << '\n';
     } 
     
    }
 }
return 0;
}
