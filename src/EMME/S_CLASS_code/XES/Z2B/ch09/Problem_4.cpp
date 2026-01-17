//
// Created by Emme.Kwok on 2026/1/10.
//
#include<iostream>
using namespace std;

int n, k, a[35], cnt;

void dfs(int step) {
    if (step == n + 1) {
        cnt++;
        if (cnt == k) {
            for (int i = 1; i <= n; i++) {
                cout << a[i];
            }
            exit(0);
        }
        return;
    }
    for (int i = a[step - 1]; i <= 9; i++) {
        a[step] = i;
        dfs(step + 1);
    }
}

int main() {
    cin >> n >> k;
    a[0] = 1;
    dfs(1);
    return 0;
}