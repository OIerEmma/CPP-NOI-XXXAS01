//
// Created by Emma on 2025/8/20.
//
#include<iostream>
#include<cstring>
using namespace std;

long long stackk[301];
string s;

long long comp() {
    int i = 0, top = 0;
    memset(stackk, 0, sizeof(stackk));
    if (s.size() <= 1) {
        return 0;
    }
    // s.size() - 1
    // 16 9 4 3 +*-@@ dfs @#ddk
    while (s[i] != '@') {
        switch (s[i]) {
            case '+':
                top--;
                stackk[top] += stackk[top + 1];
                break;
            case '-':
                top--;
                stackk[top] -= stackk[top + 1];
                break;
            case '*':
                top--;
                stackk[top] *= stackk[top + 1];
                break;
            case '/':
                top--;
                stackk[top] /= stackk[top + 1];
                break;
            default:
                long long x = 0;
                while (s[i] != ' ') {
                    x = x * 10 + (s[i++] - '0');
                }
                stackk[++top] = x;
                break;
        }
        i++;
        // cout << stackk[top] << endl;
    }
    return stackk[top];
}

int main() {
    getline(cin, s);
    cout << comp() << endl;
    return 0;
}
