//
// Created by Emme.Kwok on 2026/2/23.
//
#include<iostream>
#include<algorithm>
using namespace std;

const int maxn = 1005;
int a[maxn], p[maxn];

int main() {
    int n, k;
    cin >> n >> k;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    sort(a + 1, a + n + 1, greater<int>());
    for (int i = 1; i <= n; i++) {
        p[i] = p[i - 1] + a[i];
    }
    int ans = 0;
    for (int i = 1; i < n; i++) {
        for (int j = i + 1; j <= n; j++) {
            if (a[i] - a[j] <= k) {
                ans = max(ans, p[j] - p[i - 1]);
            }
        }
    }
    cout << ans << endl;
    return 0;
}