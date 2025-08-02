//
// Created by Emma on 2025/8/2.
//
#include<iostream>
using namespace std;

int main() {
    long long a = 0, b = 0, c = 0, num;
    for (int i = 1; i <= 10; i++) {
        cin >> num;
        if (num < 0) {
            a++;
        } else if (num == 0) {
            b++;
        } else {
            c++;
        }
    }
    cout << b << " " << a << " " << c << endl;
    return 0;
}