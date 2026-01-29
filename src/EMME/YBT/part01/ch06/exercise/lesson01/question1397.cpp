//
// Created by Emma on 2025/2/22.
//
#include<iostream>
using namespace std;
char a[20];

int cal(int x, int y, char f) {
    int result;
    switch (f) {
        case '+':
            result = x + y;
            break;
        case '-':
            result = x - y;
            break;
        case '*':
            result = x * y;
            break;
        case '/':
            result = x / y;
            break;
        default:
            result = x % y;
            break;
    }
    return result;
}

int main() {
    int a, b;
    char c;
    scanf("%d%c%d", &a, &c, &b);
    printf("%d", cal(a, b, c));
    return 0;
}
