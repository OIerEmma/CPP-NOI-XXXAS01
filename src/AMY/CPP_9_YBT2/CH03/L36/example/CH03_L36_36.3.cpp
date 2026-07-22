//
// Created by Amy on 2026/7/15.
//
#include<bits/stdc++.h>
using namespace std;
int n;
bool flag;

int main() {
    cin >> n;
    if (n == 1) {
        cout << "No";
        return 0;
    }
    if (n == 2) {
        cout << 2;
        return 0;
    }
    bool hp = false;
    for (int i = n; i >= 3; i--) {
        flag = true;
        for (int j = 2; j * j <= i; j++) {
            if (i % j == 0) {
                flag = false;
                break;
            }
        }
        if (flag) {
            cout << i;
            hp = true;
            break;
        }
    }
    if (!hp) cout << "No" << endl;
    return 0;
}
