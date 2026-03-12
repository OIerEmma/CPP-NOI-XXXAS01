//
// Created by Emme.Kwok on 2026/3/1.
//
#include<iostream>
using namespace std;

int a[100005], n;

bool check(int x) {
    int b[100005], cur = 0;
    for (int i = 1; i <= n; i++) {
        if (a[i] > x) {
            b[++cur] = a[i];
        }
    }
    for (int i = 1; i <= cur; i += 2) {
        if (b[i] != b[i + 1]) {
            return false;
        }
    }
    return true;
}

int main() {
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    int l = 1, r = 1e5, ans = 0;
    while (l <= r) {
        int mid = l + (r - l) / 2;
        if (check(mid)) {
            r = mid - 1;
            ans = mid;
        } else {
            l = mid + 1;
        }
    }
    cout << ans << endl;
    return 0;
}