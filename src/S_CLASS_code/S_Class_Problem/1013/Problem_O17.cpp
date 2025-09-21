//
// Created by Emme.Kwok on 2025/9/14.
//
#include<iostream>
#include<cstring>
using namespace std;

int mem[110], par[1010];

int main() {
    int n, m;
    cin >> m >> n;
    for (int i = 0; i < n; i++) {
        cin >> par[i];
    }
    int ans = 0, idx = 0;//, meml = 0;
    memset(mem, -1, sizeof(mem));
    for (int i = 0, j; i < n; i++) {
        bool flag = false;
        for (j = 0; j < m; j++) {
            if (mem[j] == par[i]) {
                flag = true;
                break;
            }
        }
        if (!flag) {
            // if (mem[idx] == -1) {
            // meml++;
            // }
            mem[idx++] = par[i];
            idx %= m;
            ans++;
        }
    }
    cout << ans << endl;
    return 0;
}