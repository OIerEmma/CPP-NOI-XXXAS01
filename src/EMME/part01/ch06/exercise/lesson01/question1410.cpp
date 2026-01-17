//
// Created by Emma on 2025/2/23.
//
#include<iostream>
using namespace std;

int the_biggest_factor(int n) {
    int ans = -1;
    while (n % 2 == 0) {
        ans = 2;
        n /= 2;
    }
    for (int i = 3; i * i <= n; i += 2) {
        while(n % i == 0) {
            ans = i;
            n /= i;
        }
    }
    if (n > 2) {
        ans = n;
    }
    return ans;
}

int main() {
    int n, m;
    scanf("%d %d", &m, &n);
    for (int i = m; i <= n - 1; i++) {
        printf("%d,", the_biggest_factor(i));
    }
    printf("%d", the_biggest_factor(n));
    return 0;
}
