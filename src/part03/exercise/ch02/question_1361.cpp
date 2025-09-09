//
// Created by Emma on 2025/9/7.
//
#include<iostream>
using namespace std;

int n, k, front, rear;
int num[20010], q[20010];
int numidx = 0;
struct node {
    int bef, aft;
} a[20];

bool f(int x) {
    for (int i = 1; i <= numidx; i++) {
        if (x == num[i]) {
            return true;
        }
    }
    return false;
}

int to_int(string s) {
    int ans = 0;
    for (int i = 0; i < s.size(); i++) {
        ans = ans * 10 + (s[i] - 48);
    }
    return ans;
}

int bfs() {
    int ans = 1;
    // 初始化
    q[rear++] = n;
    num[++numidx] = n;
    while (front < rear) {
        // 出队头元素
        // 遍历执行规则
        // for {
        //     元素中查找 a[i].bef；若有则用 a[i].aft 替换并生成新的数
        // }
        string s = to_string(q[front++]), t;
        for (int i = 1; i <= k; i++) {
            // 先找元素
            if (s.find(to_string(a[i].bef)) == string::npos) {
                continue;
            }
            int idx = 0, p;
            for (; ;) {
                t = s;
                p = (int) s.find(to_string(a[i].bef), idx);
                if (p == -1) {
                    break;
                }
                t.replace(p, 1, to_string(a[i].aft));
                int t2 = to_int(t);
                if (!f(t2)) {
                    ans++;
                    num[++numidx] = t2;
                    q[rear++] = t2;
                }
                if (p + 1 >= s.size()) {
                    break;
                }
                idx = p + 1;
            }
        }
    }
    return ans;
}

int main() {
    cin >> n >> k;
    for (int i = 1; i <= k; i++) {
        cin >> a[i].bef >> a[i].aft;
    }
    cout << bfs() << endl;
    return 0;
}
