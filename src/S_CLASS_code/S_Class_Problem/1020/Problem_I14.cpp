//
// Created by Emma on 2025/8/8.
//
#include<iostream>
using namespace std;

int a[2010], t[2010];
bool condition[2010];

int main() {
    int ans = 0, anum, tnum;
    cin >> anum >> tnum;
    for (int i = 1; i <= anum; i++) {
        cin >> a[i];
    }
    for (int i = 1; i <= tnum; i++) {
        cin >> t[i];
    }
    for (int i = 1; i <= anum; i++) {
        int idx = -1, maxx = -1;
        for (int j = 1; j <= tnum; j++) {
            if (maxx < t[j] && !condition[j] && t[j] <= a[i]) {
                maxx = t[j];
                idx = j;
            }
        }
        if (idx != -1) {
            condition[idx] = true;
        }
    }
    for (int i = 1; i <= tnum; i++) {
        if (!condition[i]) {
            ans++;
        }
    }
    cout << ans << endl;
    return 0;
}
