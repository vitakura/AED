#include <iostream>
#include <string>
using namespace std;

bool isSubsequence(const string& s, const string& r) {
    int j = 0;
    for (int i = 0; i < s.length() && j < r.length(); i++) {
        if (s[i] == r[j]) {
            j++;
        }
    }
    return j == r.length();
}

int main() {
    int N;
    cin >> N;
    while (N--) {
        string S;
        int Q;
        cin >> S >> Q;
        while (Q--) {
            string R;
            cin >> R;
            if (isSubsequence(S, R)) {
                cout << "Yes" << endl;
            } else {
                cout << "No" << endl;
            }
        }
    }
    return 0;
}
