#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

int main() {
    int n, m;
    while (cin >> n >> m) {
        vector<int> arr(n);
        unordered_map<int, vector<int>> occurrences;

        // Leitura do vetor e armazenamento das ocorrências
        for (int i = 0; i < n; ++i) {
            cin >> arr[i];
            occurrences[arr[i]].push_back(i + 1); // Guarda a posição 1-indexed
        }

        // Processamento das consultas
        for (int i = 0; i < m; ++i) {
            int k, v;
            cin >> k >> v;
            if (occurrences[v].size() >= k) {
                cout << occurrences[v][k - 1] << endl;
            } else {
                cout << 0 << endl;
            }
        }
    }

    return 0;
}
