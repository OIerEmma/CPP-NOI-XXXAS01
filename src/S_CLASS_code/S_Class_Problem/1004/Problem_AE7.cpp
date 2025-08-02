//
// Created by Emma on 2025/7/8.
//
#include <iostream>
using namespace std;

int sum(int num) {
    int ans = 1;
    for (int i = 2; i < num; i++) {
        if (num % i == 0) {
            ans += i;
        }
    }
    return ans;
}

int main() {
    for (int i = 1; i < 500; i++) {
        int b = sum(i), c = sum(b);
        if (b != 1 && c != 1 && i != b) {
            if (c == i) {
                cout << i << ' ' << b << endl;
                break;
            }
        }
    }
    return 0;
}
