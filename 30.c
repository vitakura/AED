#include <iostream>
#include <vector>
#include <string>
#include <cmath>

using namespace std;

int main() {
    int N, L, C;

    // Leitura dos dados de entrada
    while (cin >> N >> L >> C) {
        cin.ignore(); // Ignorar o \n após a leitura de números

        string linha;
        getline(cin, linha);

        vector<string> palavras;
        string palavra;

        // Separar as palavras da linha
        for (char ch : linha) {
            if (ch == ' ') {
                palavras.push_back(palavra);
                palavra.clear();
            } else {
                palavra += ch;
            }
        }
        palavras.push_back(palavra);  // Adiciona a última palavra

        int linhas_usadas = 1, caracteres_na_linha = 0;

        for (string& p : palavras) {
            int tamanho_palavra = p.length();

            // Se adicionar a palavra na linha atual excede o limite de caracteres
            if (caracteres_na_linha + tamanho_palavra > C) {
                linhas_usadas++;
                caracteres_na_linha = tamanho_palavra;  // Começa uma nova linha com esta palavra
            } else {
                caracteres_na_linha += tamanho_palavra;
            }

            // Acrescenta o espaço entre as palavras, exceto após a última palavra da linha
            if (caracteres_na_linha + 1 <= C) {
                caracteres_na_linha++;
            }
        }

        // Calcula o número de páginas necessárias
        int paginas = ceil(static_cast<double>(linhas_usadas) / L);

        // Saída do resultado
        cout << paginas << endl;
    }

    return 0;
}
