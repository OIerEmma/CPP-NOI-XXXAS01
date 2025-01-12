//
// Created by Emma on 2025/1/12.
//
#include<iostream>
#include<iomanip>
#include<cmath>
using namespace std;
const int n = 100;
bool prime[n + 1];

int main() {
    int m;
    cin >> m;
    for (int i = 0; i <= m; i++) {
        prime[i] = true;
    }
    prime[1] = false;
    for (int i = 2; i <= sqrt(m); i++) {
        if (prime[i]) {
            for (int j = 2; j <= m / i; j++) {
                prime[i * j] = false;
            }
        }
    }
    for (int i = 2; i <= m; i++) {
        if (prime[i]) {
            cout << i << endl;
        }
    }
    return 0;
}
