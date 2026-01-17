//
// Created by Emme.Kwok on 2025/9/13.
//
#include <iostream>
using namespace std;

int dir1[8][2] = {{-1, -2},{-1, 2},{-2, -1},{-2, 1},{1, -2},{1, 2},{2, -1},{2, 1}};
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
    Point newF = Point(f.x + x, f.y + y, f.cnt + 1);
    if (checkInChess(newF) && !flag[newF.x][newF.y]) {
        q[rear++] = newF;
        flag[newF.x][newF.y] = true;
    }
    if (newF.x == 1 && newF.y == 1) {
        ans = min(ans, newF.cnt);
    }
}

int bfs(Point p, Point s) {
    ans = 100000000;
    front = rear = 0;
    memset(flag, false, sizeof(flag));
    q[rear++] = p;
    flag[p.x][p.y] = true;
    flag[s.x][s.y] = true;
    while (front < rear) {
        Point f = q[front++];
        for (int i = 0; i < 8; i++) {
            walk(f, s, dir1[i][0], dir1[i][1]);
        }
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