//
// Created by Emme.Kwok on 2026/7/3.
//
#include<bits/stdc++.h>
using namespace std;

int FindConstraint(int num) {
    int ans = 0;
    for (int i = 1; i * i <= num; i++)
        if (num % i == 0) {
            if (i == num / i) ans += i;
            else ans += i + num / i;
        }
    return ans - num;
}

int main() {
    int s;
    cin >> s;
    // dp[j]代表总和不超过j时的最大值
    vector<int> dp(s + 1, 0);
    for (int i = 1; i <= s; i++)
        for (int j = s; j >= i; j--)
            dp[j] = max(dp[j], dp[j - i] + FindConstraint(i));
    cout << dp[s] << endl;
    return 0;
}