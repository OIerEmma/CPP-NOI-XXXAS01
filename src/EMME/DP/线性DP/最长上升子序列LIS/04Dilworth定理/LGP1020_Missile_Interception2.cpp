//
// Created by Emme.Kwok on 2026/5/30.
//
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int main() {
    vector<int> a;
    // int n;
    // cin >> n;
    int t;
    // for (int i = 0; i < n; i++) cin >> t, a.push_back(t);
    while (cin >> t) a.push_back(t);
    // tails1[i] 代表长度为 i+1 最长不上升子序列末尾数的最大值
    // tails2[i] 代表长度为 i+1 最长上升子序列末尾数的最小值
    vector<int> tails1, tails2;
    int n = a.size();
    for (int i = 0; i < n; i++) {
        auto x = upper_bound(tails1.begin(), tails1.end(), a[i], greater<int>());
        if (x == tails1.end()) tails1.push_back(a[i]);
        else *x = a[i];
        x = lower_bound(tails2.begin(), tails2.end(), a[i]);
        if (x == tails2.end()) tails2.push_back(a[i]);
        else *x = a[i];
    }
    cout << tails1.size() << endl << tails2.size() << endl;
    return 0;
}