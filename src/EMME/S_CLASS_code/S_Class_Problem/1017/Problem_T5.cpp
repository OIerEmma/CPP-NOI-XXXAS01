//
// Created by Emma on 2025/8/2.
//
#include<iostream>
using namespace std;

int main() {
    int n, num;
    int a = 0, b = 0, c = 0, d = 0, e = 0;
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> num;
        if (num <= 59) {
            a++;
        } else if (num <= 69) {
            b++;
        } else if (num <= 79) {
            c++;
        } else if (num <= 89) {
            d++;
        } else if (num <= 100) {
            e++;
        }
    }
    cout << a << endl << b << endl << c << endl << d << endl << e << endl;
    return 0;
}