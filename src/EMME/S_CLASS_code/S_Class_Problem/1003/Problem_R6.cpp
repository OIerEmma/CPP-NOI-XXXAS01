//
// Created by Emma on 2025/7/2.
//
#include<iostream>
#include<cmath>
using namespace std;

double a[310];

bool isequal(double a, double b, double absEpsilon = 1e-36) {
    if (a == b) {
        return true;
    }
    double diff = abs(a - b);
    if (diff <= absEpsilon) {
        return true;
    }
    return false;
}

int main() {
    int n;
    cin >> n >> a[0];
    double maxx = a[0], minn = a[0];
    // cin and find out maxx and minn
    for (int i = 1; i < n; i++) {
        cin >> a[i];
        maxx = max(maxx, a[i]);
        minn = min(minn, a[i]);
    }
    // calculate the average
    double avge = 0.0;
    for (int i = 0; i < n; i++) {
        if (!(isequal(a[i], maxx) || isequal(a[i], minn))) {
            avge += a[i];
        }
    }
    avge /= n - 2;
    // calculate the maxans
    double maxans;
    for (int i = 0; i < n; i++) {
        if (!isequal(a[i], maxx) && !isequal(a[i], minn)) {
            maxans = abs(avge - a[i]);
            break;
        }
    }
    for (int i = 1; i < n; i++) {
        if (!(isequal(a[i], maxx) || isequal(a[i], minn))) {
            maxans = max(maxans, abs(avge - a[i]));
        }
    }
    // cout
    printf("%.2lf %.2lf\n", avge, maxans);
    return 0;
}
