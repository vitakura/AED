#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class UnionFind {
public:
    vector<int> parent, rank;

    UnionFind(int n) {
        parent.resize(n);
        rank.resize(n, 0);
        for (int i = 0; i < n; ++i) {
            parent[i] = i;
        }
    }

    int find(int u) {
        if (u != parent[u]) {
            parent[u] = find(parent[u]);
        }
        return parent[u];
    }

    void unionSet(int u, int v) {
        int rootU = find(u);
        int rootV = find(v);

        if (rootU != rootV) {
            if (rank[rootU] > rank[rootV]) {
                parent[rootV] = rootU;
            } else if (rank[rootU] < rank[rootV]) {
                parent[rootU] = rootV;
            } else {
                parent[rootV] = rootU;
                ++rank[rootU];
            }
        }
    }
};

int main() {
    int R, C;
    cin >> R >> C;

    vector<tuple<int, int, int>> edges;

    for (int i = 0; i < C; ++i) {
        int V, W, P;
        cin >> V >> W >> P;
        edges.push_back({P, V - 1, W - 1});
    }

    // Ordenar as arestas pelo peso (custo)
    sort(edges.begin(), edges.end());

    UnionFind uf(R);
    int mst_cost = 0;

    for (auto &[cost, u, v] : edges) {
        if (uf.find(u) != uf.find(v)) {
            uf.unionSet(u, v);
            mst_cost += cost;
        }
    }

    cout << mst_cost << endl;

    return 0;
}
