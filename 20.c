#include <iostream>
#include <string>
#include <unordered_map>

using namespace std;

int main() {
    unordered_map<char, double> duration = {
        {'W', 1.0},
        {'H', 0.5},
        {'Q', 0.25},
        {'E', 0.125},
        {'S', 0.0625},
        {'T', 0.03125},
        {'X', 0.015625}
    };

    string line;
    while (getline(cin, line) && line != "*") {
        int correctMeasures = 0;
        double currentDuration = 0.0;

        for (char c : line) {
            if (c == '/') {
                if (currentDuration == 1.0) {
                    correctMeasures++;
                }
                currentDuration = 0.0;
            } else {
                currentDuration += duration[c];
            }
        }

        cout << correctMeasures << endl;
    }

    return 0;
}
