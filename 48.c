#include <iostream>
#include <iomanip>

int main() {
    int tempo, velocidade;
    std::cin >> tempo >> velocidade;

    // Consumo de combustível do carro (em km/l)
    const double consumo = 12.0;

    // Distância percorrida
    int distancia = tempo * velocidade;

    // Quantidade de litros de combustível necessária
    double litros = distancia / consumo;

    // Imprimir o resultado com três casas decimais
    std::cout << std::fixed << std::setprecision(3) << litros << std::endl;

    return 0;
}
