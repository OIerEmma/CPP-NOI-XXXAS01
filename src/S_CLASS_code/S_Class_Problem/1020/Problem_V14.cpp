//
// Created by Emma on 2025/8/11.
//
#include<iostream>
using namespace std;

int main() {
    int n;
    cin >> n;
    int f1 = 1, f2 = 2, f3 = 3;
    for (int i = 3; i <= n; i++) {
        f3 = f1 + f2;
        f1 = f2;
        f2 = f3;
    }
    cout << f3 << endl;
    return 0;
}