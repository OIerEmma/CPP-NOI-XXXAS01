//
// Created by Emma on 2025/9/7.
//
#include<iostream>
using namespace std;

const int STEPS = 100000000;
int minv = STEPS, n, init_f, target_f;
int k[210], q[210], a[210];
bool f[210];
int front, rear;

void jump(const int from_f, const int grids) {
    const int to_f = from_f + grids;
    if (to_f < 1 || to_f > n) {
        return;
    }
    a[to_f] = a[from_f] + 1;
    if (to_f == target_f) {
        minv = min(minv, a[to_f]);
    } else if (!f[to_f]) {
        q[rear++] = to_f;
        f[to_f] = true;
    }
}

void bfs() {
    front = rear = 0;
    q[rear++] = init_f;
    while (front < rear) {
        const int ele = q[front++];
        jump(ele, k[ele]);
        jump(ele, -k[ele]);
    }
}

int main() {
    cin >> n >> init_f >> target_f;
    for (int i = 1; i <= n; i++) {
        cin >> k[i];
    }
    bfs();
    if (init_f == target_f) {
        cout << 0 << endl;
    } else if (minv != STEPS) {
        cout << minv << endl;
    } else {
        cout << -1 << endl;
    }
    return 0;
}