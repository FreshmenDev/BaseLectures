/*
 * Пример работы с указателями
 */

#include <iostream>

int main () {
    int count = 5436;

    int* count2 = &count;
    std::cout << count <<  " " << count2 << " " << *count2 << std::endl;

    *count2 = 10 + 30 * 423423;
    std::cout << count << " " << count2 << " " << *count2 << std::endl;
    return 0;
}
