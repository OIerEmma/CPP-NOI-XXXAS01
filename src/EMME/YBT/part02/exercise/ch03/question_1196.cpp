//
// Created by Emme.Kwok on 2026/1/2.
//
#include<iostream>
#include<map>
using namespace std;

int n, ans;
int a[25][50];
const int dx[] = {1, 0, 0},
          dy[] = {0, -1, 1};
bool vis[25][50];
// map<string, int> m;

void dfs(int step, int x, int y) {
    if (step == n + 1) {
        // if (!m.count(s)) {
        //     ans++;
        //     m[s] = 1;
        // }
        ans++;
        return;
    }
    for (int i = 0; i < 3; i++) {
        if (!vis[x + dx[i]][y + dy[i]]) {
            vis[x + dx[i]][y + dy[i]] = true;
            // s += to_string(dx[i]) + to_string(dy[i]);
            dfs(step + 1, x + dx[i], y + dy[i]);
            vis[x + dx[i]][y + dy[i]] = false;
            // int minus = 2;
            // if (dy[i] == -1) {
            //     minus++;
            // }
            // s = s.substr(0, s.size() - minus);
        }
    }
}

int main() {
    cin >> n;
    vis[0][20] = true;
    dfs(1, 0, 20);
    cout << ans << endl;
    return 0;
}