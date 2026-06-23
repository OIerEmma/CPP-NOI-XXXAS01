//
// Created by Emme.Kwok on 2026/6/23.
//
#include<algorithm>
#include<iostream>
#include<vector>
using namespace std;

int n;
const int N = 15;
vector<int> a(N), b(N), p;

int main() {
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) cin >> a[i];
    for (int i = 0; i < n; i++) cin >> b[i];
    for (int i = 0; i < n; i++) p.push_back(i);
    int res = 1e9;
    do {
        int ans = n;
        for (int i = 1; i < n; i++)
            ans += max(b[p[i - 1]], a[p[i]]);
        res = min(res, ans);
    } while (next_permutation(p.begin(), p.end()));
    cout << res << endl;
    return 0;
}