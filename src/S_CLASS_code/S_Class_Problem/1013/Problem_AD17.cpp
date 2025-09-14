//
// Created by Emme.Kwok on 2025/9/13.
//
#include<iostream>
using namespace std;

int xf, yf, xs, ys;
int rear, front;
int q[110][5];

int bfs(int x, int y) {
    int ans = 0;
    rear = front = 0;
    q[rear++][1] = x;
    q[rear++][2] = y;
    while (front < rear) {
        if (x == 1 && y == 1) {

        }
    }
}

int main() {
    cin >> xf >> yf >> xs >> ys;
    cout << bfs(xf, yf) << endl << bfs(xs, ys) << endl;
    return 0;
}
