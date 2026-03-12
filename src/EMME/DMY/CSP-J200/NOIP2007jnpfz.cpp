//
// Created by Emme.Kwok on 2026/1/25.
//
#include<iostream>
using namespace std;

const int maxn = 3 * 1e4 + 3, maxw = 205;
int b[maxw], a[maxn];

int main() {
    int w, n, x;
    cin >> w >> n;
    for (int i = 1; i <= n; i++) {
        cin >> x;
        b[x]++;
    }
    int cnt = 0;
    for (int i = 5; i <= w; i++) {
        for (int j = 1; j <= b[i]; j++) {
            a[++cnt] = i;
        }
    }
    int ans = n, i = 1;
    for (int j = n; j > i; j--) {
        if (a[i] + a[j] <= w) {
            ans--;
            i++;
        }
    }
    cout << ans << endl;
    return 0;
}