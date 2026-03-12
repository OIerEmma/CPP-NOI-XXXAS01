//
// Created by Amy on 2026/3/7.
//
#include <iostream>
using namespace std;

int main() {
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        int a;
        cin >> a;
        int m = (a + 5) / 10 * 10;
        cout << m << endl;
    }
    return 0;
}