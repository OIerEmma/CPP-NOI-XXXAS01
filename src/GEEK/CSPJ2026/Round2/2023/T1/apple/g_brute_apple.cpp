//
// Created by Geek.Kwok on 2026/10/1.
//
#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> a;
    for (int i = 1; i <= n; i++) a.push_back(i); // really line up n apples
    int day = 0, dayOfN = 0;
    while (!a.empty()) {
        day++;
        vector<int> rest;
        for (int i = 0; i < a.size(); i++) {
            if (i % 3 == 0) { if (a[i] == n) dayOfN = day; } // position 1,4,7,... are taken
            else rest.push_back(a[i]);
        }
        a = rest;
    }
    cout << day << " " << dayOfN << endl;
    return 0;
}