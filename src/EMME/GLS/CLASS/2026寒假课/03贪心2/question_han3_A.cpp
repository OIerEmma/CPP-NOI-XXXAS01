//
// Created by Emme.Kwok on 2026/2/2.
//
#include<iostream>
using namespace std;

const int maxn = 2005;
int bomb[maxn], stop[maxn];

int main() {
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> bomb[i];
    }
    int k = 0;
    for (int i = 1; i <= n; i++) {
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