//
// Created by Geek.Kwok on 2026/3/30.
//
#include <iostream>
using namespace std;

int n, a[100001];


void heap(int h[], int n, int idx) {
    // 一次操作使 h 满足堆的性质，得到 1 个最大数在 h[idx] 中

    int x = h[idx]; // 把待调整的结点值暂存起来
    int i = idx, j = 2 * i; // j 存放 idx 的孩子中值大的结点编号，开始时为 idx 的左孩子编号
    while (j <= n) {
        // 若 idx 有右孩子且值比左孩子大则把 j 设置为右孩子的编号
        if (j < n && h[j] < h[j + 1]) j++;
        // 若父结点比孩子结点小则调整父结点和孩子结点中值大的那个结点，确保此处满足堆的性质
        if (x < h[j]) {
            h[i] = h[j];
            i = j;
            j = 2 * i;
        } else j = n + 1; // 故意让 j 超出范围而终止循环
    }
    h[i] = x; // 调整到最终位置
}

int main() {
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    for (int i = n/2; i >= 1; i--) {
        heap(a, n, i); // 建立初始堆，且产生最大值a[1]
    }
    for (int i = n; i >= 2; i--) {
        // 将当前最大值交换到最终位置上，再对前 i-1 个数调整
        swap(a[1], a[i]);
        heap(a, i - 1, 1);
    }
    for (int i = 1; i < n; i++) {
        cout << a[i] << " ";
    }
    cout << a[n] << endl;
    return 0;
}