//
// Created by Emme.Kwok on 2026/3/9.
//
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

#define ll long long

int n, m;
int cnt[1005];
vector<int> cs[1005];
ll ans = 1e18;

ll calc(int aim) {
    int cur_cnt = cnt[1];
    ll res = 0;
    vector<int> tmp;
    for (int i = 2; i <= n; i++) {
        int buy = max((int)cs[i].size() - aim + 1, 0);
        for (int j = 0; j < buy; j++) {
            res += (ll)cs[i][j];
        }
        if (res >= ans) {
            return ans;
        }
        cur_cnt += buy;
        for (int j = buy; j < (int)cs[i].size(); j++)
            tmp.push_back(cs[i][j]);
    }
    sort(tmp.begin(), tmp.end());
    for (int i = 0; i < aim - cur_cnt; i++) {
        res += (ll)tmp[i];
    }
    return res;
}

int main() {
    cin >> n >> m;
    int p, c;
    for (int i = 1; i <= m; i++) {
        cin >> p >> c;
        cnt[p]++;
        cs[p].push_back(c);
    }
    for (int i = 1; i <= n; i++) {
        sort(cs[i].begin(), cs[i].end());
    }
    for (int i = max(cnt[1], 1); i <= m; i++) {
        ans = min(ans, calc(i));
    }
    cout << ans << endl;
    return 0;
}