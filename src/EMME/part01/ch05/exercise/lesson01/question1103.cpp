//
// Created by Emma on 2025/1/18.
//
#include<iostream>
using namespace std;
int a[11];

int main() {
    int highTaoTao, ans = 0;
    for (int i = 1; i <= 10; i++) {
        cin >> a[i];
    }
    cin >> highTaoTao;
    for (int j = 1; j <= 10; j++) {
        if (highTaoTao >= a[j]) {
            ans++;
        } else {
            if (highTaoTao + 30 >= a[j]) {
                ans++;
            }
        }
    }
    cout << ans << endl;
    return 0;
}
