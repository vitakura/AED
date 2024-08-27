#include <iostream>
#include <vector>
#include <algorithm>

int main() {
    int N, K;
    std::cin >> N >> K;
    
    std::vector<std::string> alunos(N);
    
    for (int i = 0; i < N; i++) {
        std::cin >> alunos[i];
    }
    
    // Ordena a lista de alunos em ordem alfabética
    std::sort(alunos.begin(), alunos.end());
    
    // Imprime o aluno correspondente ao número K
    std::cout << alunos[K-1] << std::endl;
    
    return 0;
}
