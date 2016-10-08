#include <iostream>
#include <string>
#include <cmath>

using namespace std;

const int NEWS_COUNT = 4;
const double RADIUS = 10.0;

int main() {
	setlocale(LC_ALL, "RUS"); //????????? ???

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
    system("pause");
}
