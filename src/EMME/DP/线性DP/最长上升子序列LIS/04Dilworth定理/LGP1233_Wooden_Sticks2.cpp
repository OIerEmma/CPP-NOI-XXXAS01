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
    vector<int> tails;
    sort(a.begin(), a.end(), [](const vector<int> &x, const vector<int> &y){
        if (x[0] == y[0]) return x[1] > y[1];
        return x[0] > y[0];
    });
    for (int i = 0; i < n; i++) {
        auto x = lower_bound(tails.begin(), tails.end(), a[i][1]);
        if (x == tails.end()) tails.push_back(a[i][1]);
        else *x = a[i][1];
    }
    cout << tails.size() << endl;
    return 0;
}