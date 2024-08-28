#include <iostream>
#include <string>
#include <set>

using namespace std;

int main() {
    int N;
    cin >> N;
    cin.ignore();  // Ignorar o newline após o número de casos de teste

    while (N--) {
        string frase;
        getline(cin, frase);

        set<char> letras;
        
        // Percorrer cada caractere da frase
        for (char c : frase) {
            if (isalpha(c)) {  // Verifica se o caractere é uma letra
                letras.insert(tolower(c));  // Insere a letra em minúsculo no conjunto
            }
        }

        int totalLetras = letras.size();

        if (totalLetras == 26) {
            cout << "frase completa" << endl;
        } else if (totalLetras >= 13) {
            cout << "frase quase completa" << endl;
        } else {
            cout << "frase mal elaborada" << endl;
        }
    }

    return 0;
}
