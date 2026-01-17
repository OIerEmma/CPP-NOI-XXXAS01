//
// Created by Emma on 2025/2/26.
//
#include<iostream>
#include<cmath>
using namespace std;

bool isprime(int x) {
    if (x == 1 || x == 0) {
        return false;
    }
    for (int i = 2; i <= sqrt(x); i++) {
        if (x % i == 0) {
            return false;
        }
    }
    return true;
}

int back(int num) {
    int reversed = 0;
    while (num != 0) {
        int digit = num % 10;
        reversed = reversed * 10 + digit;
        num /= 10;
    }
    return reversed;
}

int main() {
    int m, n;
    bool flag = false;
    cin >> m >> n;
    for (int i = m; i <= n; i++) {
        if (isprime(i) && isprime(back(i))) {
            if (flag) {
                printf(",");
            }
            printf("%d", i);
            flag = true;
        }
    }
    if (!flag) {
        printf("No\n");
    } else {
        printf("\n");
    }
    return 0;
}
