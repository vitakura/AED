#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main() {
    int N;
    cin >> N;
    
    while (N--) {
        int K;
        cin >> K;
        
        vector<string> languages(K);
        for (int i = 0; i < K; i++) {
            cin >> languages[i];
        }
        
        bool same_language = true;
        for (int i = 1; i < K; i++) {
            if (languages[i] != languages[0]) {
                same_language = false;
                break;
            }
        }
        
        if (same_language) {
            cout << languages[0] << endl;
        } else {
            cout << "ingles" << endl;
        }
    }
    
    return 0;
}
