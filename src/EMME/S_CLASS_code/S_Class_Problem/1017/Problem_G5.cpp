//
// Created by Emma on 2025/8/1.
//
#include<iostream>
using namespace std;

int main() {
    long long num, sum = 0;
    for (int i = 1; i <= 10; i++) {
        cin >> num;
        sum += num;
    }
    printf("%lld\n", sum);
    return 0;
}
