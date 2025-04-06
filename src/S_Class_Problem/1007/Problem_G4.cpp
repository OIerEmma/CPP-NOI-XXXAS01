//
// Created by Emma on 2025/4/6.
//
#include<iostream>
using namespace std;

long long eight_data(long long n) {
    if (n < 8) {
        return n;
    }
    return eight_data(n / 8) * 10 + n % 8;
}

int main() {
    long long num;
    scanf("%lld", &num);
    if (num < 8) {
        printf("%lld\n", num);
    } else {
        printf("%lld\n", eight_data(num));
    }
    return 0;
}
