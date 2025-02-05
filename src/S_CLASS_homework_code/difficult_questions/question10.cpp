//
// Created by Emma on 2025/2/3.
//
#include<iostream>
using namespace std;

int main() {
    int n, y, m, d, ans_y = 2022, ans_m = 13, ans_d = 32;
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) {
        scanf("%d %d %d", &y, &m, &d);
        if(ans_y > y) {
            ans_y = y;
            ans_m = m;
            ans_d = d;
        } else if(ans_y == y) {
            if(ans_m > m) {
                ans_m = m;
                ans_d = d;
            } else if(ans_m == m) {
                if(ans_d > d) {
                    ans_d = d;
                }
            }
        }
    }
    printf("%02d %02d %02d", ans_y, ans_m, ans_d);
    return 0;
}
