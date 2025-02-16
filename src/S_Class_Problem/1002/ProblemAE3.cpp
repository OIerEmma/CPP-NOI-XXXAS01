//
// Created by Emma on 2025/2/13.
//
#include<iostream>
using namespace std;

int main() {
    int a, b, ans;
    cin >> a >> b;
    ans = 1;
    for (int i = 1; i <= b; i++) {
        ans *= a;
        ans %= 7;
    }
    if (ans == 1) {
        cout << "Monday" << endl;
    } else if (ans == 2) {
        cout << "Tuesday" << endl;
    } else if (ans == 3) {
        cout << "Wednesday" << endl;
    } else if (ans == 4) {
        cout << "Thursday" << endl;
    } else if (ans == 5) {
        cout << "Friday" << endl;
    } else if (ans == 6) {
        cout << "Saturday" << endl;
    } else {
        cout << "Sunday" << endl;
    }
    return 0;
}