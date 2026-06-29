//
// Created by Geek.Kwok on 6/3/26.
//
#include <bits/stdc++.h>
using namespace std;

int main() {
    // 输入
    int n;
    string str;
    cin >> n >> str;
    vector<int> a(n + 1);
    for (int i = 1; i <= n; i++) cin >> a[i];
    // 初始化
    vector<long long> dp(n + 1, 0);
    // 计算顺序
    for (int i = 1; i <= n; i++) {
        int mask = 0;
        dp[i] = dp[i-1] + a[1];
        mask |= 1 << (str[i-1] - 'a');
        for (int j = i - 1; j >= 1; j--) {
            if (mask & (1 << str[j-1] - 'a')) break; // 有重复字符则 break
            dp[i] = max(dp[i], dp[j-1] + a[i-j+1]);
            mask |= 1 << (str[j-1] - 'a');
        }
    }
    // 返回结果
    cout << dp[n] << endl;
    return 0;
}

/**
1. 划分阶段
问自己：这个问题可以划分成哪些阶段？每个阶段可以做什么决策？
扫描字符串的每个位置，即为一个阶段；
在位置i处，我们在其后面添加一个字符，则可以往回回溯至j，看看 j ~ i+1 之间的字符串子串是否无重复，若是则继续回溯，否则结束。

2. 定义状态
问自己：DP[i]或dp[i][j]代表什么？存的是最大值、最小值还是方案数？
定义状态：DP[i] 代表前i个字符组成的字符子串，经过适当划分后，子串价值之和的最大值
求最大值，MAX

3. 分析决策：问自己三个问题
A、有哪些选择？决策允许集合
在第i位置添加一个字符之后，往前回溯开头位置j，由 j ~ i 组成的子串，若满足无重复字符的条件，则都是考察的可划分的子字符串，即决策允许集合
B、从哪里转移？状态转移过程
对于所有的 1 <= j <= i 的 j 索引，从 j ~ i 组成的子字符串，若满足无重复字符条件，则 DP[i] = DP[j] + a[i-j+1] 在所有的选后 j 中选择 DP[i] 最大值
C、DP值怎么变？状态结果计算
DP[i] = max {DP[j] + a[i-j]}, i > j >= 0, str.substr(j, i-j) 无重复字符 [ str 0-based ]

注意：str.substr(j, i-j) 无重复字符，这里可以用到一个很秒的技巧就是“位掩码”。因为小写字符最多就是26个，可以用一个int型数字的每1位来代表是否有某个字符。
```md
int mask = 0;
字符转为整型对应位：curr <<= str[i] - 'a';
判断是否存在重复字符：mask && curr == 1 说明存在
字符加入位掩码：mask |= curr;
```

4. 状态转移方程
DP[i] = max {DP[j] + a[i-j]}, i > j >= 0, str.substr(j, i-j) 无重复字符 [ str 0-based ]

5. 确定初始条件
问自己：最小的、不需要推导就能确定答案的状态是什么？
DP[0] = 0
DP[1~n] = 0

6. 确定计算顺序
问自己(核心原则)：计算 DP[i] 时，它依赖的 DP 值都已经计算好了
i > j >= 0, 所以 j < i，即计算大的i依赖小的j，所以i从小到大，即正序

7. 确定返回结果
问自己：最终答案存在 DP 数组的哪个位置？取决于定义状态的方式
ans = DP[n]
 */