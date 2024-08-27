#include <iostream>
#include <string>
#include <map>
#include <vector>
#include <algorithm>

using namespace std;

struct CharFrequency {
    int ascii_value;
    int frequency;
};

bool compare(CharFrequency a, CharFrequency b) {
    if (a.frequency == b.frequency)
        return a.ascii_value > b.ascii_value;
    return a.frequency < b.frequency;
}

int main() {
    string line;
    bool first_case = true;
    while (getline(cin, line)) {
        if (!first_case) {
            cout << endl;
        }
        first_case = false;

        map<int, int> frequency_map;

        // Calcula a frequência dos caracteres
        for (char c : line) {
            frequency_map[(int)c]++;
        }

        vector<CharFrequency> frequencies;

        // Prepara o vetor de frequências
        for (auto it = frequency_map.begin(); it != frequency_map.end(); ++it) {
            CharFrequency cf = {it->first, it->second};
            frequencies.push_back(cf);
        }

        // Ordena conforme as regras
        sort(frequencies.begin(), frequencies.end(), compare);

        // Imprime o resultado
        for (CharFrequency cf : frequencies) {
            cout << cf.ascii_value << " " << cf.frequency << endl;
        }
    }

    return 0;
}
