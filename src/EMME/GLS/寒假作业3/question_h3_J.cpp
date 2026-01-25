//
// Created by Emme.Kwok on 2026/1/24.
//
#include<iostream>
#include<cmath>
using namespace std;

const int maxn = 3005;
int a[maxn];
bool flag[maxn];

int main() {
    int n;
    cin >> n >> a[1];
    bool f = false;
    for (int i = 2; i <= n; i++) {
        cin >> a[i];
        if (abs(a[i] - a[i - 1]) >= n) {
            f = true;
        } else {
            flag[abs(a[i] - a[i - 1])] = true;
        }
    }
    if (f) {
        cout << "Not jolly";
    } else {
        for (int i = 1; i < n; i++) {
            if (!flag[i]) {
                cout << "Not jolly";
                return 0;
            }
        }
        cout << "Jolly";
    }
    return 0;
}