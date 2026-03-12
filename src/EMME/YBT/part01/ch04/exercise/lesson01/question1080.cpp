//
// Created by Emma on 2024/12/28.
//
#include<iostream>
using namespace std;

int main() {
    int a, b, c, maxabc, x = 1, remaina, remainb, remainc;
    cin >> a >> b >> c;
    maxabc = max(max (a, b), c);
    for (int i = 1; i <= maxabc; i ++) {
        x++;
        remaina = a % x;
        remainb = b % x;
        remainc = c % x;
        if (remaina == remainb && remaina == remainc) {
            cout << x << endl;
            break;
        }
    }
    return 0;
}