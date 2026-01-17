//
// Created by Emma on 2025/4/4.
//
#include<iostream>
using namespace std;

bool blah(int n, int search) {
    if (n > search) {
        return false;
    }
    if (n == search) {
        return true;
    }
    if (blah(2 * n + 1, search) || blah(3 * n + 1, search)) {
        return true;
    }
    return false;
}

int main() {
    int k, search;
    scanf("%d,%d", &k, &search);
    if (blah(k, search)) {
        printf("YES");
    } else {
        printf("NO");
    }
    return 0;
}
