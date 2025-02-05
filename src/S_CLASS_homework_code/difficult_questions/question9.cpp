//
// Created by Emma on 2025/2/3.
//
#include<iostream>
using namespace std;

int main() {
    int n, ans = 0, sign_in, points = 0;
    scanf("%d\n", &n);
    for(int i = 1; i <= n; i++) {
        scanf("%d ", &sign_in);
        if(sign_in == 1) {
            if(points == 7) {
                points += 0;
            } else {
                points++;
            }
            ans += points;
        } else {
            points = 0;
        }
    }
    printf("%d", ans);
    return 0;
}