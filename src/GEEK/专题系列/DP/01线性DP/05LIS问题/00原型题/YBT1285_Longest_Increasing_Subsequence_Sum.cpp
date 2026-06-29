//
// Created by Geek.Kwok on 5/14/26.
//
#include <iostream>
#include <vector>
using namespace std;

int main() {
    // 输入
    int n;
    cin >> n;
    vector<int> arr(n);
    for (int i = 0; i < n; i++) cin >> arr[i];
    // DP[i] 以i为结尾的最大上升子序列和
    // 初始化
    int ans = 0;
    vector<int> dp(n, 0);
    for (int i = 0; i < n; i++) dp[i] = arr[i];
    // 计算顺序
    for (int i = 1; i < n; i++) {
        for (int j = 0; j < i; j++)
            if (arr[j] < arr[i])
                dp[i] = max(dp[i], dp[j] + arr[i]);
        ans = max(ans, dp[i]);
    }
    cout << ans << endl;

    return 0;
}