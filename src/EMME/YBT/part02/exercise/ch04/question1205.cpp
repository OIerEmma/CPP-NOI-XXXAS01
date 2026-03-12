//
// Created by Emma on 2025/4/4.
//
#include<iostream>
using namespace std;

void move(int n, char a, char b, char c) {
    if (n == 0) {
        return;
    }
    move(n - 1, a, c, b);
    printf("%c->%d->%c\n", a, n, b);
    move(n - 1, c, b, a);
}

int main() {
    int n;
    char a, b, c;
    scanf("%d %c %c %c", &n, &a, &b, &c);
    move(n, a, b, c);
    return 0;
}
