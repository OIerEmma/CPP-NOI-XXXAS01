//
// Created by Amy on 2026/7/17.
//
#include <iostream>
#include <cmath>
using namespace std;

int main() {
    int n;
    cin >> n;

    int size = 2 * n - 1;

    for (int i = 0; i < size; i++) {
        int dist = abs(n - 1 - i);
        int left = dist;
        int right = size - 1 - dist;

        for (int j = 0; j < size; j++) {
            if (j == left || j == right) {
                cout << '*';
            } else {
                cout << ' ';
            }
        }
        cout << endl;
    }

    return 0;
}