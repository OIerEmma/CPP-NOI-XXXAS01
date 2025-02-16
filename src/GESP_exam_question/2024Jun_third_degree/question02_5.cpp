//
// Created by Emma on 2025/2/12.
//
#include<iostream>
using namespace std;
int a[100001];

int main() {
    int t;
    scanf("%d", &t);
    for (int x = 1; x <= t; x++) {
        int n;
        bool flag = true;
        scanf("%d", &n);
        int maxvalue = -1;
        for (int i = 1; i <= n; i++) {
            scanf("%d", &a[i]);
        }
        for (int i = 1; i <= n; i++) {
            maxvalue = max(maxvalue, a[i]);
        }
        for (int i = 1; i <= n; i++) {
            if (maxvalue % a[i] != 0) {
                flag = false;
                break;
            }
        }
        if (flag) {
            cout << "Yes\n";
        } else {
            cout << "No\n";
        }
    }
    return 0;
}
