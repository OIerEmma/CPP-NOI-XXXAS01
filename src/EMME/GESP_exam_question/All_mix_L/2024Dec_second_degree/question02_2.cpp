//
// Created by Emma on 2025/2/7.
//
#include<iostream>
using namespace std;

int main() {
    int n, ans = 0, sum;
    long long num;
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) {
        sum = 0;
        scanf("%lld", &num);
        while(num > 0) {
            sum += int(num % 10);
            num /= 10;
        }
        ans = max(ans, sum);
    }
    printf("%d", ans);
    return 0;
}