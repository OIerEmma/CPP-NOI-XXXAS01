//
// Created by Emma on 2025/8/15.
//
#include<iostream>
#include<cmath>
#include<cstring>
using namespace std;

int a1[110], b1[110], c[110];

int main() {
    string a, b;
    int n;
    cin >> n;
    for (int t = 0; t < n; t++) {
        memset(a1, 0, sizeof(a1));
        memset(b1, 0, sizeof(b1));
        memset(c, 0, sizeof(c));
        cin >> a;
        getchar();
        cin >> b;
        int idx1 = (int) a.find('.'), idx2 = (int) b.find('.'), diff = abs(idx1 - idx2);
        // 前面补零
        if (idx1 < idx2) {
            for (int i = 0; i < diff; i++) {
                a = "0" + a;
            }
        } else {
            for (int i = 0; i < diff; i++) {
                b = "0" + b;
            }
        }
        // 后面补零
        int suffix_diff = abs((int)a.size() - (int)b.size());
        if (a.size() < b.size()) {
            for (int i = 0; i < suffix_diff; i++) {
                a += "0";
            }
        } else {
            for (int i = 0; i < suffix_diff; i++) {
                b += "0";
            }
        }
        a.erase(a.find('.'), 1);
        b.erase(b.find('.'), 1);
        for (int i = 0; i < a.size(); i++) {
            a1[a.size() - i] = a[i] - 48;
        }
        for (int i = 0; i < b.size(); i++) {
            b1[b.size() - i] = b[i] - 48;
        }
        int lenc = 1, x = 0;
        while (lenc <= a.size() || lenc <= b.size()) {
            c[lenc] = a1[lenc] + b1[lenc] + x;
            x = c[lenc] / 10;
            c[lenc] %= 10;
            lenc++;
        }
        c[lenc] = x;
        int y = max(idx1, idx2);
        while (c[lenc] == 0 && lenc > 1) {
            lenc--;
        }
        // 处理小数点后多余的零
        int tail = 1, j = 1;
        while (c[tail] == 0 && tail < y + 1) {
            tail++;
        }
        for (int i = lenc, j = 1; i >= tail; i--, j++) {
            if (j == y + 1) {
                cout << '.';
            }
            cout << c[i];
        }
        cout << endl;
    }
    return 0;
}