//
// Created by Geek.Kwok on 2025/9/9.
//
#include <iostream>
#include <map>
using namespace std;

int arr[101], flag[101], q[101];
int front, rear, maxv, cnt;
int n, k, r[10000][2];

void bfs() {
    // 针对每个人进行亲戚关系和人数统计
    for (int i = 1; i <= n; i++) {
        if (flag[i]) {
            continue;
        }
        cnt++;
        // 初始化
        int currRoundMax = 1;
        front = rear = 0;
        q[rear++] = i;
        flag[i] = true;
        while (front < rear) {
            // 出队列
            int p = q[front++];
            // 检查亲属关系
            for (int j = 1; j <= k; j++) {
                if (p == r[j][0]) {
                    // 检查亲属关系
                    int rs = r[j][1];
                    // 亲属存在且未访问过
                    if (!flag[rs]) {
                        currRoundMax++; // 当前亲属团人数加一
                        q[rear++] = rs; // 当前亲属进队列
                        flag[rs] = true; // 当前亲属被关联过了
                    }
                }
            }
        }
        // 保存最大人数的亲属团
        maxv = max(maxv, currRoundMax);
    }
}

int main() {
    cin >> n >> k;
    for (int i = 1; i <= k; i++) {
        cin >> r[i][0] >> r[i][1];
    }
    bfs();
    cout << cnt << " " << maxv << endl;
    return 0;
}