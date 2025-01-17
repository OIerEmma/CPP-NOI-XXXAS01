//
// Created by Emma on 2025/1/16.
//
#include<iostream>
using namespace std;
int a[100], b[100];

int main() {
    int n, b_size = 0;
    // 输入
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    // 去重
    b[b_size++] = a[0];
    for (int j, k = 1; k < n; k++) {
        int item = a[k];
        for (j = 0; j < b_size; j++) {
            if (item == b[j]) {
                break;
            }
        }
        if (j == b_size) {
            b[b_size++] = item;
        }
    }
    // 冒泡排序
    for (int x = 0; x < b_size - 1; x++) {
        for (int y = 0; y < b_size - x - 1; y++) {
            if (b[y] > b[y + 1]) {
                swap(b[y], b[y + 1]);
            }
        }
    }
    cout << b_size << endl;
    for (int i = 0; i < b_size; i++) {
        cout << b[i] << " ";
    }
    return 0;
}
