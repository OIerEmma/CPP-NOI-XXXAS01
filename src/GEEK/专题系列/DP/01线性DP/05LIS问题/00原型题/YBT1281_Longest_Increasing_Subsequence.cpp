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
    // 初始化
    int ans = 1;
    vector<int> dp(n, 1);
    // 计算顺序
    for (int i = 1; i < n; i++) {
        for (int j = 0; j < i; j++)
            if (arr[j] < arr[i])
                dp[i] = max(dp[i], dp[j] + 1);
        ans = max(ans, dp[i]);
    }
    // 返回结果
    cout << ans << endl;
    return 0;
}

/**
1.划分阶段
    问自己：这个问题能分成哪些阶段？每个阶段在做什么决定？
    遍历数组中的每个元素作为阶段。
    每个阶段 nums[i]，
        - 选择它，把它接在某个已有上升子序列的后面
        - 不选择它，它自己作为一个新序列的起点
2.定义状态
    问自己：DP[i]代表什么？存的是最大值、最小值还是方案数？
    本题求最长的上升子序列，属于最大值DP。
    DP[i] = 以nums[i]为结尾的最长上升子序列的长度
3.分析决策：问自己三个问题
    A.有哪些选择？决策允许集合
    假设当前在 nums[i] 元素，可以选择 nums[j] 元素，该元素满足 j < i && nums[j] < nums[i]，
    对于这样的 nums[j] 元素，都可以把 nums[i] 接在以 nums[j] 为结尾的最长上升子序列后面。
    B.从哪转移？状态转移过程
    假设当前在 nums[i] 元素，状态 DP[i] 从状态 DP[j] 转移而来，得到一个候选长度 DP[i] = DP[j] + 1
    若j不存在，则 nums[i] 只能单独构成长度为 1 的子序列
    C.dp值怎么变？状态结果计算
    对于所有满足条件的 nums[j] 元素，DP[i] = max { DP[j] + 1 }
    若没有满足条件的 nums[j] 元素，DP[i] = 1
4.写出状态转移方程
    DP[i] = max { DP[j] + 1 }, 0 < j < i && nums[j] < nums[i]
    DP[i] = 1, 0 < j < i && nums[j] >= nums[i]
5.确定初始条件
    问自己：最小的、不需要推导就能确定答案的状态是什么？
    最坏情况下 nums[i] 自身可以构成一个长度为1的上升子序列，因此 DP[i] = 1
6.确定计算顺序
    问自己（核心原则）：计算dp[i]时，它依赖的dp值必须已经计算好了。
    i 从小到大，正序
7.确定返回结果
    问自己：最终答案在dp数组的哪个位置？取决于状态定义的方式。
    ans = max { DP[i] }, 0 <= i < n
 */