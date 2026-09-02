//
// Created by Emme.Kwok on 2026/8/31.
//
#include<bits/stdc++.h>
using namespace std;

const int MAXN = 1e5 + 5;
struct node {
    int x, t, dif;
} coin[MAXN];

bool cmp(node x, node y) {
    return x.x != y.x ? x.x < y.x : x.t < y.t;
}

int main() {
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> coin[i].x >> coin[i].t;
        coin[i].dif = coin[i].t - coin[i].x;
    }
    sort(coin + 1, coin + n + 1, cmp);
    // for (int i = 1; i <= n; i++)
    //     cout << coin[i].x << " " << coin[i].t << " " << coin[i].dif << endl;
    vector<int> tails;
    for (int i = 1; i <= n; i++) {
        if (coin[i].dif < 0) continue;
        auto it = upper_bound(tails.begin(), tails.end(), coin[i].dif);
        if (it == tails.end()) tails.push_back(coin[i].dif);
        else *it = coin[i].dif;
    }
    cout << tails.size() << endl;
    return 0;
}