#include <iostream>
#include <string>

using namespace std;

int main() {
    int N;
    cin >> N;
    cin.ignore(); // Ignorar a quebra de linha após o número de casos de teste

    while (N--) {
        string linha;
        getline(cin, linha);

        int meio = linha.size() / 2;
        string primeira_metade = linha.substr(0, meio);
        string segunda_metade = linha.substr(meio);

        // Inverter as duas metades
        reverse(primeira_metade.begin(), primeira_metade.end());
        reverse(segunda_metade.begin(), segunda_metade.end());

        // Juntar as metades invertidas para formar a linha original
        cout << primeira_metade + segunda_metade << endl;
    }

    return 0;
}
