//
// Created by Emme.Kwok on 2025/9/14.
//
#include<iostream>
#include<cmath>
using namespace std;

bool shui(int num) {
    int ans = 0;
    ans += (int)pow(num % 10, 3);
    ans += (int)pow(num / 10 % 10, 3);
    ans += (int)pow(num / 100, 3);
    if (ans == num) {
        return true;
    }
    return false;
}

int main() {
    int n, m;
    bool flag = false;
    cin >> n >> m;
    for (int i = n; i <= m; i++) {
        if (shui(i)) {
            cout << i << " ";
            flag = true;
        }
    }
    if (!flag) {
        cout << "no" << endl;
    }
    return 0;
}