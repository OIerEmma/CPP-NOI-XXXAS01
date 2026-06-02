//
// Created by Geek.Kwok on 2026/6/1.
//
#include <iostream>
#include <vector>
using namespace std;

int main() {
    // 输入
    int n, m;
    string s, ss;
    cin >> n;
    vector<int> a(n + 1);
    for (int i = 1; i <= n; i++) cin >> a[i];
    cin >> m, cin >> s;
    // 定义状态：dp[i] 代表前i个字符串的最大总得分
    // 初始化
    vector<int> dp(m + 1, 0);
    // 计算顺序
    for (int i = 1; i <= m; i++) {
        dp[i] = dp[i - 1];
        for (int idx, j = 1; j <= n; j++) {
            idx = i - j * 3;
            if (idx < 0) break;
            ss = s.substr(i - j * 3, 3);
            if (ss != "abc") break;
            dp[i] = max(dp[i], dp[idx] + a[j]);
        }
    }
    // 返回结果
    cout << dp[m] << endl;
    return 0;
}

/**
1.划分阶段
问自己：这个问题可以划分为哪些阶段？每个阶段可以做什么决策？
字符串序列的每个字符就是一个阶段，在第i个字符串时，往后添加一个字符，然后往前回溯"abc"，确定是否组成满足条件的子串。可以回溯1~n个"abc"，直到无法找到子串为止。

2.定义状态
问自己：dp[i]代表什么？保存的是最大值、最小值还是方案数？
定义状态：dp[i] 代表前i个字符串的最大总得分
求最大总得分，是最值型DP，max

3.分析决策：问自己三个问题
A、有哪些选择？决策允许集合
    当前在字符串的第i个位置，往后添加一个字符，然后往前回溯匹配：
    - 无法匹配“abc”，dp[i+1] = dp[i]
    - 1个“abc”，dp[i+1] = dp[i+1 - 3*1] + a[1-1]
    - 2个“abc”，dp[i+1] = dp[i+1 - 3*2] + a[2-1]
    - ...
    - n个“abc”，dp[i+1] = dp[i+1 - 3*n] + a[n-1]
    dp[i+1] = max{dp[i+1], dp[i+1 - 3*j] + a[j-1]}, 1 <= j <= n, 中间若失配则立即 break
B、从哪里转移？状态转移过程
    当前在字符串的第i个位置，从历史视角看，从哪些位置跳转而来：
    - 无法匹配“abc”，dp[i] = dp[i-1]
    - 1个“abc”，dp[i] = dp[i - 3*1] + a[1-1]
    - 2个“abc”，dp[i] = dp[i - 3*2] + a[2-1]
    - ...
    - n个“abc”，dp[i] = dp[i - 3*n] + a[n-1]
    dp[i] = max{dp[i-1], dp[i - 3*j] + a[j-1]}, 1 <= j <= n, i - 3*j >= 1
C、DP值怎么变？状态结果计算
    dp[i] = max{dp[i-1], dp[i - 3*j] + a[j-1]}, 1 <= j <= n, i - 3*j >= 0, s.substr(i-3*j, 3*j) == "abc"*j

4.写出状态转移方程
    dp[i] = max{dp[i-1], dp[i - 3*j] + a[j-1]}, 1 <= j <= n, i - 3*j >= 0, s.substr(i-3*j, 3*j) == "abc"*j

5.确定初始条件
问自己：最小的、不需要推导就能确定答案的状态是什么？
dp[0] = 0,
dp[i] = 0, 0 < i <= m

6.确定计算顺序
问自己（核心原则）：计算dp[i]时，它依赖的dp值必须已经算好了。
i从小到大，正序

7.确定返回结果
问自己：最终答案在dp数组的哪个位置？取决于状态定义的方式
dp[m]
 */