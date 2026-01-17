//
// Created by Emme.Kwok on 2025/9/21.
//
#include<iostream>
using namespace std;

int main() {
    int n, type;
    int a, b, c, ans = 0;
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> type;
        if (type == 1) {
            cin >> a >> b;
            ans += 2 * (a + b);
        } else if (type == 2) {
            cin >> a;
            ans += 4 * a;
        } else {
            cin >> a >> b >> c;
            ans += a + b + c;
        }
    }
    cout << ans << endl;
    return 0;
}