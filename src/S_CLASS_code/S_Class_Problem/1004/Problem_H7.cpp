//
// Created by Emma on 2025/7/6.
//
#include<iostream>
using namespace std;

bool perfect(int num) {
    int ans = 1;
    for (int i = 2; i <= num / 2; i++) {
        if (num % i == 0) {
            ans += i;
        }
    }
    return ans == num;
}

int main() {
    int n, m;
    cin >> m >> n;
    for (int i = m; i <= n; i++) {
        if (perfect(i)) {
            cout << i << " ";
        }
    }
    return 0;
}