//
// Created by Emma on 2025/2/8.
//
#include<iostream>
using namespace std;

int main() {
    char c[200];
    char a, b;
    int i, n = 0;
    while ((c[n++] = getchar()) != '\n');
    a = getchar();
    getchar();
    b = getchar();
    for (i = 0; i < n; i++) {
        if (c[i] == a) cout << b;
        else cout << c[i];
    }
    cout << endl;
    return 0;
}
