//
// Created by Geek.Kwok on 2026/10/22.
//
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int N = 100005;
int n, a[N];

int main() {
    freopen("xxx.in", "r", stdin);
    freopen("xxx.out", "w", stdout);
    ios::sync_with_stdio(false);
    cin.tie(nullptr), cout.tie(nullptr);
    cin >> n;
    for (int i = 1; i <= n; i++) cin >> a[i];
    // ...解题...
    return 0;
}

void readLines() {
    int n;
    cin >> n;
    string line;
    getline(cin, line);
    for (int i = 1; i <= n; i++) {
        getline(cin, line);
        // 处理 line
    }
}

int countChars() {
    int c, cnt = 0;
    while ((c = getchar()) != EOF)
        if (c != ' ' && c != '\n' && c != '\r')
            cnt++;
    return cnt;
}

const int MAXN = 1005;
bool vis[MAXN][MAXN];
void multiCase() {
    int T;
    cin >> T;
    while (T--) {
        int n, m;
        cin >> n >> m;
        for (int i = 0; i <= n + 1; i++)
            for (int j = 0; j <= m + 1; j++)
                vis[i][j] = false;
        // ...本组解题...
    }
}