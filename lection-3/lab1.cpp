#include <iostream>
#include <cmath>
#include <string>


int main() {
    const int NEWS_COUNT = 4;
    const double RADIUS = 10.0;
    
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
    
    std::cout << "News in your region:" << std::endl << std::endl;
    
    float myLat, myLon;
    
    std::cout << "Enter your position" << std::endl;
    
    std::cin >> myLat >> myLon;
    
    bool hasNews = false;
    
    for(int i = 0; i < NEWS_COUNT; ++i) {
        double distance = std::sqrt(std::pow((myLat - lats[i]), 2) + std::pow((myLon - lons[i]), 2));   
       
        if(distance < RADIUS) {
            std::cout << news[i] << std::endl;
            hasNews = true;
        }   
    }
    
    if (hasNews) {
        std::cout << "I hope, I helped you" << std::endl;
    } else {
        std::cout << "Sorry, there are no news (((" << std::endl;
    }
}
