//
// Created by Geek.Kwok on 2026/3/28.
//
#include<iostream>
#include<cstring>
using namespace std;

int m, n, mem[1010][2010];
int zero[2010] = {0};
bool vis[1010];

void s2BIG(string s, int a[]) {
    for (int i = 1; i <= s.size(); i++) a[i] = s[s.size() - i] - '0';
    a[0] = s.size();
}

void printBIG(int a[]) {
    for (int i = a[0]; i >= 1; i--) cout << a[i];
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

int* dfs(int step) {
    if (mem[step][0] > 0) return mem[step];
    if (step >= n) return zero;
    int t[2010], t2[2010];
    memset(t, 0, sizeof t);
    memset(t2, 0, sizeof t2);
    for (int i = 1; i <= 2; i++) {
        if (vis[step + i]) continue;
        vis[step + i] = true;
        int a[2010], b[2010];
        memset(a, 0, sizeof a);
        memset(b, 0, sizeof b);
        s2BIG("1", a); // 1
        addBIG(a, dfs(step + i), b); // 1 + dfs(step + i) = b
        addBIG(t, b, t2);
        memcpy(t, t2, sizeof t2);

        vis[step + i] = false;

    }
    memcpy(mem[step], t, sizeof t);
    // printBIG(mem[step]);
    return mem[step];
}

int main() {
    cin >> m >> n;
    zero[0] = 1;
    dfs(m);
    printBIG(mem[m]);
    return 0;
}