//
// Created by Amy on 2026/2/26.
//
#include<iostream>
using namespace std;

int main() {
    int h, m, s, k;
    cin >> h >> m >> s >> k;
    if (k + s >= 60) {
        m = m + (k + s) / 60;
        s = (k+s) % 60;
    } else {
        s += k;
    }
    if(m >= 60) {
        h = h + m / 60;
        m %= 60;
    }
    if(h >= 24) {
        h %= 24;
    }
    cout << h << " " << m << " " << s;
    return 0;
}
