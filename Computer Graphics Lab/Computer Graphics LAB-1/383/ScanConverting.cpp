#include <iostream>

int main() {
    int x = 5;
    int y = 3;

    for (int i = 1; i <= y; ++i) {
        std::cout << std::endl;
    }

    for (int i = 1; i <= x; ++i) {
        std::cout << " ";
    }

    std::cout << "*" << std::endl;

    return 0;
}
