#include <iostream>

int main() {
    int a0, a1, a2;
    std::cin >> a0 >> a1 >> a2;
    int d = a1 - a0;
    int r = a1 / a0;
    int r_9 = 1;
    for (int i = 0; i < 9; i++) r_9 *= r;
    std::cout << (a0 * a2 == a1 * a1 ? a0 * r_9 : a0 + 9 * d) << std::endl;
}