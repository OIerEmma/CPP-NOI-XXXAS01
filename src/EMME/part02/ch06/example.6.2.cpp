//
// Created by Emme.Kwok on 2026/1/24.
//
#include<iostream>
using namespace std;

const int maxn = 105;
int a[maxn];

int main() {
    int n, ave = 0;
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        ave += a[i];
    }
    ave /= n;
    for (int i = 1; i <= n; i++) {
        a[i] -= ave;
    }
    int step = 0;
    for (int i = 1; i < n; i++) {
        if (a[i] == 0) {
            continue;
        }
        a[i + 1] += a[i];
        a[i] = 0;
        step++;
    }
    cout << step << endl;
    return 0;
}