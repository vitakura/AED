#include <iostream>
#include <map>
#include <iomanip>
#include <string>

using namespace std;

int main() {
    int T;
    string line;
    
    // Leitura do número de casos de teste
    getline(cin, line);
    T = stoi(line);
    getline(cin, line); // Linha em branco após o número de casos de teste
    
    for (int t = 0; t < T; ++t) {
        map<string, int> speciesCount;
        int totalTrees = 0;
        
        // Leitura das espécies até encontrar uma linha em branco
        while (getline(cin, line) && !line.empty()) {
            speciesCount[line]++;
            totalTrees++;
        }
        
        // Exibir o resultado para este caso de teste
        for (auto& species : speciesCount) {
            double percentage = (species.second * 100.0) / totalTrees;
            cout << species.first << " " << fixed << setprecision(4) << percentage << endl;
        }
        
        if (t < T - 1) {
            cout << endl; // Linha em branco entre casos de teste
        }
    }

    return 0;
}
