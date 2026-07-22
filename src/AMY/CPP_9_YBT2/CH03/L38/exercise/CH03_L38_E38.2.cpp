//
// Created by Amy on 2026/7/17.
//
#include <iostream>
using namespace std;

int main() {
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j < i; j++) cout << ' ';
        cout << '*';
        if (i < n) {
            for (int j = 0; j < 2 * (n - i) - 1; j++) cout << ' ';
            cout << '*';
        }
        cout << '\n';
    }
    for (int i = n + 1; i <= 2 * n - 1; i++) {
        for (int j = 1; j < n; j++) cout << ' ';
        cout << "*\n";
    }
    return 0;
}
