//
// Created by Emma on 2025/8/8.
//
#include<iostream>
#include<cmath>
using namespace std;

int main() {
    long long n, ans = 0;
    cin >> n;
    int al = int(pow(n, 1.0 / 3));
    for (int a = 1; a <= al; a++) {
        int bl = int(pow(n / a, 1.0 / 2));
        for (int b = a; b <= bl; b++) {
            ans += n / a / b - b + 1;
        }
    }
    cout << ans << endl;
    return 0;
}