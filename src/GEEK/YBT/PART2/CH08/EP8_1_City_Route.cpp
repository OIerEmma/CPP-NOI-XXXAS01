//
// Created by Geek.Kwok on 2026/3/18.
//
#include <bits/stdc++.h>
using namespace std;

bool s[9];
int a[101], b[101];

int ju[9][9] = {{0,0,0,0,0,0,0,0,0},
                {0,1,0,0,0,1,0,1,1},
                {0,0,1,1,1,1,0,1,1},
                {0,0,1,1,0,0,1,1,1},
                {0,0,1,0,1,1,1,0,1},
                {0,1,1,0,1,1,1,0,0},
                {0,0,0,1,1,1,1,1,0},
                {0,1,1,1,0,0,1,1,0},
                {0,1,1,1,1,0,0,0,1}};

void out(int d) { // 输出过程
    cout << char(a[d] + 64);
    while (b[d]) {
        d = b[d];
        cout << "--" << char(a[d] + 64);
    }
    cout << endl;
}

void doit() {
    int head, tail, i;
    head = 0; tail = 1; // 队首为0、队尾为1
    a[1] = 1; // 记录经过的城市
    b[1] = 0; // 记录前驱城市
    s[1] = true; // 表示该城市已经到过
    do {
        head++; // 队首加一，出队
        for (int i = 1; i <= 8; i++) { // 搜索可直通的城市
            if (ju[a[head]][i] == 0 && s[i] == false) { // 判断城市是否走过
                tail++;
                a[tail] = i;
                b[tail] = head;
                s[i] = true;
                if (i == 8) { // 第一次搜索到H城市时路线最短
                    out(tail);
                    head = tail;
                    break;
                }
            }
        }
    } while (head < tail);
}

int main() {
    doit();
    return 0;
}