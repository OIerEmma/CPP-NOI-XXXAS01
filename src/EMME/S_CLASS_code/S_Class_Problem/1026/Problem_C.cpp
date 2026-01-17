//
// Created by Emma on 2025/1/14.
//
#include<iostream>
using namespace std;

int main() {
    int c, s, a1, a2, a3;
    cin >> c >> s >> a1 >> a2 >> a3;
    int anstime = a1 + a2 + a3;
    if (20 - anstime >= c / s) {
        cout << "YES" << endl;
    } else {
        cout << "NO" << endl;
    }
    return 0;
}
