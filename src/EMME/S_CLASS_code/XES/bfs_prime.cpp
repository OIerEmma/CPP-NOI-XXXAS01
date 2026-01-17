//
// Created by Emme.Kwok on 2025/11/22.
//
// #include<bits/stdc++.h>
#include<iostream>
#include<queue>
#include<cmath>
using namespace std;

int f[10000];
bool pri[10000], vis[10000];
int a, b;
queue<int> q;

bool isprime(int x) {
    if (x <= 1) {
        return false;
    }
    for (int i = 2; i * i <= x; i++) {
        if (x % i == 0) {
            return false;
        }
    }
    return true;
}

void digit(bool high, int d, int now) {
    int p1 = pow(10, d), p2 = pow(10, d + 1);
    for (int i = !high; i <= 9; i++) {
        if (i != int(now / p1) % 10) {
            int nxt = int(now / p2) * p2 + (now % p1) + (i * p1);
            if (pri[nxt] && !vis[nxt]) {
                f[nxt] = f[now] + 1;
                q.push(nxt);
                vis[nxt] = true;
            }
        }
    }
}

int bfs() {
    q.push(a);
    vis[a] = true;
    while (!q.empty()) {
        int now = q.front();
        q.pop();
        if (now == b) {
            return f[now];
        }
        //digit(true, 3, now);
        for (int i = 1; i <= 9; i++) {
            if (i != now / 1000) {
                int nxt = now / 10;
            }
        }
        digit(false, 2, now);
        digit(false, 1, now);
        digit(false, 0, now);
    }
}

int main() {
    cin >> a >> b;
    for (int i = 1000; i <= 9999; i++) {
        if (isprime(i)) {
            pri[i] = true;
        }
    }
    cout << bfs() << endl;
    return 0;
}