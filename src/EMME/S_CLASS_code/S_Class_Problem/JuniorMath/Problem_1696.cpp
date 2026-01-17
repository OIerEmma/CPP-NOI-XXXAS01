//
// Created by Emme.Kwok on 2025/9/14.
//
#include<iostream>
using namespace std;

int main() {
    long long t, n;
    cin >> t;
    while (t--) {
        cin >> n;
        bool flag = false;
        while (n != 1) {
            if (n % 2 == 0) {
                n /= 2;
            } else {
                cout << n << " ";
                n = n * 3 + 1;
                flag = true;
            }
        }
        if (!flag) {
            cout << "No number can be output !";
        }
        cout << endl;
    }
    return 0;
}