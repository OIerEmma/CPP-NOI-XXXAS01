//
// Created by Emme.Kwok on 2026/1/27.
//
#include<iostream>
using namespace std;

int main() {
    freopen("string.in", "r", stdin);
    freopen("string.out", "w", stdout);
    int t;
    cin >> t;
    while (t--) {
        string s;
        cin >> s;
        int p1 = -1, p2 = -1, ans = 0;
        for (int i = 0; i < s.size(); i++) {
            if (s[i] == '1') {
                if (p1 == -1) {
                    p1 = i;
                } else {
                    p2 = i;
                    for (int j = p1; j <= p2; j++) {
                        if (s[j] == '0') {
                            ans++;
                            s[j] = '1';
                        }
                    }
                }
            }
        }
        p1 = -1, p2 = -1;
        for (int i = 0; i < s.size(); i++) {
            if (s[i] == '0') {
                if (p1 == -1) {
                    p1 = i;
                } else {
                    p2 = i;
                    for (int j = p1; j <= p2; j++) {
                        if (s[j] == '1') {
                            ans++;
                            s[j] = '0';
                        }
                    }
                }
            }
        }
        cout << ans << endl;
    }
    return 0;
}