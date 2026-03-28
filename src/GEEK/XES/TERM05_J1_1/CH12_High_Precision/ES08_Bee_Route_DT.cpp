//
// Created by Geek.Kwok on 2026/3/28.
//
#include<iostream>
#include<algorithm>
using namespace std;

int a[1005], b[1005], c[1005];
int *pa = a, *pb = b, *pc = c;

void s2BIG(string s, int a[]) {
    for (int i = 1; i <= s.size(); i++) {
        a[i] = s[s.size() - i] - '0';
    }
    a[0] = s.size();
}

void printBIG(int a[]) {
    for (int i = a[0]; i >= 1; i--) {
        cout << a[i];
    }
}

void addBIG(int a[], int b[], int c[]) {
    int jin = 0;
    c[0] = max(a[0], b[0]);
    for (int i = 1; i <= c[0]; i++) {
        c[i] = a[i] + b[i] + jin;
        jin = c[i] / 10;
        c[i] %= 10;
    }
    if (jin > 0) {
        c[0]++;
        c[c[0]] = jin;
    }
}

int main() {
    int m, n;
    cin >> m >> n;
    s2BIG("1", a);
    s2BIG("1", b);
    for (int i = 3; i <= (n-m+1); i++) {
        addBIG(pa, pb, pc);
        pa = pb;
        pb = pc;
        pc = pa;
    }
    printBIG(pb);
    return 0;
}