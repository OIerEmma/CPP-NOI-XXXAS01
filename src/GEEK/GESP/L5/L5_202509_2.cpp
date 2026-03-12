//
// Created by Geek.Kwok on 2026/3/12.
//
#include <iostream>
using namespace std;

int countBits(int n) {
    int ans = 0;
    while (n) {
        if (n & 1) {
            ans++;
        }
        n >>= 1;
    }
    return ans;
}

int main() {

    return 0;
}