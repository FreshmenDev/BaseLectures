/*
 * Пример реалзиации алгоритма поиска в массиве
 */

#include <iostream>

int main () {
    int n = 5;
    int ages[n];
    int value = 10;

    for (int i = 0; i < n; ++i) {
        ages[i] = i + 10;
    }

    for (int i = 0; i < n; ++i) {
        std::cout << ages[i] << " " << std::endl;
    }

    int j = 0, ind = -1;

    while (j < n) {
        if (ages[j] == value) {
            ind = j;
            break;
        }
        ++j;
    }
    std::cout << ind << " ";

    return 0;
}
