//
// Created by Emme.Kwok on 2026/2/5.
//
#include<iostream>
using namespace std;

struct node {
    long long x, y;
} a[150005];

bool cmp(node a, node b) {
    return a.y < b.y;
}

int main() {
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++) {
        scanf("%lld %lld", &a[i].x, &a[i].y);
    }
    sort(a + 1, a + n + 1, cmp);
    long long s = 0, nowt = 0;
    for (int i = 1; i <= n; i++) {
        if (nowt + a[i].x <= a[i].y) {
            nowt += a[i].x;
            s++;
        }
    }
    cout << s << endl;
    return 0;
}