//
// Created by Emma on 2025/2/7.
//
#include<iostream>
#include<cmath>
using namespace std;

int main() {
    int t, a, i = 0;
    scanf("%d", &t);
    while (i < t) {
        i++;
        scanf("%d", &a);
        int b = int(sqrt(sqrt(a)));
        if(b * b * b * b == a) {
            printf("%d", b);
        } else {
            printf("-1");
        }
    }
    return 0;
}
