//
// Created by Emma on 2025/2/12.
//
#include<iostream>
using namespace std;

int main() {
    int a, b, c, x = 1;
    cin >> a >> b >> c;
    const int maxabc = max(max (a, b), c);
    for (int i = 1; i <= maxabc; i ++) {
        x++;
        const int remaina = a % x, remainb = b % x, remainc = c % x;
        if (remaina == remainb && remaina == remainc) {
            cout << x << endl;
            break;
        }
    }
    return 0;
}