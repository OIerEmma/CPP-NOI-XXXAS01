//
// Created by Emme.Kwok on 2025/12/28.
//
#include<iostream>
using namespace std;

const int maxn = 35;
int n, a[maxn];
bool vis[maxn];

bool isprime(int x) {
    if (x < 2) {
        return false;
    }
    for (int i = 2; i * i <= x; i++) {
        if (x % i == 0) {
            return false;
        }
    }
    return true;
}

void dfs(int step) {
    if (step == n + 1) {
        if (isprime(a[n] + a[1])) {
            for (int i = 1; i <= n; i++) {
                cout << a[i] << " ";
            }
            cout << endl;
            exit(0);
        }
    }
    for (int i = 2; i <= n; i++) {
        if (!vis[i] && isprime(i + a[step - 1])) {
            vis[i] = true;
            a[step] = i;
            dfs(step + 1);
            vis[i] = false;
            a[step] = 0;
        }
    }
}

int main() {
    cin >> n;
    a[1] = 1;
    vis[1] = true;
    dfs(2);
    return 0;
}