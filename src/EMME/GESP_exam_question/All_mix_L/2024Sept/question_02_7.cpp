//
// Created by Emma on 2025/2/16.
//
#include<iostream>
using namespace std;

int main() {
    int n, num, ans = 0;
    cin >> n;
    for (int i = 1; i <= n; i++) {
        scanf("%d", &num);
        if (num % 9 == 0 && num % 8 != 0) {
            ans++;
        }
    }
    printf("%d\n", ans);
    return 0;
}