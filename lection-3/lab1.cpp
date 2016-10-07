#include <iostream>
#include <string>
#include <cmath>

int main() {
	
	setlocale(LC_ALL,"RUS"); //��������� �������� �����

    const int NEWS_COUNT = 4; // ���-�� ��������
    const double RADIUS = 10.0; // ����������� ������
    
	struct News {  // ���������� ��������� News
 		char* description; 
 		double lats; 
 		double lons; 
 		float D; 
	};  
    
	News  news [NEWS_COUNT]; //�������� ������ �������� News

	news[1].description = "Fire"; //�������� �������
	news[2].description = "Flood";
	news[3].description = "Asteroid";
	news[4].description = "City Day";   
  
	news[1].lats = 45.5; //���������� 1
	news[2].lats = 48.6;
	news[3].lats = 58.6;
	news[4].lats = 60.6;
  
	news[1].lons = 40.5; //���������� 2
	news[2].lons = 47.6;
	news[3].lons = 56.6;
	news[4].lons = 43.6;

	float myLat, myLon, distance, tmp; //��������� 1, ���������� 2, ��������� � �������, ������������� ���������� ��� ����������
	char* tmp2; //������������� ���������� ��� ���������� ���������
    
    std::cout << "News in your region:" << std::endl << std::endl; 
    
    std::cout << "Enter your position" << std::endl;
    
    std::cin >> myLat >> myLon; //���� ��������� ������������
    
    bool hasNews = false;
    
	for(int i = 0; i < NEWS_COUNT; ++i) { //���� ��� ������� ���������
	distance =std::sqrt(std::pow((myLat - news[i].lats), 2) + pow((myLon - news[i].lons), 2));  
		if (distance < RADIUS) { //����� ��������, ���������� � ������
			news[i].D = distance; //��������� - � ������ ��� ����������
			hasNews = true;
		}
    }
    
	for(int i = 0; i < NEWS_COUNT- 1; i++) { //���������� �������� (���������� �������� �� ��������� ������������ �������)           
        for(int j = 0; j < NEWS_COUNT- i; j++) { //���������� ������
            if (news[j].D > news[j+1].D) { //������������ ��������
				tmp = news[j + 1].D;  
				news[j + 1].D = news[j].D;
				news[j].D = tmp; 
				tmp2 = news[j + 1].description; //������������ ��������� 
				news[j + 1].description = news[j].description;
				news[j].description = tmp2; 
              } 
         } 
	} 

	for(int i = 0; i < NEWS_COUNT; i++) { //����� ������������� �������� � ��������� (������ �� ������� ������)
			if (news[i].D>0) { 
				std::cout <<news[i].description<<" - "<<news[i].D<<std::endl; 
		    } 
	} 


	if (hasNews) { //����������
        std::cout << "I hope, I helped you" << std::endl;
    } else {
        std::cout << "Sorry, there are no news (((" << std::endl;
    }

	system("pause"); //�������� ������ �� ������
}
