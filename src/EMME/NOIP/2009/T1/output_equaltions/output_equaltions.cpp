//
// Created by Geek.Kwok on 2026/10/2.
//
#include<bits/stdc++.h>
using namespace std;

int main() {
    int n, a;
    cin >> n;
    for (int i = n; i >= 0; i--){
        cin >> a;
        if (a) {
            if (i < n && a > 0) cout << '+';
            if (abs(a) > 1 || i == 0) cout << a;
            if (a == -1 && i) cout << '-';
            if (i > 0) cout << 'x';
            if (i > 1) cout << '^' << i;
        }
    }
    return 0;
}
/*
10
-89 89 -56 1 34 -1 0 56 45 0 89
*/