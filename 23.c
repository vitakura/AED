#include <iostream>
#include <vector>
using namespace std;

struct SegmentTree {
    vector<int> tree;
    int n;

    SegmentTree(const vector<int>& data) {
        n = data.size();
        tree.resize(2 * n);
        build(data);
    }

    void build(const vector<int>& data) {
        for (int i = 0; i < n; i++)
            tree[n + i] = (data[i] > 0) ? 1 : (data[i] < 0) ? -1 : 0;
        for (int i = n - 1; i > 0; --i)
            tree[i] = tree[2 * i] * tree[2 * i + 1];
    }

    void update(int pos, int value) {
        pos += n;
        tree[pos] = (value > 0) ? 1 : (value < 0) ? -1 : 0;
        for (pos /= 2; pos > 0; pos /= 2)
            tree[pos] = tree[2 * pos] * tree[2 * pos + 1];
    }

    int query(int l, int r) {
        l += n;
        r += n + 1;
        int result = 1;
        while (l < r) {
            if (l % 2 == 1) result *= tree[l++];
            if (r % 2 == 1) result *= tree[--r];
            l /= 2;
            r /= 2;
        }
        return result;
    }
};

int main() {
    int N, K;
    while (cin >> N >> K) {
        vector<int> data(N);
        for (int i = 0; i < N; i++) {
            cin >> data[i];
        }

        SegmentTree segTree(data);
        string result = "";

        for (int i = 0; i < K; i++) {
            char command;
            int x, y;
            cin >> command >> x >> y;
            if (command == 'C') {
                segTree.update(x - 1, y);
            } else if (command == 'P') {
                int product = segTree.query(x - 1, y - 1);
                if (product > 0) result += "+";
                else if (product < 0) result += "-";
                else result += "0";
            }
        }

        cout << result << endl;
    }

    return 0;
}
