//
// Created by Emma on 2025/2/5.
//
#include<iostream>
using namespace std;

int main() {
    long long n, a, b, ans = 0;
    scanf("%lld %lld %lld", &a, &b, &n);
    n++;
    ans += n / (5 * a + 2 * b) * 7;
    long long remain = n % (5 * a + 2 * b);
    if (remain > 5 * a) {
        ans += 5;
        remain -= 5 * a;
        if (remain > b) {
            ans += 2;
        } else {
            ans++;
        }
    } else {
        if (remain % a == 0) {
            ans += remain / a;
        } else {
            ans += remain / a + 1;
        }
    }
    printf("%lld\n", ans);
    return 0;
}