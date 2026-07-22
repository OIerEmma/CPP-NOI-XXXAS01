//
// Created by Amy on 2026/7/11.
//
#include <iostream>
using namespace std;

int main() {
    int N, K;
    cin >> N >> K;
    double price = 200;
    for (int i = 1; i <= 20; i++) {
        if (i * N >= price) {
            cout << i << endl;
            return 0;
        }
        price *= (1 + K / 100.0);
    }
    cout << "Impossible" << endl;
    return 0;
}