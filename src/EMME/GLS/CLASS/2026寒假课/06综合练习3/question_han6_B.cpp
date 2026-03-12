//
// Created by Emme.Kwok on 2026/2/5.
//
#include<iostream>
#include<cstdio>
using namespace std;

const int maxn = 100005;
int arr[maxn];

int main() {
    freopen("b.in", "r", stdin);
    freopen("b.out", "w", stdout);
    int n, k;
    cin >> n >> k;
    for (int i = 1; i <= n; i++) {
        cin >> arr[i];
    }
    int cnt = 0, i = 0;
    long long ans = 0;
    while (cnt < k) {
        i++;
        if (arr[i] < 0) {
            continue;
        }
        cnt++;
        if (cnt == 1) {
            ans += arr[i];
        } else {
            ans += arr[i] - arr[i - 1];
        }
    }
    cout << ans << endl;
    return 0;
}