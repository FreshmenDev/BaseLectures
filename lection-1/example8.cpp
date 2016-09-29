/*
 * Пример инициализации строки как указатель
 */

#include <iostream>

int main () {
    char* string = "Hello World";

    std::cout << string << std::endl;

    for (int i = 0; i < 10; ++i) {
        std::cout << string[i] << " ";
    }

    return 0;
}
