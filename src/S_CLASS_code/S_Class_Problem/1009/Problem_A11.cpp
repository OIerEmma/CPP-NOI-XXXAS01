//
// Created by Emma on 2025/7/10.
//
#include<iostream>
using namespace std;

char a[100010], b[100010];

int main() {
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> a[i] >> b[i];
    }
    int c = 0, p = 0, j = 0, f = 0, g = 0, h = 0, win = 0, fail = 0, same = 0;
    for (int i = 0; i < n; i++) {
        if (a[i] == b[i]) {
            same++;
        } else {
            if (a[i] == 'C') {
                if (b[i] == 'J') {
                    win++;
                    c++;
                } else {
                    fail++;
                    f++;
                }
            } else if (a[i] == 'J') {
                if (b[i] == 'B') {
                    win++;
                    j++;
                } else {
                    fail++;
                    g++;
                }
            } else {
                if (b[i] == 'C') {
                    win++;
                    p++;
                } else {
                    fail++;
                    h++;
                }
            }
        }
    }
    cout << win << " " << same << " " << fail << endl;
    cout << fail << " " << same << " " << win << endl;
    char ans, ans2;
    ans = 'B';
    int maxx = p;
    if (c > maxx) {
        ans = 'C';
        maxx = c;
    }
    if (j > maxx) {
        ans = 'J';
        maxx = j;
    }
    ans2 = 'B';
    int maxx2 = f;
    if (g > maxx2) {
        ans2 = 'C';
        maxx2 = g;
    }
    if (h > maxx2) {
        ans2 = 'J';
        maxx2 = h;
    }
    cout << ans << " " << ans2 << endl;
    return 0;
}
