//
// Created by Emma on 2025/2/14.
//
#include<iostream>
using namespace std;

int main() {
    int n;
    cin >> n;
    int ans = 0;
    char a;
    for (int i = 0; i < n; i++) {
        cin >> a;
        if (int(a) >= 97) {
            ans += int(a) - 97 + 1;
        } else {
            ans += -int(a);
        }
    }
    printf("%d", ans);
    return 0;
}