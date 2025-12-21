//#include<bits/stdc++.h>
#include<iostream>
#include<queue>
using namespace std;

const int MAX_VAL = 1000015;
queue<int> q;
int flag[MAX_VAL], step[MAX_VAL];
long long cnt[MAX_VAL];
int minv, ans;

void bfs(int n, int k) {
    q.push(1);
    flag[1] = true, cnt[1] = 1;

    while (!q.empty()) {
        int now = q.front();
        q.pop();

        if (now > n) {
            continue;
        }

        for (int a = 1; a <= k; a++) {
            int nxt = now + 1 + now % a;
            if (!flag[nxt]) {
                q.push(nxt);
                flag[nxt] = true;
                step[nxt] = step[now] + 1;
                cnt[nxt] = cnt[now];
            } else if (step[nxt] == step[now] + 1) {
                cnt[nxt] = (cnt[nxt] + cnt[now]) % (long long)(10e9 + 7);
            }
        }
    }
}

int main() {
    int n, k;
    cin >> n >> k;
    bfs(n, k);
    cout << step[n] << endl << cnt[n] << endl;
}