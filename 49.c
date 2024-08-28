#include <iostream>

int main() {
    int valor;
    std::cin >> valor;

    std::cout << valor << std::endl;

    int notas[7] = {100, 50, 20, 10, 5, 2, 1};
    int quantidade;

    for (int i = 0; i < 7; ++i) {
        quantidade = valor / notas[i];
        std::cout << quantidade << " nota(s) de R$ " << notas[i] << ",00" << std::endl;
        valor %= notas[i];
    }

    return 0;
}
