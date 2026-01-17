//
// Created by Emme.Kwok on 2025/9/11.
//
#include<iostream>
using namespace std;

string a0[10010], b1[10010], c2[10010];
int cnt0, cnt1, cnt2;

int main() {
    string s, line;
    char type;
    while (getline(cin, line)) {
        type = line[0];
        s = line.substr(2);
        if (type == '0') {
            a0[++cnt0] = s;
        } else if (type == '1') {
            b1[++cnt1] = s;
        } else {
            c2[++cnt2] = s;
        }
    }
    //int len = max({cnt0, cnt1, cnt2, 10});
    for (int i = 1; i <= 10; i++) {
        if (cnt0 > 0) {
            cout << a0[cnt0--];
        } else {
            cout << 0;
        }
        cout << ' ';
        if (cnt1 > 0) {
            cout << b1[cnt1--];
        } else {
            cout << 0;
        }
        cout << ' ';
        if (cnt2 > 0) {
            cout << c2[cnt2--];
        } else {
            cout << 0;
        }
        cout << endl;
    }
    return 0;
}