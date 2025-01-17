#include <iostream>
using namespace std;
int direction[4][2] = {{1, 0}, {0, -1}, {-1, 0}, {0, 1}};

int main() {
    int n, num = 1;
    int a[5001][5001];
    cin >> n;
    // for (int offset = 0; offset < n/2; offset ++) {
    //     int row = 0 + offset, col = n - 1 - offset;
    //     // 下
    //     while (num < n * n && row >= 0 + offset && row < n - offset && col >= 0 + offset && col < n - offset) {
    //         a[row][col] = num ++;
    //         row += direction[0][0];
    //         col += direction[0][1];
    //     }
    //     row = n - 1 - offset, col = n - 1 - offset - 1;
    //     // 左
    //     while (num < n * n && row >= 0 + offset && row < n - offset && col >= 0 + offset && col < n - offset) {
    //         a[row][col] = num ++;
    //         row += direction[1][0];
    //         col += direction[1][1];
    //     }
    //     row = n - 1 - offset - 1, col = 0 + offset;
    //     // 上
    //     while (num < n * n && row >= 0 + offset && row < n - offset && col >= 0 + offset && col < n - offset) {
    //         a[row][col] = num ++;
    //         row += direction[2][0];
    //         col += direction[2][1];
    //     }
    //     row = 0 + offset, col = 0 + offset + 1;
    //     // 右
    //     while (num < n * n && row >= 0 + offset && row < n - offset && col >= 0 + offset && col < n - offset - 1) {
    //         a[row][col] = num ++;
    //         row += direction[3][0];
    //         col += direction[3][1];
    //     }
    // }
    // a[(n-1)/2][(n-1)/2] = num;
    // for (int i = 0, j; i < n; i++) {
    //     for (j = 0; j < n - 1; j++) {
    //         cout << a[i][j] << " ";
    //     }
    //     cout << a[i][j] << endl;
    // }
    return 0;
}