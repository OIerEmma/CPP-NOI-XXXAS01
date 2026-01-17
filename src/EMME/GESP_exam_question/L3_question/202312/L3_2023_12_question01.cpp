//
// Created by Emme.Kwok on 2025/12/21.
//
#include<iostream>
using namespace std;

int main() {
    int n, i;
    long long f;
    cin >> n >> i;
    if (n == 1) {
        cout << i + 1 << endl;
        return 0;
    }
    for (int s = 1; ; s++) {
        bool flag = false;
        f = s * n + i;
        for (int j = 2; j <= n; j++) {
            if (f * n % (n - 1) == 0) {
                f = f * n / (n - 1) + i;
            } else {
                flag = true;
                break;
            }
        }
        if (!flag) {
            break;
        }
    }
    cout << f << endl;
    return 0;
}