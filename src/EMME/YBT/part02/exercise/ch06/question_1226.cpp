//
// Created by Emme.Kwok on 2026/1/29.
//
#include<iostream>
using namespace std;

int main() {
    int a[7], sum ,cnt, u[5] = {0, 5, 3, 1};
    while (true) {
        sum = 0;
        for (int i = 1; i <= 6; i++) {
            cin >> a[i];
            sum += a[i];
        }
        if (sum == 0) {
            break;
        }
        cnt = a[6] + a[5] + a[4] + (a[3] + 3) / 4;
        int c2 = 5 * a[4] + u[a[3] % 4];
        if(a[2] > c2) {
            cnt += (a[2] - c2 + 8) / 9;
        }
        int c1 = (cnt - a[6]) * 36 - a[5] * 25 - a[4] * 16 - a[3] * 9 - a[2] * 4;
        if (a[1] > c1) {
            cnt += (a[1] - c1 + 35) / 36;
        }
        cout << cnt << endl;
    }
    return 0;
}