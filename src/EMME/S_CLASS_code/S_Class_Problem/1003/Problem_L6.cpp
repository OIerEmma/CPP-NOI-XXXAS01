//
// Created by Emma on 2025/7/1.
//
#include<iostream>
using namespace std;

bool a[10010];

int main() {
    int l, m;
    cin >> l >> m;
    int x, y;
    for (int i = 1; i <= m; i++) {
        cin >> x >> y;
        for (int j = x; j <= y; j++) {
            a[j] = true;
        }
    }
    int sum = 0;
    for (int i = 0; i <= l; i++) {
        if (!a[i]) {
            sum++;
        }
    }
    cout << sum << endl;
    return 0;
}