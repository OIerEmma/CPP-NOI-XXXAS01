//
// Created by Emma on 2024/12/24.
//
#include<iostream>
using namespace std;

int main() {
    int n, a, b, maxHours = 0, finalMaxHours = 0;
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> a >> b;
        if (90 <= a && a <= 140 && b >= 60 && b <= 90) {
            // 正常
            maxHours++;
        } else {
            // 异常
            if (maxHours > finalMaxHours) {
                finalMaxHours = maxHours;
            }
            maxHours = 0;
        }
    }
    cout << max(finalMaxHours, maxHours) << endl;
    return 0;
}
