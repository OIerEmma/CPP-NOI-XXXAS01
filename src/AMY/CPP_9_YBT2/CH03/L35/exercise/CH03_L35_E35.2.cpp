//
// Created by Amy on 2026/7/14.
//
#include<bits/stdc++.h>
using namespace std;
long long n;
int sum;
int main() {
    cin >> n;
    while (n > 0) {
        sum += int(n % 10);
        n /= 10;
    }
    cout << sum;
    return 0;
}