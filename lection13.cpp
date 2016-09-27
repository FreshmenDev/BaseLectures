#include <iostream>

int main () {
    int n = 5;
    int ages[n];
    int value = 4;

    for (int i = 0; i < n; ++i) {
        ages[i] = i + 10;
    }

    for (int i = 0; i < n; ++i) {
        std::cout << ages[i] << " ";
    }
    return 0;
}
