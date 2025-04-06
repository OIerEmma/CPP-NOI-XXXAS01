//
// Created by Emma on 2025/4/6.
//
#include<iostream>
using namespace std;

void move(int n, char a, char b, char c) {
    if (n == 0) {
        return;
    }
    move(n - 1, a, c, b);
    printf("%d %c %c\n", n, a, b);
    move(n - 1, c, b, a);
}

int main() {
    int n;
    scanf("%d", &n);
    move(n, 'A', 'B', 'C');
    return 0;
}
