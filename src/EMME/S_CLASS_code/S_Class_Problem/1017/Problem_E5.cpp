//
// Created by Emma on 2025/8/1.
//
#include<iostream>
using namespace std;

int main() {
    long long num, sum = 0, n;
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> num;
        sum += num;
    }
    printf("%lld\n%.1lf", sum, double(sum) / double(n));
    return 0;
}