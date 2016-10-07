#include <iostream>
#include <string>
#include <cmath>

int main() {
	
	setlocale(LC_ALL,"RUS"); //поддержка русского €зыка

    const int NEWS_COUNT = 4; // кол-во новостей
    const double RADIUS = 10.0; // объ€вленный радиус
    
	struct News {  // ќбъ€вление структуры News
 		char* description; 
 		double lats; 
 		double lons; 
 		float D; 
	};  
    
	News  news [NEWS_COUNT]; //—оздание данных стуркуры News

     news[1].description = "Fire"; //название новости
     news[2].description = "Flood";
     news[3].description = "Asteroid";
     news[4].description = "City Day";   
  
     news[1].lats = 45.5; //координаты 1
     news[2].lats = 48.6;
     news[3].lats = 58.6;
     news[4].lats = 60.6;
  
     news[1].lons = 40.5; //координаты 2
     news[2].lons = 47.6;
     news[3].lons = 56.6;
     news[4].lons = 43.6;
    
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
