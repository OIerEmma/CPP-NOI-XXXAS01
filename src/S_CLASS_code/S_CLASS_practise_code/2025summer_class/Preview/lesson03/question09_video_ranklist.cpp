//
// Created by Emma on 2025/7/12.
//
#include<iostream>
#include<algorithm>
using namespace std;

int a[10010];

int main() {
    int n, k;
    cin >> n >> k;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    for (int i = 1; i <= n; i++) {
        sort(a + 1, a + i + 1, greater<int>());
        if (i <= k) {
            cout << a[i] << endl;
        } else {
            cout << a[k] << endl;
        }
    }
    for (int i = 1; i <= k; i++) {
        cout << a[i] << " ";
    }
    return 0;
}

/*
10 3
200 300 400 500 600 600 0 300 200 100
*/