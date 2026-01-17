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
        if (num % 2 == 0) {
            sum += num;
        }
    }
    printf("%lld\n", sum);
    return 0;
}