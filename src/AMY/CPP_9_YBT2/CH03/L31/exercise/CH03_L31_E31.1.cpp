//
// Created by Amy on 2026/7/10.
//
#include <iostream>
#include <cstdio>
using namespace std;

int main() {
    int n;
    cin >> n;

    int cnt[4] = {0};  // 0-18, 19-35, 36-60, 61+
    for (int i = 0; i < n; ++i) {
        int age;
        cin >> age;
        if (age <= 18) {
            ++cnt[0];
        } else if (age <= 35) {
            ++cnt[1];
        } else if (age <= 60) {
            ++cnt[2];
        } else {
            ++cnt[3];
        }
    }

    for (int i = 0; i < 4; ++i) {
        printf("%.2f%%\n", (double)cnt[i] / n * 100.0);
    }

    return 0;
}
