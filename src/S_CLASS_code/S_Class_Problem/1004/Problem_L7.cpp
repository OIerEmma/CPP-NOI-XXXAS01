//
// Created by Emma on 2025/7/6.
//
#include<iostream>
using namespace std;

int ackmann(int m, int n) {
    if (m == 0) {
        return n + 1;
    } else if (n == 0) {
        return ackmann(m - 1, 1);
    }
    return ackmann(m - 1, ackmann(m, n - 1));
}

int main() {
    int n, m;
    cin >> m >> n;
    cout << ackmann(m, n) << endl;
    return 0;
}