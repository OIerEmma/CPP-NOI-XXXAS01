//
// Created by Emma on 2025/7/13.
//
#include<iostream>
using namespace std;

int to_int(string s) {
    int ans = 0;
    for (int i = 0; i < s.size(); i++) {
        ans = ans * 10 + (s[i] - 48);
    }
    return ans;
}

int main() {
    // string a, b;
    // cin >> a >> b;
    // int y = to_int(a.substr(0, 4)), y2 = to_int(b.substr(0, 4));
    // int m = to_int(a.substr(4, 2)), m2 = to_int(b.substr(4, 2));
    // int d = to_int(a.substr(6, 2)), d2 = to_int(b.substr(6, 2));
    // if (y == y2 && m == m2) {
    //     cout << d2 - d + 1 << endl;
    // } else {
    //     int ans = 0, ans2 = 0;
    //     if (y == y2) {
    //         if (m == 2) {
    //             if () {
    //
    //             } else {
    //
    //             }
    //         } else if (m == 4 || m == 6 || m == 9 || m == 11) {
    //
    //         } else {
    //
    //         }
    //     } else {
    //
    //     }
    //     cout << ans2 - ans + 1 << endl;
    // }
    return 0;
}