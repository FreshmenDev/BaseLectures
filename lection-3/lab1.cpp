#include <iostream>
#include <string>
#include <cmath>
#include <iomanip> //модуль для округления

int main() {
	
	setlocale(LC_ALL,"RUS"); //поддержка русского языка

    const int NEWS_COUNT = 4; // кол-во новостей
    const double RADIUS = 10.0; // объявленный радиус
    
	struct News {  // Объявление структуры News
 		char* description; 
 		double lats; 
 		double lons; 
 		float D; 
	};  
    
	News  news [NEWS_COUNT]; //Создание данных стуркуры News

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

	float myLat, myLon, distance, tmp; //коордната 1, координата 2, дистанция в формуле, промежуточная переменная для сортировки
	char* tmp2; //промежуточная переменная для сортировки структуры
    
    std::cout << "News in your region:" << std::endl << std::endl; 
    
    std::cout << "Enter your position" << std::endl;
    
    std::cin >> myLat >> myLon; //ввод координат пользователя
    
    bool hasNews = false;
    
	for(int i = 0; i < NEWS_COUNT; ++i) { //цикл для расчета дистанций
	distance =std::sqrt(std::pow((myLat - news[i].lats), 2) + pow((myLon - news[i].lons), 2));  
		if (distance < RADIUS) { //поиск новостей, попадающих в радиус
			news[i].D = distance; //дистанция - в массив для сортировки
			hasNews = true;
		}
    }
    
	for(int i = 0; i < NEWS_COUNT- 1; i++) { //сортировка пузырька (повторение проходов по элементам сортируемого массива)           
        for(int j = 0; j < NEWS_COUNT- i; j++) { //внутренний массив
            if (news[j].D > news[j+1].D) { //перестановка новостей
				tmp = news[j + 1].D;  
				news[j + 1].D = news[j].D;
				news[j].D = tmp; 
				tmp2 = news[j + 1].description; //перестановка дистанции 
				news[j + 1].description = news[j].description;
				news[j].description = tmp2; 
              } 
         } 
	} 

	for(int i = 0; i < NEWS_COUNT; i++) { //вывод сортированных новостей и дистанции (нужные по условию задачи)
			if (news[i].D>0) { 
				std::cout << std::setprecision(2) <<news[i].description<<" - "<<news[i].D<<std::endl; //округление дистанции
		    } 
	} 


	if (hasNews) { //вежливость
        std::cout << "I hope, I helped you" << std::endl;
    } else {
        std::cout << "Sorry, there are no news (((" << std::endl;
    }

	system("pause"); //задержка вывода на экране
}
