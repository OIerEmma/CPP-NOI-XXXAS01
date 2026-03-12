//
// Created by Geek.Kwok on 2026/2/8.
//
#include<iostream>
#include<cstdio>
using namespace std;

struct node {
    double c, t;
}way[105];

int main() {
    freopen("a.in", "r", stdin);
    freopen("a.out", "w", stdout);
    int n, T;
    cin >> n >> T;
    for (int i = 1; i <= n; i++) {
        cin >> way[i].c >> way[i].t;
    }
    bool flag = true;
    double ans = 1e9;
    for (int i = 1; i <= n; i++) {
        if (way[i].t <= T) {
            ans = min(ans, way[i].c);
            flag = false;
        }
    }
    if (flag) {
        cout << "TLE" << endl;
    } else {
        cout << ans << endl;
    }
    return 0;
}