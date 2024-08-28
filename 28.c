#include <iostream>
#include <string>

using namespace std;

int main() {
    while (true) {
        char D;
        string N;
        cin >> D >> N;
        
        // Condição de parada: D e N são ambos zero
        if (D == '0' && N == "0") break;

        // Remover todas as ocorrências do dígito D de N
        string resultado;
        for (char c : N) {
            if (c != D) {
                resultado += c;
            }
        }

        // Remover zeros à esquerda
        int primeiro_digito_nao_zero = 0;
        while (primeiro_digito_nao_zero < resultado.size() && resultado[primeiro_digito_nao_zero] == '0') {
            primeiro_digito_nao_zero++;
        }
        resultado = resultado.substr(primeiro_digito_nao_zero);

        // Se o resultado for vazio, significa que todos os dígitos foram removidos ou a string original era composta apenas de zeros
        if (resultado.empty()) {
            resultado = "0";
        }

        // Imprimir o resultado final
        cout << resultado << endl;
    }

    return 0;
}
