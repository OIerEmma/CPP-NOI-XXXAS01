//
// Created by Emma on 2025/7/7.
//
#include<iostream>
using namespace std;

int main() {
    int k;
    cin >> k;
    long long f0 = 1, f1 = 1, f2 = 1;
    for (int i = 2; i <= k; i++) {
        f2 = f0 + f1;
        f0 = f1;
        f1 = f2;
    }
    cout << f0 << endl;
    return 0;
}