//
// Created by Emme.Kwok on 2026/9/21.
//
#include<bits/stdc++.h>
using namespace std;

bool flag[105];

int main() {
    int n, m, pos = 0, s;
    cin >> n >> m;
    s = n;
    while (s--) {
        for (int i = 1; i <= m;) {
            if (!flag[pos]) i++;
            pos = (pos + 1) % n;
        }
        int now = pos == 0 ? n - 1 : pos - 1;
        flag[now] = true;
        cout << now + 1 << " ";
    }
    return 0;
}