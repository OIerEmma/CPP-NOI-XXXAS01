//
// Created by Emme.Kwok on 2026/5/30.
//
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<vector<int>> a(n, vector<int>(2));
    for (int i = 0; i < n; i++) cin >> a[i][0] >> a[i][1];
    sort(a.begin(), a.end(), [](vector<int> &x, vector<int> &y) {
        return x[0] == y[0] ? x[1] < y[1] : x[0] < y[0];
    });
    vector<int> tails;
    for (int i = 0; i < n; i++) {
        auto it = lower_bound(tails.begin(), tails.end(), a[i][1]);
        if (it == tails.end()) tails.push_back(a[i][1]);
        else *it = a[i][1];
    }
    cout << tails.size() << endl;
    return 0;
}