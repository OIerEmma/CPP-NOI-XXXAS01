//
// Created by Amy on 2025/12/6.
//
#include <iostream>
using namespace std;

int main() {
    int a[101], n, sum = 0, t = 0;
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        sum += a[i];
    }
    for (int i = 1; i <= n; i++)
        if (a[i] * n >= sum)
            t++;
    cout << t << endl;
    return 0;
}
