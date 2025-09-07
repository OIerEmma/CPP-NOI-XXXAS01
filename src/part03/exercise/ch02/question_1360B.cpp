//
// Created by Emma on 2025/9/6.
//
#include<iostream>
#include<cmath>
using namespace std;

const int STEPS = 100000000;
int minv = STEPS, n, init_f, target_f;
int k[210], q[420], f[210], a[210];
int front, rear;

void jump(const int from_f, const int grids) {
    // 计算上跳或下跳到哪一层
    const int to_f = from_f + grids;
    // 目标楼层合法性判断
    if (to_f < 1 || to_f > n) {
        return;
    }
    // 跳转次数加1
    a[to_f] = a[from_f] + 1;
    if (to_f == target_f) {
        // 到达目标层 计算最小步数
        minv = min(minv, a[to_f]);
    } else if (!f[to_f]) {
        // 到达满足条件的层数则入队
        q[rear++] = to_f;
        // 更新f[to_f]为true 代表此楼层我已经走过了
        f[to_f] = true;
    }
}

void bfs() {
    // 初始化队列和头尾指针
    front = rear = 0;
    q[rear++] = init_f;
    // BFS框架代码
    while (front < rear) {
        // 取队列头元素
        const int ele = q[front++];
        // 上跳或下跳并检查
        jump(ele, k[ele]);
        jump(ele, -k[ele]);
    }
}

int main() {
    // input
    cin >> n >> init_f >> target_f;
    for (int i = 1; i <= n; i++) {
        cin >> k[i];
    }
    // bfs
    bfs();
    // output
    if (init_f == target_f) {
        // 如果初始楼层等于目标楼层 不需要走了 输出0
        cout << 0 << endl;
    } else if (minv < STEPS) {
        // 如果minv被更新过了(就是不等于初始值了) 输出minv
        cout << minv << endl;
    } else {
        cout << -1 << endl;
    }
    return 0;
}
