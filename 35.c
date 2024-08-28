#include <iostream>
#include <string>

using namespace std;

int main() {
    int N;
    cin >> N;

    while (N--) {
        string s1, s2;
        cin >> s1 >> s2;

        string resultado;
        int i = 0, j = 0;

        // Combina as duas strings alternando as letras
        while (i < s1.size() && j < s2.size()) {
            resultado += s1[i++];
            resultado += s2[j++];
        }

        // Adiciona os caracteres restantes da string mais longa
        while (i < s1.size()) {
            resultado += s1[i++];
        }

        while (j < s2.size()) {
            resultado += s2[j++];
        }

        cout << resultado << endl;
    }

    return 0;
}
