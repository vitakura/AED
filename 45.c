#include <iostream>
#include <iomanip>

using namespace std;

int main() {
    int X;         // Distância total percorrida (em Km)
    double Y;      // Total de combustível gasto (em litros)

    // Leitura dos valores de entrada
    cin >> X >> Y;

    // Cálculo do consumo médio
    double consumoMedio = X / Y;

    // Exibição do resultado com 3 casas decimais
    cout << fixed << setprecision(3);
    cout << consumoMedio << " km/l" << endl;

    return 0;
}
