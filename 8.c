#include <iostream>
#include <stack>
#include <cstdio> // Para usar scanf e printf

using namespace std;

int main() {
    int N;
    scanf("%d", &N);

    stack<int> mainStack;
    stack<int> minStack;

    char command[5]; // Para armazenar os comandos PUSH, POP, MIN

    for (int i = 0; i < N; ++i) {
        scanf("%s", command);

        if (command[1] == 'U') { // "PUSH"
            int value;
            scanf("%d", &value);
            mainStack.push(value);

            if (minStack.empty() || value <= minStack.top()) {
                minStack.push(value);
            }
        } else if (command[0] == 'P') { // "POP"
            if (mainStack.empty()) {
                printf("EMPTY\n");
            } else {
                if (mainStack.top() == minStack.top()) {
                    minStack.pop();
                }
                mainStack.pop();
            }
        } else if (command[0] == 'M') { // "MIN"
            if (minStack.empty()) {
                printf("EMPTY\n");
            } else {
                printf("%d\n", minStack.top());
            }
        }
    }

    return 0;
}
