//
// Created by Emme.Kwok on 2026/3/9.
//
#include<iostream>
#include<algorithm>
#include<cmath>
using namespace std;

struct node {
    int b, c, minus;
}thing[200005];

bool cmp(node x, node y) {
    return abs(x.minus) > abs(y.minus);
}

int main() {
    int n;
    cin >> n;
    n <<= 1;
    for (int i = 1; i <= n; i++) {
        cin >> thing[i].b;
    }
    for (int i = 1; i <= n; i++) {
        cin >> thing[i].c;
    }
    for (int i = 1; i <= n; i++) {
        thing[i].minus = thing[i].b - thing[i].c;
    }
    sort(thing + 1, thing + n + 1, cmp);
    long long ans = 0;
    int bn = n/2, cn = n/2;
    for (int i = 1; i <= n; i++) {
        if (thing[i].minus > 0) {
            if (bn == 0) {
                cn--;
                ans += thing[i].c;
            } else {
                bn--;
                ans += thing[i].b;
            }
        } else if (thing[i].minus < 0) {
            if (cn == 0) {
                bn--;
                ans += thing[i].b;
            } else {
                cn--;
                ans += thing[i].c;
            }
        } else {
            if (bn > cn) {
                bn--;
                ans += thing[i].b;
            } else {
                cn--;
                ans += thing[i].c;
            }
        }
    }
    cout << ans << endl;
    return 0;
}