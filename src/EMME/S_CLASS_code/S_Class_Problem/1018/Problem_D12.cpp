//
// Created by Emma on 2025/8/3.
//
#include<iostream>
using namespace std;

int main() {
    long long s = 0, m, i = 1;
    cin >> m;
    while (s <= m) {
        s += i;
        i++;
    }
    cout << i - 1 << endl;
    return 0;
}