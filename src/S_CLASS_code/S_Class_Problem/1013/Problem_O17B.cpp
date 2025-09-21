//
// Created by Emme.Kwok on 2025/9/14.
//
#include<iostream>
#include<cstring>
using namespace std;

int mem[1010];
int front, rear, par;

bool isInQueue(int par) {
    for (int i = front; i < rear; i++) {
        if (mem[i] == par) {
            return true;
        }
    }
    return false;
}

int main() {
    int n, m, cnt = 0;
    cin >> m >> n;
    for (int i = 0; i < n; i++) {
        cin >> par;
        if (!isInQueue(par)) {
            cnt++;
            if (rear - front >= m) {
                mem[front++] = 0;
            }
            mem[rear++] = par;
        }
    }
    cout << cnt << endl;
    return 0;
}