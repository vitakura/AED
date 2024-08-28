#include <iostream>
#include <string>
#include <unordered_map>
using namespace std;

int main() {
    int M, N;
    unordered_map<string, int> hayPointDict;

    // Leitura do dicionário
    cin >> M >> N;
    for (int i = 0; i < M; ++i) {
        string word;
        int value;
        cin >> word >> value;
        hayPointDict[word] = value;
    }

    // Leitura e cálculo das descrições de cargos
    for (int i = 0; i < N; ++i) {
        int salary = 0;
        string word;
        while (cin >> word && word != ".") {
            if (hayPointDict.find(word) != hayPointDict.end()) {
                salary += hayPointDict[word];
            }
        }
        cout << salary << endl;
    }

    return 0;
}
