//
// Created by Emme.Kwok on 2025/9/19.
//
#include<iostream>
using namespace std;

int main() {
    int n, m, i = 1;
    while (cin >> n) {
        cin >> m;
        if (n == 0 && m == 0) {
            break;
        }
        int cnt = 0;
        for (int a = 1; a < n; a++) {
            for (int b = a + 1; b < n; b++) {
                double s = (a * a + b * b + m) * 1.0 / (a * b);
                if (s - int(s) < 1e-9) {
                    cnt++;
                }
            }
        }
        cout << "Case " << i << ": " << cnt << endl;
        i++;
    }
    return 0;
}