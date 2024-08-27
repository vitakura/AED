#include <iostream>
#include <vector>

using namespace std;

int main() {
    int N, P;
    cin >> N >> P;

    vector<vector<int>> board(N + 1, vector<int>(N + 1, 0));
    vector<vector<int>> black_acc(N + 1, vector<int>(N + 1, 0));
    vector<vector<int>> white_acc(N + 1, vector<int>(N + 1, 0));

    // Preenche o tabuleiro com as pedras pretas e brancas e constrói matrizes acumuladas
    for (int i = 0; i < P; ++i) {
        int L, C;
        cin >> L >> C;
        board[L][C] = 1;  // Pedra preta
    }
    for (int i = 0; i < P; ++i) {
        int L, C;
        cin >> L >> C;
        board[L][C] = 2;  // Pedra branca
    }

    // Construindo matrizes acumuladas
    for (int i = 1; i <= N; ++i) {
        for (int j = 1; j <= N; ++j) {
            black_acc[i][j] = black_acc[i - 1][j] + black_acc[i][j - 1] - black_acc[i - 1][j - 1] + (board[i][j] == 1 ? 1 : 0);
            white_acc[i][j] = white_acc[i - 1][j] + white_acc[i][j - 1] - white_acc[i - 1][j - 1] + (board[i][j] == 2 ? 1 : 0);
        }
    }

    int blackAreas = 0, whiteAreas = 0;

    // Verifica sub-áreas de tamanho 1 a N
    for (int size = 1; size <= N; ++size) {
        for (int row = 1; row + size - 1 <= N; ++row) {
            for (int col = 1; col + size - 1 <= N; ++col) {
                int r2 = row + size - 1;
                int c2 = col + size - 1;
                int blackCount = black_acc[r2][c2] - black_acc[row - 1][c2] - black_acc[r2][col - 1] + black_acc[row - 1][col - 1];
                int whiteCount = white_acc[r2][c2] - white_acc[row - 1][c2] - white_acc[r2][col - 1] + white_acc[row - 1][col - 1];

                if (blackCount > 0 && whiteCount == 0) {
                    blackAreas++;
                }
                if (whiteCount > 0 && blackCount == 0) {
                    whiteAreas++;
                }
            }
        }
    }

    cout << blackAreas << " " << whiteAreas << endl;

    return 0;
}