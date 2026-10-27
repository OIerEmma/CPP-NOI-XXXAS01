//
// Created by Geek.Kwok on 2026/10/26.
//
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int N = 100005;
int L, M, l, r;
bool a[N];

int main() {
    // freopen("xxx.in", "r", stdin);
    // freopen("xxx.out", "w", stdout);
    ios::sync_with_stdio(false);
    cin.tie(nullptr), cout.tie(nullptr);
    cin >> L >> M;
    for (int i = 1, l, r; i <= M; i++) {
        cin >> l >> r;
        for (int j = l; j <= r; j++) a[j] = true;
    }
    int cnt = 0;
    for (int i = 0; i <= L; i++)
        if (!a[i]) cnt++;
    cout << cnt << '\n';
    return 0;
}