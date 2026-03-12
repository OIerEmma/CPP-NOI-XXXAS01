//
// Created by Emma on 2025/8/28.
//
#include<iostream>
using namespace std;

long long q[1000100];

void work(int a, int n) {
    int rear = 2;
    q[1] = a;
    int two = 1, three = 1;
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
    }
    cout << q[n] << endl;
}

int main() {
    int a, n;
    while (cin >> a) {
        cin >> n;
        work(a, n);
    }
    return 0;
}