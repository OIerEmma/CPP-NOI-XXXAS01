//
// Created by Emma on 2025/2/23.
//
#include<cstdio>
#include<algorithm>
using namespace std;

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

int main() {
    int n;
    scanf("%d", &n);
    int cnt = 0, a = 3;
    for (int i = 1; i <= n && a <= n; i++) {
        if (isprime(a) && isprime(i)) {
            printf("%d %d\n", i, a);
            cnt++;
        }
        a++;
    }
    if (cnt == 0) {
        printf("empty");
    }
    return 0;
}
