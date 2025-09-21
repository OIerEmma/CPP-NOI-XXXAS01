//
// Created by Emme.Kwok on 2025/9/14.
//
#include<iostream>
using namespace std;

long long pow(int x, int y) {
    long long ans = 1;
    for (int i = 1; i <= y; i++) {
        ans *= x;
    }
    return ans;
}

int main() {
    int x;
    while (cin >> x) {
        int i;
        for (i = 1; i <= 62; i++) {
            if (pow(2, i) % x == 1) {
                cout << "2^" << i << " mod "<< x << " = 1" << endl;
                break;
            }
        }
        if (i == 63) {
            cout << "2^? mod " << x << " = 1" << endl;
        }
    }
    return 0;
}