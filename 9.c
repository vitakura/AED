#include <iostream>
#include <vector>
#include <stack>

using namespace std;

void dfs(int startX, int startY, int N, int M, vector<vector<char>> &grid, vector<vector<bool>> &visited) {
    stack<pair<int, int>> s;
    s.push({startX, startY});
    visited[startX][startY] = true;
    
    int dx[] = {-1, 1, 0, 0}; // Direções de movimento
    int dy[] = {0, 0, -1, 1};

    while (!s.empty()) {
        auto [x, y] = s.top();
        s.pop();

        for (int i = 0; i < 4; ++i) {
            int newX = x + dx[i];
            int newY = y + dy[i];

            if (newX >= 0 && newX < N && newY >= 0 && newY < M && !visited[newX][newY] && grid[newX][newY] == '.') {
                visited[newX][newY] = true;
                s.push({newX, newY});
            }
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false); // Desabilita a sincronização do C++ com C para acelerar IO
    cin.tie(NULL); // Desvincula cin e cout para evitar flush desnecessário

    int N, M;
    cin >> N >> M;

    vector<vector<char>> grid(N, vector<char>(M));
    vector<vector<bool>> visited(N, vector<bool>(M, false));

    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < M; ++j) {
            cin >> grid[i][j];
        }
    }

    int regions = 0;

    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < M; ++j) {
            if (grid[i][j] == '.' && !visited[i][j]) {
                dfs(i, j, N, M, grid, visited);
                ++regions;
            }
        }
    }

    cout << regions << endl;

    return 0;
}