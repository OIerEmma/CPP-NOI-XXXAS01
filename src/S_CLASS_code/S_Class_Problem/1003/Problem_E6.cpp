//
// Created by Emma on 2025/6/30.
//
#include<iostream>
using namespace std;

int a[110];

int main() {
    int n, f;
    cin >> n;
    bool flag = true;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    cin >> f;
    for (int i = 0; i < n; i++) {
        if (a[i] == f) {
            flag = false;
            cout << i + 1 << endl;
            break;
        }
    }
    if (flag) {
        cout << -1 << endl;
    }
    return 0;
}