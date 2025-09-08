//
// Created by Emma on 2025/9/7.
//
#include<iostream>
#include<algorithm>
using namespace std;

long long q[1000100];

void work(int a, int n) {
    int rear = 2;
    q[1] = a;
    int two = 1, three = 1;
    cout << 1 << " ";
    while (rear <= n) {
        long long t1 = q[two] * 2 + 1, t2 = q[three] * 3 + 1;
        int t = min(int(t1), int(t2));
        if (t1 < t2) {
            two++;
        } else {
            three++;
        }
        if (t == q[rear - 1]) {
            continue;
        }
        q[rear++] = t;
        cout << q[rear - 1] << " ";
    }
    cout << endl;
}

int main() {
    int n;
    while (cin >> n) {
        work(1, n);
    }
    return 0;
}