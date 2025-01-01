//
// Created by Emma on 2025/1/1.
//
#include<iostream>
using namespace std;

int main() {
    int n = 0, s = 0, m;
    cin >> m;
    while (s <= m) {
        ++n;
        s += n;
    }
    cout << n << endl;
    return 0;
}
