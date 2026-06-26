//
// Created by Geek.Kwok on 6/26/26.
//
#include <bits/stdc++.h>
using namespace std;

struct car {
    int a, b, diff;
};
struct site {
    int p, c;
};

int main() {
    // IO优化：加快输入输出速度
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    // 读入数据
    int n, m, x;
    cin >> n >> m >> x;
    vector<site> s(n);
    vector<car> c(m);
    for (int i = 0; i < n; i++) cin >> s[i].p >> s[i].c;
    for (int i = 0; i < m; i++) cin >> c[i].a >> c[i].b, c[i].diff = c[i].a - c[i].b;

    // 核心算法：贪心 + 双指针
    // 排序
    sort(s.begin(), s.end(), [](const site& a, const site& b) { return a.p < b.p; });
    sort(c.begin(), c.end(), [](const car& a, const car& b) { return a.diff > b.diff; });
    // 贪心匹配+双指针
    long long ans = 0;
    int i = 0, j = m - 1, s_front = 0, s_back = n - 1;
    while (i <= j) {
        while (c[i].diff >= 0) {
            if (s[s_front].c <= 0) s_front++;  // 当前站点位置可容纳车辆数为0则指针后移
            s[s_front].c--;
            ans += (2LL * x * c[i].b + 2LL * s[s_front].p * c[i].diff);  // 统计车辆里程
            i++;
        }
        while (c[j].diff < 0) {
            if (s[s_back].c <= 0) s_back--;
            s[s_back].c--;
            ans += (2LL * x * c[j].a + 2LL * (x - s[s_back].p) * (-c[j].diff));
            j--;
        }
    }
    /*
    auto it = c.begin();
    while (it != c.end() && it->diff >= 0) {
        // 单个 car 优先选择离A地最近的站点
        for (int i = 0; i < n; i++) if (s[i].c > 0) {
            s[i].c--;
            ans += (2LL * x * it->b + 2LL * s[i].p * it->diff);
            ++it;
            break;
        }
    }
    auto it2 = c.rbegin();
    while (it2 != c.rend() && it2->diff < 0) {
        // 单个 car 优先选择离B地最近的站点
        for (int i = n - 1; i >= 0; i--) if (s[i].c > 0) {
            s[i].c--;
            ans += (2LL * x * it2->a + 2LL * (x - s[i].p) * (-it2->diff));
            ++it2;
            break;
        }
    }
    */
    // 输出结果
    cout << ans << endl;
    return 0;
}

/**
m
A a B b

n
A--s1--s2--s3---B
0           p   x
car to A：2 * p
car to B：2 * (x - p)
pi  上限ci

最短总行驶路程：每辆车的最短行驶路程之和
每辆车的最短行驶路程：选择运输站点策略
  - 考察 r = a - b 的运输次数值：
    - 若 r >= 0, 完整 2 * x 有 b 次，剩余到 A 地有 r 次
    - 若 r < 0，完整 2 * x 有 a 次，剩余到 B 地有 -r 次
    - 所以应该按照 r 从大到小排序，依次选择站点；站点按照靠近A地的位置从小到大排序
      - 对于 r >= 0，优先选择靠近A地的站点位置
      - 对于 r < 0，优先选择靠近B地的站点位置

n = 3 m = 4 x = 10
p1 = 1 c1 = 1
p2 = 2 c2 = 1
p3 = 8 c3 = 3
a1 = 5 b1 = 3 r1 = 2
a2 = 7 b2 = 2 r2 = 5
a3 = 9 b3 = 0 r3 = 9
a4 = 1 b4 = 10000 r4 = -9999
 */