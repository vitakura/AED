#include <iostream>
#include <iomanip>

using namespace std;

int main() {
    string nome;
    double salarioFixo, totalVendas;

    // Lê os dados de entrada
    cin >> nome;
    cin >> salarioFixo;
    cin >> totalVendas;

    // Calcula o total a receber (salário fixo + 15% de comissão sobre as vendas)
    double totalReceber = salarioFixo + (totalVendas * 0.15);

    // Define a precisão para duas casas decimais e imprime o resultado
    cout << fixed << setprecision(2);
    cout << "TOTAL = R$ " << totalReceber << endl;

    return 0;
}
