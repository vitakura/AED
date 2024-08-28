#include <iostream>
#include <cmath>  // Necessário para a função abs

using namespace std;

int main() {
    int a, b, c;

    // Leitura dos três valores inteiros
    cin >> a >> b >> c;

    // Aplicando a fórmula para encontrar o maior entre a e b
    int maiorAB = (a + b + abs(a - b)) / 2;

    // Agora comparando o resultado com o terceiro valor c
    int maiorABC = (maiorAB + c + abs(maiorAB - c)) / 2;

    // Exibindo o maior valor com a mensagem
    cout << maiorABC << " eh o maior" << endl;

    return 0;
}
