//
// Created by Emme.Kwok on 2026/9/8.
//
#include<bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr), cout.tie(nullptr);
    int t;
    cin >> t;
    while (t--) {
        unordered_set<int> s;
        int n;
        cin >> n;
        for (int i = 1, a; i <= n; i++) {
            cin >> a;
            if (!s.count(a)) cout << a << " ";
            s.insert(a);
        }
        cout << "\n";
    }
    return 0;
}