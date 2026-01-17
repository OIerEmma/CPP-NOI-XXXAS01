//
// Created by Emma on 2025/2/10.
//
#include<iostream>
using namespace std;

int main() {
    int N, m, num, ans = 0;
    scanf("%d %d", &N, &m);
    for (int i = 1; i <= N; i++) {
        scanf("%d", &num);
        if (num == m) {
            ans++;
        }
    }
    printf("%d", ans);
    return 0;
}