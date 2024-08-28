#include <iostream>

int main() {
    int N;
    std::cin >> N;

    int horas = N / 3600;
    int minutos = (N % 3600) / 60;
    int segundos = N % 60;

    std::cout << horas << ":" << minutos << ":" << segundos << std::endl;

    return 0;
}
