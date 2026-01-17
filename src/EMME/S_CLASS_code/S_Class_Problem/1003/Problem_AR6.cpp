//
// Created by Emma on 2025/7/5.
//
#include<iostream>
using namespace std;

int a[110];

int main() {
    int n, k;
    cin >> n >> k;
    int ans = 0;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        if (a[i] == k) {
            ans++;
        }
    }
    cout << ans << endl;
    return 0;
}