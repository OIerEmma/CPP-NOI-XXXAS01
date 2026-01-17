//
// Created by Emma on 2025/2/22.
//
#include<iostream>
#include<cmath>
using namespace std;

bool is_prime(int num) {
    bool ans = true;
    for (int i = 2; i <= sqrt(num); i++) {
        if (num % i == 0) {
            ans = false;
        }
    }
    return ans;
}

int main() {
    int n;
    for (int i = 10; i < 99; i++) {
        if (is_prime(i)) {
            n = i % 10 * 10 + i / 10;
            if (is_prime(n)) {
                cout << i << endl;
            }
        }
    }
    return 0;

}