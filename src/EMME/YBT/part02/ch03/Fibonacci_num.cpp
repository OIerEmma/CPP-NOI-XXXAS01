//
// Created by Emma on 2025/4/25.
//
#include<iostream>
using namespace std;

int main() {
    int n, ans = 1;
    scanf("%d", &n);
    int temp1 = 1, temp2 = 1;
    for (int i = 3; i <= n; i++) {
        ans = temp1 + temp2;
        temp1 = temp2;
        temp2 = ans;
    }
    printf("%d", ans);
    return 0;
}