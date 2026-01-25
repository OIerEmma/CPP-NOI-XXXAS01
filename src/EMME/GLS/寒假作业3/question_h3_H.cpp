//
// Created by Emme.Kwok on 2026/1/24.
//
#include<iostream>
using namespace std;

const int maxn = 1005;
int a[maxn], b[maxn];

int main() {
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> a[i] >> b[i];
    }
    int ans = 2 * 1e5 + 1;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            if (i == j) {
                ans = min(a[i] + b[j], ans);
            } else {
                ans = min(max(a[i], b[j]), ans);
            }
        }
    }
    cout << ans << endl;
    return 0;
}