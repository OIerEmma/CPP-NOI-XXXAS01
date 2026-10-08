//
// Created by Emme.Kwok on 2026/9/30.
//
#include<bits/stdc++.h>
using namespace std;

int a[105], b[1005];

int main() {
    int n, ans = 0;
    cin >> n;
    for (int i = 1; i <= n; i++) cin >> a[i], b[a[i]]++;
    vector<int> res;
    for (int i = 1; i <= 1000; i++)
        if (b[i]) ans++, res.push_back(i);
    cout << ans << endl;
    for (int x : res) cout << x << " ";
    return 0;
}