//
// Created by Geek.Kwok on 2026/4/29.
//
#include <algorithm>
#include <iostream>
using namespace std;

int n, f[5005];
struct node {
    int c1, c2;
}city[5005];

int cmp(const node n1, const node n2) {
    return n1.c1 < n2.c1;
}

int main() {
    cin >> n;
    for (int i = 1; i <= n; i++) cin >> city[i].c1 >> city[i].c2, f[i] = 1;
    sort(city + 1, city + n + 1, cmp);
    // for (int i = 1; i <= n; i++) cout << city[i].c1 << " " << city[i].c2 << endl;
    for (int i = n - 1; i >= 1; i--) {
        int l = 0;
        for (int j = i + 1; j <= n; j++) {
            if (city[i].c2 < city[j].c2 && f[j] > l) l = f[j];
        }
        f[i] = l + 1;
    }
    int maxx = 1;
    for (int i = 2; i <= n; i++) if (f[i] > f[maxx]) maxx = i;
    cout << f[maxx] << endl;
}