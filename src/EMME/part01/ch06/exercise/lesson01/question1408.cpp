//
// Created by Emma on 2025/2/23.
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

bool back_same(string input) {
    bool flag = true;
    for (int i = 0; i < input.size() / 2; i++) {
        if (input[i] != input[input.size() - i - 1]) {
            flag = false;
            break;
        }
    }
    if (!flag) {
        return false;
    }
    return true;
}

int main() {
    int n, cnt = 0;
    scanf("%d", &n);
    for (int i = 11; i <= n; i++) {
        if (isprime(i) && back_same(to_string(i))) {
            cnt++;
        }
    }
    printf("%d\n", cnt);
    return 0;
}
