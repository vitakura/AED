#include <iostream>

int main() {
    int distancia;
    
    // Lê a distância em quilômetros
    std::cin >> distancia;
    
    // Calcula o tempo em minutos
    int tempo = distancia * 2;
    
    // Imprime o resultado seguido da palavra "minutos"
    std::cout << tempo << " minutos" << std::endl;
    
    return 0;
}
