//
// Created by Emma on 2025/3/10.
//
#include<iostream>
#include<cstring>
using namespace std;

int main() {
    int n, m, num;
    cin >> n >> m;
    bool a[n], flag = true;
    memset(a, false, sizeof(a));
    for (int i = 0; i < m; i++) {
        cin >> num;
        a[num] = true;
    }
    for (int i = 0; i < n; i++) {
        if (a[i] == false) {
            flag = false;
            cout << i << " ";
        }
    }
    if (flag == true) {
        cout << n << endl;
    }
    return 0;
}
