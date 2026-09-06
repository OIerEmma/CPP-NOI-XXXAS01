//
// Created by Emme.Kwok on 2026/7/18.
//
#include<bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++) cin >> a[i];
    vector<int> tails; // tails[i]代表长度为i的最长上升子序列的最后一个为多少
    for (int i = 0; i < n; i++) {
        // 最长不下降子序列(LNDS)使用upper_bound()即可
        // auto t = upper_bound(tails.begin(), tails.end(), a[i]);
        auto t = lower_bound(tails.begin(), tails.end(), a[i]);
        if (t == tails.end()) tails.push_back(a[i]);
        else *t = a[i];
    }
    cout << tails.size() << endl;
    return 0;
}