//
// Created by Emma on 2025/7/6.
//
#include<iostream>
#include<cstring>
using namespace std;

int a[1010], b[1010];

int main() {
    int n, m;
    cin >> m >> n;
    memset(b, -1, sizeof(b));
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    int ans = 0, idx = 0, len = 0;
    for (int i = 0; i < n; i++) {
        int j;
        for (j = 0; j < len; j++) {
            if (a[i] == b[j]) {
                break;
            }
        }
        if (j == len) {
            ans++;
            if (b[idx] == -1) {
                len++;
            }
            b[idx++] = a[i];
            idx %= m;
        }
    }
    cout << ans << endl;
    return 0;
}