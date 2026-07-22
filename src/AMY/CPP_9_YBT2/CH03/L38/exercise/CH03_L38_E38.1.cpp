//
// Created by Amy on 2026/7/17.
//
#include <iostream>
using namespace std;

int main() {
    int n;
    cin >> n;
    int size = 2 * n - 1;
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            cout << "*";
        }
        cout << "\n";
    }
    return 0;
}
