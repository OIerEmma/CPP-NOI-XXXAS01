//
// Created by Emma on 2025/7/8.
//
#include<iostream>
using namespace std;

int a[10010];

int main() {
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    int ans = 0;
    for (int i = 0; i < n; i++) {
        for (int j = i; j < n; j++) {
            if (a[i] > a[j]) {
                swap(a[i], a[j]);
                ans++;
            }
        }
    }
    cout << ans << endl;
    return 0;
}