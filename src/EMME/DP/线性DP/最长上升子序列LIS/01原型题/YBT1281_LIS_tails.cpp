//
// Created by Emme.Kwok on 2026/7/3.
//
#include<bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++) cin >> a[i];
    vector<int> tails;
    for (int i = 0; i < n; i++) {
        auto t = lower_bound(tails.begin(), tails.end(), a[i]);
        if (t == tails.end()) tails.push_back(a[i]);
        else *t = a[i];
    }
    cout << tails.size() << endl;
    return 0;
}