//
// Created by Emme.Kwok on 2025/9/14.
//
#include<iostream>
using namespace std;

int main() {
    int a, b;
    cin >> a >> b;
    while (a != 0 || b != 0) {
        int ans = 1;
        for (int i = 1; i <= b; i++) {
            ans *= a;
            ans %= 1000;
        }
        cout << ans << endl;
        cin >> a >> b;
    }
    return 0;
}