//
// Created by Emme.Kwok on 2026/9/6.
//
#include<bits/stdc++.h>
using namespace std;

struct item {
    int w, v;
};

int main() {
    int group, W;
    cin >> group >> W;
    vector<vector<item>> groups(group);
    for (int g = 0; g < group; g++) {
        int cnt;
        cin >> cnt;
        for (int k = 0; k < cnt; k++)
            cin >> groups[g][k].w >> groups[g][k].v;
    }
    vector<int> dp(W + 1, 0);
    for (int g = 0; g < group; g++)
        for (int j = W; j >= 0; j--)
            for (auto &it : groups[g])
                if (j >= it.w) dp[j] = max(dp[j], dp[j - it.w] + it.v);
    cout << dp[W] << endl;
    return 0;
}