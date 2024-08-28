#include <iostream>
#include <string>

using namespace std;

int main() {
    int N;
    cin >> N;
    cin.ignore(); // Ignorar o caractere de nova linha após a leitura de N

    while (N--) {
        string palavra;
        getline(cin, palavra);

        if (palavra.length() == 5) {
            cout << 3 << endl; // A única palavra de 5 letras é "three", representando o número 3
        } else {
            int count_one = 0, count_two = 0;
            if (palavra[0] == 'o') count_one++;
            if (palavra[1] == 'n') count_one++;
            if (palavra[2] == 'e') count_one++;

            if (palavra[0] == 't') count_two++;
            if (palavra[1] == 'w') count_two++;
            if (palavra[2] == 'o') count_two++;

            if (count_one >= 2) {
                cout << 1 << endl;
            } else if (count_two >= 2) {
                cout << 2 << endl;
            }
        }
    }

    return 0;
}
