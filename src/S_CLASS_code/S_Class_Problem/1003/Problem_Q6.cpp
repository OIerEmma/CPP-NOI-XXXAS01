//
// Created by Emma on 2025/7/1.
//
#include<iostream>
using namespace std;

bool lamp[5010];

int main() {
    int n, m;
    cin >> n >> m;
    for (int i = 2; i <= m; i++) {
        for (int j = i; j <= n; j += i) {
            lamp[j] = !lamp[j];
        }
    }
    bool flag = false;
    for (int i = 1; i <= n; i++) {
        if (!lamp[i]) {
            if (flag) {
                cout << "," << i;
            } else {
                cout << i;
                flag = true;
            }
        }
    }
    return 0;
}