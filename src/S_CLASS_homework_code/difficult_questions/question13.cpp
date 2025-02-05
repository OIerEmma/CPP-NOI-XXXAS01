//
// Created by Emma on 2025/2/3.
//
#include<iostream>
using namespace std;

int main() {
    int n, ans = 1000000001, num, m  = 0;
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) {
        scanf("%d", &num);
        // ans = min(ans, abs(num));
        if (ans > abs(num)) {
            m = num;
            ans = abs(num);
        } else if (ans == abs(num)) {
            // ans = max(ans, abs(num));
            if (m < num) {
                m = num;
            }
        }
    }
    printf("%d", m);
    return 0;
}