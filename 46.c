#include <iostream>
#include <iomanip>
#include <cmath>

using namespace std;

int main() {
    double x1, y1, x2, y2;

    // Leitura das coordenadas dos dois pontos
    cin >> x1 >> y1;
    cin >> x2 >> y2;

    // Cálculo da distância usando a fórmula
    double distancia = sqrt(pow(x2 - x1, 2) + pow(y2 - y1, 2));

    // Exibição do resultado com 4 casas decimais
    cout << fixed << setprecision(4);
    cout << distancia << endl;

    return 0;
}
