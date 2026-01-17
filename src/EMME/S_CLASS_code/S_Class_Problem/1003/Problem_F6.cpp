//
// Created by Emma on 2025/6/30.
//
#include<iostream>
#include<algorithm>
using namespace std;

int a[110];

int main() {
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    sort(a, a + n);
    int ans = n;
    for (int i = 0; i < n - 1; i++) {
        if (a[i] == a[i + 1]) {
            a[i + 1] = -1;
            ans--;
        }
    }
    cout << ans << endl;
    for (int i = 0; i < n; i++) {
        if (a[i] != -1) {
            cout << a[i] << endl;
        }
    }
    return 0;
}