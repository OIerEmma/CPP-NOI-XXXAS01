//
// Created by Emme.Kwok on 2025/9/14.
//
#include<iostream>
using namespace std;

int q[1010];
int front, rear;

int main() {
    int n, t, cge;
    while (cin >> n) {
        front = rear = 1;
        for (int i = 1; i <= n; i++) {
            cin >> t;
            if (t == 1) {
                front = rear = 1;
            } else if (t == 2) {
                cin >> cge;
                if (rear - front >= 10) {
                    cout << "queue out" << endl;
                    continue;
                }
                q[rear++] = cge;
            } else if (t == 3) {
                if (rear == front) {
                    cout << "queue empty" << endl;
                    continue;
                }
                q[front++] = 0;
            } else {
                cout << rear - front << endl;
                for (int j = front; j < rear; j++) {
                    cout << q[j] << " ";
                }
                cout << endl;
            }
        }
    }
    return 0;
}
