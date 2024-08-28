#include <iostream>
#include <iomanip>

using namespace std;

int main() {
    int codigo1, numero1, codigo2, numero2;
    double valor1, valor2;

    // Leitura dos valores da primeira linha
    cin >> codigo1 >> numero1 >> valor1;

    // Leitura dos valores da segunda linha
    cin >> codigo2 >> numero2 >> valor2;

    // Cálculo do valor total a ser pago
    double total = (numero1 * valor1) + (numero2 * valor2);

    // Exibição do resultado com formatação
    cout << fixed << setprecision(2);
    cout << "VALOR A PAGAR: R$ " << total << endl;

    return 0;
}
