#include <iostream>
#include <string>
#include <cmath>

int main() {
    using namespace std;
    const int NEWS_COUNT = 4;
    const double RADIUS = 10.0;
    double DISTANCE[NEWS_COUNT];
    char* NEWS [NEWS_COUNT];

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
    float theAuxiliaryVariable, dis;

    cout << "Enter your position" << endl;

    cin >> myLat >> myLon;

    bool hasNews = false;

    for(int i = 0; i < NEWS_COUNT; ++i) {
        dis =sqrt(pow((myLat - lats[i]), 2) + pow((myLon - lons[i]), 2));
        if(dis < RADIUS) {
            DISTANCE[i] = dis;
            NEWS[i] = news[i];
        }
    }
    for(int i = 0; i < NEWS_COUNT- 1; ++i) {
        for(int j = 0; j < NEWS_COUNT- i; ++j) {
            if (DISTANCE[j] > DISTANCE[j+1]) {
                theAuxiliaryVariable = DISTANCE[j + 1];
                DISTANCE[j + 1] = DISTANCE[j];
                DISTANCE[j] = theAuxiliaryVariable;

                receivingArray = NEWS[j + 1];
                NEWS[j + 1] = NEWS[j];
                NEWS[j] = receivingArray;
            }
        }
    }



    for(int i = 0; i < NEWS_COUNT; ++i) {
        if (DISTANCE[i]>0){
            cout <<NEWS[i]<<" - "<<DISTANCE[i]<<endl;
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