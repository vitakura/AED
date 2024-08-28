#include <iostream>
#include <string>
#include <algorithm>
#include <vector>

using namespace std;

// Função para encontrar o tamanho da maior substring comum entre duas strings
int maiorSubstringComum(const string& s1, const string& s2) {
    int m = s1.length();
    int n = s2.length();
    int maxLength = 0;

    // Tabela para armazenar o comprimento das substrings
    vector<vector<int>> dp(m + 1, vector<int>(n + 1, 0));

    for (int i = 1; i <= m; i++) {
        for (int j = 1; j <= n; j++) {
            if (s1[i - 1] == s2[j - 1]) {
                dp[i][j] = dp[i - 1][j - 1] + 1;
                maxLength = max(maxLength, dp[i][j]);
            }
        }
    }

    return maxLength;
}

int main() {
    string s1, s2;

    // Processa cada par de strings até o final da entrada
    while (getline(cin, s1) && getline(cin, s2)) {
        int resultado = maiorSubstringComum(s1, s2);
        cout << resultado << endl;
    }

    return 0;
}
