//
// Created by Geek.Kwok on 2026/6/1.
//
#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    long long maximumTotalDamage(vector<int>& power) {

    }
};

/**
1.划分阶段
问自己：这个问题可以划分为哪些阶段？每个阶段做什么决策？
针对每个咒语就是一个阶段，魔法师都可以选择使用或不使用当前咒语。
2.定义状态
问自己：dp[i]代表什么？存储最大值、最小值还是方案数？
求魔法师可以达到的伤害值之和的最大值，所以是求max，是最值型DP
定义状态：dp[i] 代表前 i 个咒语，魔法师可以达到的伤害值之和的最大值。
3.分析决策：问自己三个问题
    A、有哪些选择？决策允许集合。站在当前第 i+1 个咒语，从现在看未来：
        第i+1个咒语已失效，则跳过，dp[i+1] = dp[i]
        第i+1个咒语有效，则
            - 选择使用第i+1个咒语，则 dp[i+1] = dp[i] + power[i+1], { 同时后续值为 p 的咒语都失效 <- [power[i+1]-2,power[i+1]-1,power[i+1]+1,power[i+1]+2] }
            - 选择不使用第i+1个咒语，则 dp[i+1] = dp[i]
    B、从哪里转移？状态转移过程。站在当前第 i 个咒语，从过去看现在：
        第i个咒语已失效，则跳过，dp[i] = dp[i-1]
        第i个咒语有效，则
            - 选择使用第i个咒语，则 dp[i] = dp[i-1] + power[i], { 同时后续值为 p 的咒语都失效 <- [power[i]-2,power[i]-1,power[i]+1,power[i]+2] }
            - 选择不使用第i个咒语，则 dp[i] = dp[i-1]
    C、DP值怎么变？状态结果计算。
        dp[i] = max {dp[i - 1], dp[i - 1] + power[i]},
 */