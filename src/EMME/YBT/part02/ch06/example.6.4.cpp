//
// Created by Emme.Kwok on 2026/1/25.
//
#include<iostream>
using namespace std;

const int maxn = 1005;
int bomb[maxn], stop[maxn];

int main() {
    int cnt = 0;
    while (cin >> bomb[++cnt]);
    // int cnt;
    // cin >> cnt;
    // for (int i = 1; i <= cnt; i++) {
    //     cin >> bomb[i];
    // }
    int k = 0;
    for (int i = 1; i <= cnt; i++) {
        int minn = 30001, idx = 0;
        for (int j = 1; j <= k; j++) {
            if (stop[j] >= bomb[i]) {
                if (minn > stop[j]) {
                    minn = stop[j];
                    idx = j;
                }
            }
        }
        if (minn == 30001 && idx == 0) {
            k++;
            stop[k] = bomb[i];
        } else {
            stop[idx] = bomb[i];
        }
    }
    cout << k << endl;
    return 0;
}