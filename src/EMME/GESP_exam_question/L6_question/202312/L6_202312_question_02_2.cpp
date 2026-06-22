//
// Created by Emme.Kwok on 2026/6/21.
//
#include<iostream>
#include<algorithm>
#include<cstring>
using namespace std;

const int N = 305;
int fa[N], cnt[N];

int main() {
    int n;
    cin >> n;
    fa[0] = -1;
    for (int i = 1; i < n; i++) cin >> fa[i];
    int q;
    cin >> q;
    while (q--) {
        memset(cnt, 0, sizeof(cnt));
        int m;
        cin >> m;
        for (int i = 0; i < m; i++) {
            int p;
            cin >> p;
            for (int j = p; j != -1; j = fa[j]) cnt[j]++;
        }
        int ans = -1;
        for (int i = n - 1; i >= 0; i--)
            if (cnt[i] == m) { ans = i; break; }
        cout << ans << endl;
    }
    return 0;
}