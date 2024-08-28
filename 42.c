#include <iostream>
#include <iomanip>
#include <cmath>

using namespace std;

int main() {
    double R;
    cin >> R;

    // Definição de pi
    const double pi = 3.14159;

    // Cálculo do volume usando a fórmula (4/3) * pi * R^3
    double volume = (4.0 / 3.0) * pi * pow(R, 3);

    // Exibição do resultado com 3 casas decimais
    cout << fixed << setprecision(3);
    cout << "VOLUME = " << volume << endl;

    return 0;
}
