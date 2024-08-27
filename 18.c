#include <iostream>
#include <vector>
#include <algorithm>
#include <tuple>

using namespace std;

int main() {
    int t;
    cin >> t;

    for (int i = 0; i < t; ++i) {
        int n, v, a;
        cin >> n >> v >> a;

        vector<int> arestas;

        for (int j = 0; j < a; ++j) {
            int x, y;
            cin >> x >> y;

            // Adicionando as arestas (x*v + y) e (y*v + x)
            arestas.push_back(x * v + y);
            arestas.push_back(y * v + x);
        }

        // Ordenar as arestas
        sort(arestas.begin(), arestas.end());

        // Contando o número de componentes diferentes
        int componentes = 1;
        for (size_t k = 1; k < arestas.size(); ++k) {
            if (arestas[k] != arestas[k-1]) {
                componentes++;
            }
        }

        // Saída do número de componentes
        cout << componentes << endl;
    }

    return 0;
}
