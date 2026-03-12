//
// Created by Emme.Kwok on 2026/3/1.
//
#include<iostream>
using namespace std;

int a[100005], n;

bool check(int x) {
    int b[100005], cur = 0;
    for (int i = 1; i <= n; i++) {
        if (a[i] > x) {
            b[++cur] = a[i];
        }
    }
    for (int i = 1; i <= cur; i += 2) {
        if (b[i] != b[i + 1]) {
            return false;
        }
    }
    return true;
}

int main() {
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    for (int i = 1; true; i++) {
        if (check(i)) {
            cout << i << endl;
            break;
        }
    }
    return 0;
}