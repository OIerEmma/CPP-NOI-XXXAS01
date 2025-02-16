//
// Created by Emma on 2025/2/11.
//
#include<iostream>
using namespace std;

int main() {
    int n, a, b, maxvalue = 0, ans = 0;
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> a >> b;
        if (90 <= a && a <= 140 && b >= 60 && b <= 90) {
            // 正常
            maxvalue++;
        } else {
            // 异常
            if (maxvalue > ans) {
                ans = maxvalue;
            }
            maxvalue = 0;
        }
    }
    cout << max(ans, maxvalue) << endl;
    return 0;
}
