//
// Created by Emma on 2025/1/23.
//
#include<iostream>
using namespace std;

int max(int x, int y);
int min(int x, int y);

int max(int x, int y) {
    return x + y - min(x, y);
}

int min(int x, int y) {
    return x < y ? x : y;
}

int main() {
    int a, b, c, d;
    cin >> a >> b >> c >> d;
    printf("%d %d %d %d\n", max(a, b), max(c, d), max(a, b), max(c, d));
    return 0;
}
