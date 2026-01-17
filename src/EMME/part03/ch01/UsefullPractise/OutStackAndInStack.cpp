//
// Created by Emma on 2025/8/19.
//
#include<iostream>
using namespace std;
#define n 100

void push(int s[], int *top, const int *x) { // 入栈
    if (*top == n) {
        cout << "overflow" << endl;
    } else {
        (*top)++;
        s[*top] = *x;
    }
}

void pop(const int s[], int *top, int *y) { // 出栈
    if (*top == 0) {
        cout << "underflow" << endl;
    } else {
        *y = s[*top];
        (*top)--;
    }
}

int main() {
    return 0;
}