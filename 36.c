#include <iostream>
#include <string>

using namespace std;

int main() {
    int N;
    cin >> N;

    while (N--) {
        string A, B;
        cin >> A >> B;

        if (A.size() >= B.size() && A.substr(A.size() - B.size()) == B) {
            cout << "encaixa" << endl;
        } else {
            cout << "nao encaixa" << endl;
        }
    }

    return 0;
}
