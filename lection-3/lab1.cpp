#include <iostream>
#include <string>
#include <cmath>

using namespace std;

int main() {

    const int NEWS_COUNT = 4;
    const double RADIUS = 10.0;
    double arrDistances[NEWS_COUNT];
    char* arrNews [NEWS_COUNT];

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
    char* receivingArray;

    cout << "News in your region:" << endl << endl;

    float myLat, myLon;
    float tmp, distance;

    cout << "Enter your position" << endl;

    cin >> myLat >> myLon;

    bool hasNews = false;

    for(int i = 0; i < NEWS_COUNT; ++i) {
        distance =sqrt(pow((myLat - lats[i]), 2) + pow((myLon - lons[i]), 2));
        if(distance < RADIUS) {
            arrDistances[i] = distance;
            arrNews[i] = news[i];
        }
    }
    for(int i = 0; i < NEWS_COUNT- 1; ++i) {
        for(int j = 0; j < NEWS_COUNT- i; ++j) {
            if (arrDistances[j] > arrDistances[j+1) {
                tmp = arrDistances[j + 1];
                arrDistances[j + 1] = arrDistances[j];
                arrDistances[j] = tmp;

                receivingArray = arrNews[j + 1];
                arrNews[j + 1] = arrNews[j];
                arrNews[j] = receivingArray;
            }
        }
    }



    for(int i = 0; i < NEWS_COUNT; ++i) {
        if (arrDistances[i]>0){
            cout << arrNews[i] << " - " << arrDistances[i] << endl;
            hasNews = true;
        }
    }

    if (hasNews) {
        cout << "I hope, I helped you" << endl;
    }
    else {
        cout << "Sorry, there are no news (((" << endl;
    }
}