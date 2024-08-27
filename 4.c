#include <iostream>
#include <set>
#include <string>
#include <cctype>

int main() {
    std::set<std::string> dictionary;
    std::string word;
    char c;

    while (std::cin.get(c)) {
        if (isalpha(c)) {
            word += tolower(c);
        } else {
            if (!word.empty()) {
                dictionary.insert(word);
                word.clear();
            }
        }
    }

    // Adiciona a última palavra, se existir
    if (!word.empty()) {
        dictionary.insert(word);
    }

    for (const auto& w : dictionary) {
        std::cout << w << std::endl;
    }

    return 0;
}
