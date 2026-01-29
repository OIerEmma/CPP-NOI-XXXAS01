//
// Created by Emma on 2025/1/18.
//
#include<iostream>
using namespace std;

int main() {
    int n, m, b[101], c = 0;
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> b[i];
    }
    cin >> m;
    for (int i = 1; i <= n; i++) {
        if (b[i] == m) {
            c++;
        }
    }
    cout << c;
}