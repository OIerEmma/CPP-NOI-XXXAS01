//
// Created by Emme.Kwok on 2026/9/20.
//
#include<bits/stdc++.h>
using namespace std;

// 0代表输，1代表赢，2代表平（针对player1来说）
const int f[5][5] {
    {2, 0, 1, 1, 0},
    {1, 2, 0, 1, 0},
    {0, 1, 2, 0, 1},
    {0, 0, 1, 2, 1},
    {1, 1, 0, 0, 2}
};
int sa[205], sb[205];

int main() {
    // freopen("E_RPSLS.in", "r", stdin);
    // freopen("E_RPSLS.out", "w", stdout);
    ios::sync_with_stdio(false);
    cin.tie(nullptr), cout.tie(nullptr);
    int n, a, b, ansa = 0, ansb = 0, pa = 0, pb = 0;
    cin >> n >> a >> b;
    for (int i = 0; i < a; i++) cin >> sa[i];
    for (int i = 0; i < b; i++) cin >> sb[i];
    while (n--) {
        if (f[sa[pa]][sb[pb]] == 1) ansa++;
        else if (f[sa[pa]][sb[pb]] == 0) ansb++;
        pa = (pa + 1) % a;
        pb = (pb + 1) % b;
    }
    cout << ansa << " " << ansb << endl;
    return 0;
}