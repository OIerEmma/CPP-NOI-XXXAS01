//
// Created by Amy on 2026/7/21.
//
#include <iostream>
#include <string>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int a, b;
    cin >> a >> b;
    int result = 1;
    int base   = a % 7;
    int exp    = b;
    while (exp > 0) {
        if (exp & 1) {
            result = (result * base) % 7;
        }
        base = (base * base) % 7;
        exp >>= 1;
    }
    string days[7] = {
        "Sunday",
        "Monday",
        "Tuesday",
        "Wednesday",
        "Thursday",
        "Friday",
        "Saturday"
    };
    cout << days[result] << endl;
    return 0;
}
