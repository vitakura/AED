#include <iostream>
#include <sstream>
#include <vector>
#include <algorithm>

bool compare(const std::string &a, const std::string &b) {
    if (a.size() == b.size()) {
        return false; // mantém a ordem original
    }
    return a.size() > b.size();
}

int main() {
    int n;
    std::string line;

    std::cin >> n;
    std::cin.ignore(); // Ignora o newline após o número de casos

    while (n--) {
        std::getline(std::cin, line);

        std::vector<std::string> words;
        std::stringstream ss(line);
        std::string word;

        while (ss >> word) {
            words.push_back(word);
        }

        std::stable_sort(words.begin(), words.end(), compare);

        for (size_t i = 0; i < words.size(); ++i) {
            std::cout << words[i];
            if (i < words.size() - 1) {
                std::cout << " ";
            }
        }
        std::cout << std::endl;
    }

    return 0;
}
