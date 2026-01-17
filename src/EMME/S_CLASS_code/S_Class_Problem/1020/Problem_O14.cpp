//
// Created by Emma on 2025/8/11.
//
#include<iostream>
using namespace std;

int a[31], odd[31], even[31];

int main() {
    int n;
    cin >> n;
    int o = 1, e = 1;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        if (a[i] % 2 == 0) {
            even[e++] = a[i];
        } else {
            odd[o++] = a[i];
        }
    }
    for (int i = 1; i < e; i++) {
        cout << even[i] << " ";
    }
    cout << endl;
    for (int i = 1; i < o; i++) {
        cout << odd[i] << " ";
    }
    return 0;
}
