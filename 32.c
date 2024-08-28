#include <iostream>
#include <string>

using namespace std;

int main() {
    string linha;

    // Leitura de várias linhas até o fim da entrada (EOF)
    while (getline(cin, linha)) {
        bool maiuscula = true;

        for (char& c : linha) {
            if (isalpha(c)) { // Verifica se o caractere é uma letra
                if (maiuscula) {
                    c = toupper(c);
                } else {
                    c = tolower(c);
                }
                maiuscula = !maiuscula; // Alterna entre maiúscula e minúscula
            }
            // Espaços são mantidos sem alteração
        }

        // Imprime a linha modificada
        cout << linha << endl;
    }

    return 0;
}
