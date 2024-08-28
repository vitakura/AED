#include <iostream>
#include <string>

using namespace std;

int main() {
    int N;
    cin >> N;

    // Mapeamento do número de LEDs necessários para cada dígito
    int ledsPorDigito[10] = {6, 2, 5, 5, 4, 5, 6, 3, 7, 6};

    while (N--) {
        string numero;
        cin >> numero;

        int totalLeds = 0;
        for (char c : numero) {
            totalLeds += ledsPorDigito[c - '0']; // '0' é 48 na tabela ASCII, então c - '0' converte para o índice correto
        }

        cout << totalLeds << " leds" << endl;
    }

    return 0;
}
