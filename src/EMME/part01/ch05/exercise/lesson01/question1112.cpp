//
// Created by Emma on 2025/1/19.
//
#include <iostream>
using namespace std;

int main() {
    int a[10000], x, y, i, j;
    cin >> j;
    for (i = 0; i < j; i++) {
        cin >> a[i];
    }
    x = y = a[0];
    for (i = 0; i < j; i++) {
        if (a[i]> x) {
            x = a[i];
        } else if (a[i] < y){
            y = a[i];
        }
    }
    cout << x - y << endl;
    return 0;
}
