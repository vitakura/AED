#include <iostream>
#include <vector>
using namespace std;

int main() {
    int N;
    cin >> N;

    for (int i = 0; i < N; i++) {
        int M, C;
        cin >> M >> C;

        vector<vector<int>> hashTable(M);

        for (int j = 0; j < C; j++) {
            int key;
            cin >> key;
            int index = key % M;
            hashTable[index].push_back(key);
        }

        for (int k = 0; k < M; k++) {
            cout << k << " -> ";
            for (int j = 0; j < hashTable[k].size(); j++) {
                cout << hashTable[k][j] << " -> ";
            }
            cout << "\\" << endl;
        }

        if (i < N - 1) {
            cout << endl;
        }
    }

    return 0;
}
