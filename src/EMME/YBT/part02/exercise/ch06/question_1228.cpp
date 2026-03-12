//
// Created by Emme.Kwok on 2026/1/29.
//
#include<iostream>
#include<algorithm>
using namespace std;

const int maxn = 2e4 + 3;
int h[maxn];

int main() {
    int n, b;
    cin >> n >> b;
    int sum = 0;
    for (int i = 1; i <= n; i++) {
        cin >> h[i];
        sum += h[i];
    }
    if (sum < b) {
        cout << -1 << endl;
    } else if (sum == b) {
        cout << n << endl;
    } else {
        sort(h + 1, h + n + 1, greater<int>());
        int ans = 0, nowh = 0, i = 1;
        while (nowh < b) {
            ans++;
            nowh += h[i];
            i++;
        }
        cout << ans << endl;
    }
    return 0;
}