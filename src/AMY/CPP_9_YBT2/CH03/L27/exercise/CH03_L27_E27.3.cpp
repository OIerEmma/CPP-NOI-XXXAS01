//
// Created by Amy on 2026/6/30.
//
#include<bits/stdc++.h>
using namespace std;

int main() {
    for (int i = 1; ; i++) {
        cin >> i;
        if (i >= 0 && i <= 100) {
            cout << "成绩：" << i;
            return 0;
        }
    }
}
