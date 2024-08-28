#include <iostream>
#include <vector>

using namespace std;

class SegmentTree {
    vector<long long> tree, lazy;
    int n;

    void build(int node, int start, int end) {
        if (start == end) {
            tree[node] = 0;
        } else {
            int mid = (start + end) / 2;
            build(2*node, start, mid);
            build(2*node+1, mid+1, end);
            tree[node] = tree[2*node] + tree[2*node+1];
        }
    }

    void updateRange(int node, int start, int end, int l, int r, long long val) {
        if (lazy[node] != 0) {
            tree[node] += (end - start + 1) * lazy[node];
            if (start != end) {
                lazy[2*node] += lazy[node];
                lazy[2*node+1] += lazy[node];
            }
            lazy[node] = 0;
        }

        if (start > end or start > r or end < l)
            return;

        if (start >= l and end <= r) {
            tree[node] += (end - start + 1) * val;
            if (start != end) {
                lazy[2*node] += val;
                lazy[2*node+1] += val;
            }
            return;
        }

        int mid = (start + end) / 2;
        updateRange(2*node, start, mid, l, r, val);
        updateRange(2*node+1, mid+1, end, l, r, val);
        tree[node] = tree[2*node] + tree[2*node+1];
    }

    long long queryRange(int node, int start, int end, int l, int r) {
        if (lazy[node] != 0) {
            tree[node] += (end - start + 1) * lazy[node];
            if (start != end) {
                lazy[2*node] += lazy[node];
                lazy[2*node+1] += lazy[node];
            }
            lazy[node] = 0;
        }

        if (start > end or start > r or end < l)
            return 0;

        if (start >= l and end <= r)
            return tree[node];

        int mid = (start + end) / 2;
        long long p1 = queryRange(2*node, start, mid, l, r);
        long long p2 = queryRange(2*node+1, mid+1, end, l, r);
        return (p1 + p2);
    }

public:
    SegmentTree(int size) {
        n = size;
        tree.resize(4*n);
        lazy.resize(4*n);
        build(1, 0, n-1);
    }

    void update(int l, int r, long long val) {
        updateRange(1, 0, n-1, l, r, val);
    }

    long long query(int l, int r) {
        return queryRange(1, 0, n-1, l, r);
    }
};

int main() {
    int T;
    cin >> T;
    while (T--) {
        int N, C;
        cin >> N >> C;
        SegmentTree segTree(N);
        for (int i = 0; i < C; i++) {
            int type, p, q;
            cin >> type >> p >> q;
            if (type == 0) {
                long long v;
                cin >> v;
                segTree.update(p-1, q-1, v);
            } else {
                cout << segTree.query(p-1, q-1) << endl;
            }
        }
    }
    return 0;
}
