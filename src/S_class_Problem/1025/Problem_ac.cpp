//
// Created by Emma on 2025/1/17.
//
#include<iostream>
using namespace std;
bool a[10005];
int main() {
    int l, m, x, y, sum = 0;
    cin >> l >> m;
    for (int i = 1; i <= m; i++) {
        cin >> x >> y;
        for (int j = x; j <= y; j++) {
            a[j] = 1;
        }
    }
    for (int i = 0; i <= l; i++) {
        if (!a[i]) {
            sum++;
        }
    }
    cout << sum << endl;
    return 0;
}