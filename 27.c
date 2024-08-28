#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

void criptografar(string& linha) {
    // Primeira passada: deslocar 3 posições para a direita os caracteres alfabéticos
    for (int i = 0; i < linha.size(); i++) {
        if (isalpha(linha[i])) {
            linha[i] = linha[i] + 3;
        }
    }

    // Segunda passada: inverter a string
    reverse(linha.begin(), linha.end());

    // Terceira passada: deslocar uma posição para a esquerda os caracteres da metade em diante
    int metade = linha.size() / 2;
    for (int i = metade; i < linha.size(); i++) {
        linha[i] = linha[i] - 1;
    }
}

int main() {
    int n;
    cin >> n;
    cin.ignore(); // ignorar o \n após o número de linhas

    while (n--) {
        string linha;
        getline(cin, linha);

        criptografar(linha);

        cout << linha << endl;
    }

    return 0;
}
