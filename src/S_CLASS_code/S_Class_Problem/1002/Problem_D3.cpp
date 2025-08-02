//
// Created by Emma on 2025/2/6.
//
#include<iostream>
using namespace std;

int main() {
    int n, ans = 0;
    cin >> n;
    if (n == 1) {
        cout << 1 << endl;
    } else {
        while (n != 1) {
            ans++;
            if (n % 2 == 0) {
                n /= 2;
            } else {
                n = n * 3 + 1;
            }
        }
        printf("%d", ans);
    }
    return 0;
}