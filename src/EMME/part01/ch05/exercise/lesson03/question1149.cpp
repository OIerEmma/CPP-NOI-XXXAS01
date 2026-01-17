//
// Created by Emma on 2025/2/20.
//
#include<iostream>
#include<cstring>
using namespace std;

int main() {
    int maxn = 0;
    char many[200], s[200];
    while (cin >> s) {
        size_t len = strlen(s);
        if (s[len - 1] == '.') {
            s[len - 1] = '\0';
            len--;
        }
        if (len > maxn) {
            maxn = int(len);
            strcpy(many, s);
        }
    }
    cout << many << endl;
    return 0;
}
