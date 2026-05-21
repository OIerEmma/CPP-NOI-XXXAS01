//
// Created by Emme.Kwok on 2026/5/21.
//
#include<iostream>
#include<vector>
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> a(n + 1);
    for (int i = 0; i < n; i++) cin >> a[i]; // 输入
    vector<int> dp(n + 1, 1); // 初始化条件
    int ans = 0;
    // 计算顺序
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < i; j++)
            if (a[j] < a[i]) // 比前一个大才可以接到后面去
                dp[i] = max(dp[i], dp[j] + 1); // 状态转移方程
        ans = max(ans, dp[i]);
    }
    cout << ans << endl;
    return 0;
}
/**
1.划分阶段
    问自己：这个问题能划分成哪些阶段？每个阶段在做什么决定？
    针对数组中的每个元素，每遍历一个元素就是一个阶段
    ① 把它接在一个已有的上升子序列后一个
    ② 自己独立成为一个新上升子序列的开头
2.定义状态
    问自己：dp[i] 或 dp[i][j] 代表什么？存储的是最大值，最小值还是方案数？
    dp[i] 代表以 nums[i] 为结尾的最长上升子序列的长度
    存储的是最大值
3.分析决策
    问自己：
    ① 有哪些选择？决策允许集合
        当站在 nums[i] 时，可以选择 nums[j] 元素，
        j 满足 j < i && num[j] < nums[i]
        把 nums[i] 接在以 nums[j] 为结尾的最长上升子序列后面
    ② 从哪转移？状态转移过程
        dp[i] 是从 dp[j] 转移而来
        dp[i] = dp[j] + 1
    ③ dp值怎么变？状态计算结果
        dp[i] = max {dp[j] + 1} 取所有符合条件的 j 的最大值
        ※ 当 j 不存在时，dp[i] = 1，自己构成一个最长上升子序列
4.状态转移方程
    dp[i] = max { dp[j] + 1,
                  0 =< j < i,
                  num[j] < nums[i]
                }
    dp[i] = 1, otherwise
5.确定初始条件
    问自己：最小的，不需要推导就能得出结果的状态是什么？
    每个元素都可以单独成为一个长度为 1 的上升子序列，因此每个元素初始化为 1
6.确定计算顺序
    问自己（核心原则）：计算 dp[i] 时，它依赖的 dp 值应该已经计算好了
    针对第 i 个时，它依赖的 j 比它更小，所以从小到大
7.确定返回结果
    问自己：最终存储的答案在 dp 数组的哪个位置？取决于状态定义的方式
    ans = max { dp[i],
                0 <= i <= n
              }
*/