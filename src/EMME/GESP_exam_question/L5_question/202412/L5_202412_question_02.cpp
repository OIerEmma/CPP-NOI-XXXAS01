//
// Created by Emme.Kwok on 2026/3/1.
//
#include<iostream>
#include<set>
#include<vector>
#include<algorithm>
using namespace std;

multiset<int> a[1005];
multiset<int>::iterator it;
int n, m, p, c;
long long ans = 1e18;
long long work(int x) {
    int cnt = x - (int)a[1].size();
    vector<int> v;
    long long sum = 0;
    for (int i = 2; i <= n; i++) {
        if (a[i].empty()) {
            continue;
        }
        int s = (int)a[i].size() - x + 1;
        it = a[i].begin();
        while(s > 0) {
            sum += *it++, s--, cnt--;
        }
        if (sum >= ans) {
            return ans;
        }
        while(it != a[i].end()) {
            v.push_back(*it++);
        }
    }
    if (cnt <= 0) {
        return sum;
    }
    sort(v.begin(), v.end());
    for (int i = 0; i < cnt; i++) {
        sum += v[i];
    }
    return sum;
}

int main() {
    cin >> n >> m;
    for (int i = 1; i <= m; i++) {
        cin >> p >> c;
        a[p].insert(c);
    }
    for (int i = max((int)a[1].size(), 1); i <= m; i++) {
        ans = min(ans, work(i));
    }
    cout << ans << endl;
    return 0;
}