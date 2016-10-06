#include <iostream>
#include <string>
#include <cmath>
#include <iomanip>
#include <

using namespace std; 

struct News;
{
	char* Event;
	float lats;
	float lons;
	double lenght;
}
int main() {
    const int NEWS_COUNT = 4;
    const double RADIUS = 10.0;
    
	ogon` = { "Fire", 45.5, 40.5 };
	voda = { "Flood", 48.6, 47.6 };
	asteroid = { "Asteroid", 58.6, 56.6 };
	den` goroda = { "City Day", 60.6, 43.6 };
    
  
    
    cout << "News in your region:" << endl << endl;
    
    float myLat, myLon;
    
   cout << "Enter your position" << endl;
    
    cin >> myLat >> myLon;
    
    bool hasNews = false;
    
    for(int i = 0; i < NEWS_COUNT; ++i) {
        double distance = sqrt(pow((myLat - lats[i]), 2) + pow((myLon - lons[i]), 2));   
       
        if(distance < RADIUS) {
            cout << news[i] << endl;
            hasNews = true;
        }   
    }
    

    if (hasNews) {
        cout << "I hope, I helped you" << endl;
    } else {
        cout << "Sorry, there are no news (((" << endl;
    }
}
