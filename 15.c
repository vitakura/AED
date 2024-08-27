#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

bool customSort(int a, int b, int M) {
    int modA = a % M;
    int modB = b % M;

    // Se os restos são diferentes, ordenar pelo resto
    if (modA != modB)
        return modA < modB;

    // Se os restos são iguais, ordenar ímpares antes de pares
    if ((a % 2 != 0) && (b % 2 == 0))
        return true;
    if ((a % 2 == 0) && (b % 2 != 0))
        return false;

    // Se ambos são ímpares, o maior vem primeiro
    if ((a % 2 != 0) && (b % 2 != 0))
        return a > b;

    // Se ambos são pares, o menor vem primeiro
    if ((a % 2 == 0) && (b % 2 == 0))
        return a < b;

    // Caso não se encaixe em nenhuma das condições acima (não deve acontecer)
    return false;
}

int main() {
    int N, M;
    while (cin >> N >> M) {
        if (N == 0 && M == 0) break;

        vector<int> numbers(N);
        for (int i = 0; i < N; i++) {
            cin >> numbers[i];
        }

        sort(numbers.begin(), numbers.end(), [M](int a, int b) {
            return customSort(a, b, M);
        });

        cout << N << " " << M << endl;
        for (int i = 0; i < N; i++) {
            cout << numbers[i] << endl;
        }
    }
    cout << "0 0" << endl;
    return 0;
}
