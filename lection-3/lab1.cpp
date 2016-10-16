#include <iostream>
#include <string>
#include <cmath>

struct News {
    char* name;
    float lat;
    float lon;
    double distance;
};

int main() {
    const int NEWS_COUNT = 8;
    const double RADIUS = 10.0;

    News news[NEWS_COUNT];

    news[0].name = "Fire";
    news[0].lat = 45.5;
    news[0].lon = 40.5;

    news[1].name = "Flood";
    news[1].lat = 48.6;
    news[1].lon = 47.6;

    news[2].name = "Asteroid";
    news[2].lat = 58.6;
    news[2].lon = 56.6;

    news[3].name = "City Day";
    news[3].lat = 60.6;
    news[3].lon = 43.6;

    std::cout << "News in your region:" << std::endl << std::endl;

    float myLat, myLon;

    std::cout << "Enter your position" << std::endl;

    std::cin >> myLat >> myLon;

    bool hasNews = false;

    /*
     *  Итак на данном этапе у нас есть данные и позиция пользователя.
     *  Задача состоит в том, чтобы мы нашли новости в заданном радиусе
     *  а также выввели их в отсортированом по расстоянию до пользователя порядке + порядкок.
     *  Для этого в структуре, которая описывает информацию о новостях, я добавил поле distance.
     *
     *  Прежде чем что-либо сортировать, нам неплохо бы узнать расстояние до каждого объекта.
     *  Вообще решение данной задачи можно поделить на несколько частей:
     *    - Рассчитываем расстояние до каждой новости, на этом же этапе можно узнать
     *      есть ли у нас новости, так как может оказаться так, что пользователь слишком далеко
     *    - Если новостей нет, то сообщим об этом пользователю, ему не надо ждать пока мы там
     *      сортируем наш массив, на самом деле и сортировать в таком случае ничего не надо
     *    - Если новости есть, мы отсортируем наши новости по расстоянию.
     *      Так как мы не знаем где заведомо будет нужная новость в массиве, нам проще
     *      удостоверится, что все нужные нам новости находятся в начале массива
     *    - После того как мы отсортировали новости, мы можем пройти по нашему массиву
     *      и выводить новости до тех пор, пока эти новости поадают в радиус
     *      если новость не попала в радиус, мы можем остановить цикл, так как мы знаем
     *      что все нужные нам новсти в начале массива, и как только мы дойдём до такой
     *      новости, что она не будет входить в радиус, значит последующие тоже не входят
     *      и мы можем выходить.
     *
     */

    for (int i = 0; i < NEWS_COUNT; ++i) {
        news[i].distance = std::sqrt(std::pow((myLat - news[i].lat), 2)
                                     + std::pow((myLon - news[i].lon), 2));

        if (news[i].distance < RADIUS) {
            hasNews = true;
        }
    }

    if (hasNews) {
        
        /*
         * Для сортировки я использую алгоритм сортировки вставкой
         * при той же сложности вычисления, он выглядет намного лаконичнее и аккуратнее
         */

        for (int i = 1; i < NEWS_COUNT; ++i) {
            News key = news[i];
            int j = i - 1;

            while (j > -1 && news[j].distance > key.distance) {
                news[j + 1] = news[j];
                --j;
            }

            news[j + 1] = key;
        }


        for (int k = 0; k < NEWS_COUNT; ++k) {
            if (news[k].distance > RADIUS) break;
            std::cout << news[k].name << " - " << news[k].distance << std::endl;
        }

        std::cout << "I hope, I helped you" << std::endl;
    } else {
        std::cout << "Sorry, there are no news (((" << std::endl;
    }
}