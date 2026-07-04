//
// Created by Emme.Kwok on 2026/7/3.
//
#include<bits/stdc++.h>
using namespace std;

struct node {
    int a, b, c;
};

bool cmp(node x, node y) {
    return x.b * y.c >= x.c * y.b;
}

int main() {
    int t, n;
    cin >> t >> n;
    vector<node> p(n);
    for (int i = 0; i < n; i++) cin >> p[i].a;
    for (int i = 0; i < n; i++) cin >> p[i].b;
    for (int i = 0; i < n; i++) cin >> p[i].c;
    sort(p.begin(), p.end(), cmp);
    vector<int> dp(t + 1, 0);
    for (int i = 0; i < n; i++)
        for (int j = t; j >= p[i].c; j--)
            dp[j] = max(dp[j], dp[j - p[i].c] + p[i].a - j * p[i].b);
    cout << *max_element(dp.begin(), dp.end()) << endl;
    return 0;
}