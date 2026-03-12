//
// Created by Emma on 2025/8/12.
//
#include<iostream>
using namespace std;

int a[101], b[101], n;

void init(int a[]) {
    string s;
    cin >> n >> s;
    a[0] = (int) s.size();
    for (int i = 1; i <= a[0]; i++) {
        if (s[a[0] - i] >= '0' && s[a[0] - i] <= '9') {
            a[i] = s[a[0] - i] - '0';
        } else {
            a[i] = s[a[0] - i] - 'A' + 10;
        }
    }
}

bool check(const int a[]) {
    for (int i = 1; i <= a[0]; i++) {
        if (a[i] != a[a[0] - i + 1]) {
            return false;
        }
    }
    return true;
}

void addnum(int a[]) {
    for (int i = 1; i <= a[0]; i++) {
        b[i] = a[a[0] - i + 1];
    }
    for (int i = 1; i <= a[0]; i++) {
        a[i] += b[i];
    }
    for (int i = 1; i <= a[0]; i++) {
        a[i + 1] += a[i] / n;
        a[i] %= n;
    }
    if (a[a[0] + 1] > 0) {
        a[0]++;
    }
}

int main() {
    init(a);
    if (check(a)) {
        cout << 0 << endl;
    } else {
        bool flag = false;
        for (int i = 1; i <= 30; i++) {
            addnum(a);
            if (check(a)) {
                cout << i << endl;
                flag = true;
                break;
            }
        }
        if (!flag) {
            cout << "Impossible" << endl;
        }
    }
    return 0;
}
