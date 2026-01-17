//
// Created by Emma on 2025/2/6.
//
#include<iostream>
using namespace std;

int main() {
    int odd = 0, even = 0, n, num;
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) {
        scanf("%d", &num);
        if(num % 2 == 0) {
            even++;
        } else {
            odd++;
        }
    }
    printf("%d %d\n", odd, even);
    return 0;
}
