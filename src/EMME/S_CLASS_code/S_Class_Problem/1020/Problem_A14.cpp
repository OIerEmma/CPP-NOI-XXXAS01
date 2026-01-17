//
// Created by Emma on 2025/8/6.
//
#include<iostream>
using namespace std;

bool a[100010];

int main() {
    int num, n;
    cin >> n;
    for (int i = 1; i <= n - 2; i++) {
        cin >> num;
        a[num] = true;
    }
    int cnt = 0;
    for (int i = 1; i <= n; i++) {
        if (!a[i]) {
            cout << i << " ";
            cnt++;
            if (cnt == 2) {
                break;
            }
        }
    }
    return 0;
}