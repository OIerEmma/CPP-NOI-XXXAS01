//
// Created by Emma on 2025/2/22.
//
#include<iostream>
#include<cmath>
using namespace std;

bool is_prime(int num) {
    bool ans = true;
    for (int i = 2; i <= sqrt(num); i++) {
        if (num % i == 0) {
            ans = false;
        }
    }
    return ans;
}

int main() {
    int n, ans = 0;
    scanf("%d", &n);
    for (int i = 2; i <= n; i++) {
        if (is_prime(i)) {
            ans++;
        }
    }
    printf("%d\n", ans);
    return 0;
}