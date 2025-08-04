//
// Created by Emma on 2025/8/2.
//
#include<iostream>
using namespace std;

int n, a[10001];

bool isprime(int n) {
    if (n < 2) {
        return false;
    }
    for (int i = 2; i * i <= n; i++) {
        if (n % i == 0) {
            return false;
        }
    }
    return true;
}

int *find() {
    for (int i = 1; i <= n; i++) {
        if (isprime(a[i])) {
            return &a[i];
        }
    }
    return nullptr;
}

int main() {
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) {
        scanf("%d", &a[i]);
    }
    int *p = find();
    if (p != nullptr) {
        printf("%d\n%d\n", p, *p);
    } else {
        printf("can't find!");
    }
    return 0;
}
