//
// Created by Geek.Kwok on 2025/9/13.
//
#include <iostream>
using namespace std;

// 日的走法
int dir1[8][2] = {{-1, -2},{-1, 2},{-2, -1},{-2, 1},{1, -2},{1, 2},{2, -1},{2, 1}};
// 田的走法
int dir2[4][2] = {{-2, -2},{-2, 2},{2, -2},{2, 2}};

struct Point {
    int x, y, cnt;
    Point(): x(0), y(0) {}
    Point(int x, int y, int cnt): x(x), y(y), cnt(cnt) {}
};
Point q[100*100];
bool flag[101][101];
int front, rear, ans;
int xx1, yy1, xx2, yy2;

bool checkInChess(Point p) {
    return !(p.x > 100 || p.x < 1 || p.y > 100 || p.y < 1);
}

void walk(Point f, Point s, int x, int y) {
    // 2.3 满足条件的节点入队，统计相关数据
    Point newF = Point(f.x + x, f.y + y, f.cnt + 1);
    // 不能踩另一个马的坐标
    // if (newF.x == s.x && newF.y == s.y) {
    //     return;
    // }
    if (checkInChess(newF) && !flag[newF.x][newF.y]) {
        q[rear++] = newF;
        flag[newF.x][newF.y] = true;
    }
    // 判断新节点是否达到了目标节点（1,1） 若是求最小步数
    if (newF.x == 1 && newF.y == 1) {
        ans = min(ans, newF.cnt);
    }
}

int bfs(Point p, Point s) {
    ans = 100000000;
    front = rear = 0;
    memset(flag, false, sizeof(flag));
    // 1. 初始化（第1个出发点入队列）
    q[rear++] = p;
    flag[p.x][p.y] = true;
    flag[s.x][s.y] = true;
    while (front < rear) {
        // 2.1 front element = 队头出队
        Point f = q[front++];
        // 2.2 front element 逻辑处理：延伸出下一层的所有节点
        // 走日
        for (int i = 0; i < 8; i++) {
            walk(f, s, dir1[i][0], dir1[i][1]);
        }
        // 走田
        for (int i = 0; i < 4; i++) {
            walk(f, s, dir2[i][0], dir2[i][1]);
        }
    }
    return ans;
}

int main() {
    cin >> xx1 >> yy1 >> xx2 >> yy2;
    Point p1 = Point(xx1, yy1, 0);
    Point p2 = Point(xx2, yy2, 0);
    cout << bfs(p1, p2) << endl;
    cout << bfs(p2, p1) << endl;
    return 0;
}