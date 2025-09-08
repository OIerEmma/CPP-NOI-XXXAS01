//
// Created by Emma on 2025/9/7.
//
#include<iostream>
using namespace std;

int n, k, front, rear;
int num[2010], q[2010];
int numidx = 0;

struct node {
    int bef, aft;
} a[2010];

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

void bfs() {
    int ans = front = 0, i = 1;
    rear = 1;
    string s = to_string(n), t = s;
    while (front < rear) {
        if (s.find(to_string(a[i].bef)) == string::npos) {
            continue;
        }
        int p = (int) s.find(to_string(a[i].bef));
        t.replace(p, 1, to_string(a[i].aft));
        int t2 = to_int(t);
        if (!f(t2)) {
            ans++;
            num[++numidx] = t2;
        }
        i++;
    }
}

int main() {
    cin >> n >> k;
    for (int i = 1; i <= k; i++) {
        cin >> a[i].bef >> a[i].aft;
    }
    return 0;
}
