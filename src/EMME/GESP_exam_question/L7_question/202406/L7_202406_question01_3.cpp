#include<bits/stdc++.h>
using namespace std;

const int N = 1e5 + 10;
vector<int> g[N];
int col[N], num[N], parent[N];
int ans, sum;
vector<int> order;

void buildOrder(int root) {
    parent[root] = 0;
    stack<int> st;
    st.push(root);
    while (!st.empty()) {
        int x = st.top();
        st.pop();
        order.push_back(x);
        for (int i : g[x])
            if (i != parent[x]) {
                parent[i] = x;
                st.push(i);
            }
    }
    reverse(order.begin(), order.end());
}

void calc(int root) {
    buildOrder(root);
    for (int x : order) {
        num[x] = col[x];
        for (int i : g[x])
            if (i != parent[x]) num[x] += num[i];
    }
}

void dfs() {
    for (int x : order) {
        bool flag = false;
        if (num[x] != sum && num[x] != 0) flag = true;
        for (int i : g[x])
            if (i != parent[x])
                if (num[i] != 0 && num[i] != num[x] - col[x]) flag = true;
        if (flag && col[x] != 1) ans++;
    }
}

int main() {
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++) cin >> col[i], sum += col[i];
    for (int i = 1, u, v; i < n; i++) {
        cin >> u >> v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    calc(1);
    dfs();
    cout << ans << endl;
    return 0;
}