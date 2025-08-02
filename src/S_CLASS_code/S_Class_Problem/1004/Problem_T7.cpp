//
// Created by Emma on 2025/7/6.
//
#include<iostream>
using namespace std;

long long addall(int num) {
    return (1 + num) * num / 2;
}

int main() {
    int n;
    cin >> n;
    int a;
    for (int i = 1; ; i++) {
        long long sum = addall(i);
        if (sum - n > 0 && (sum - n) % 3 == 0) {
            a = (sum - n) / 3;
            if (a <= i) {
                cout << a << " " << i << endl;
                break;
            }
        }
    }
    return 0;
}