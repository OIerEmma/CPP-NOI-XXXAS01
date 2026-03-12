//
// Created by Amy on 2026/1/25.
//
#include <iostream>
using namespace std;

int main() {
    int n;
    cin >> n;
    long long sum = 0;
    for (int i = 1; i <= n; i++) {
        sum += i * (i + 1) / 2;
    }
    cout << sum << endl;

    return 0;
}
