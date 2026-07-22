//
// Created by Amy on 2026/7/14.
//
#include <iostream>
using namespace std;

int main() {
    long long n;
    cin >> n;
    int score = 0;
    while (n != 1) {
        if (n % 2 == 1) {
            n = n * 3 + 1;
        } else {
            n = n / 2;
        }
        score++;
    }
    cout << score << endl;
    return 0;
}