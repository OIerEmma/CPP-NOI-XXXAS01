//
// Created by Emma on 2025/8/6.
//
#include<iostream>
using namespace std;

bool isprime(int x) {
    for (int i = 2; i * i <= x; i++) {
        if (x % i == 0) {
            return false;
        }
    }
    return true;
}

int main() {
    int num;
    cin >> num;
    cout << num << "=";
    if (isprime(num)) {
        cout << num;
    } else {
        bool flag = true;
        while (num) {
            if (isprime(num)) {
                cout << "*" << num;
                break;
            }
            int i;
            for (i = 2; i < num; i++) {
                if (num % i == 0 && isprime(i)) {
                    num /= i;
                    break;
                }
            }
            if (flag) {
                cout << i;
                flag = false;
            } else {
                cout << "*" << i;
            }
        }
    }
    return 0;
}