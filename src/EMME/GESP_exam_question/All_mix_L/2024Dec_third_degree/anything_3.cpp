//
// Created by Emma on 2025/2/8.
//
#include<iostream>
using namespace std;

int jiaogu(int n) {
    int ans = 0;
    while (n != 1) {
        if (n % 2 == 0) {
            ans++;
            n /= 2;
        } else {
            ans++;
            n = n * 3 + 1;
        }
    }
    return ans;
}

void run_jiaogu(long long n) {
    while (n != 1) {
        if (n % 2 == 0) {
            printf("%lld ", n / 2);
            n /= 2;
        } else {
            printf("%lld ", n * 3 + 1);
            n = n * 3 + 1;
        }
    }
    printf("\n");
}

int main() {
    int k;
    scanf("%d", &k);
    for (int i = 2; i <= 90000; i++) {
        if (jiaogu(i) == k) {
            run_jiaogu(i);
        }
    }
    return 0;
}