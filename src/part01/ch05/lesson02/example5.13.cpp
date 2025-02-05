//
// Created by Emma on 2025/1/20.
//
#include<iostream>
using namespace std;

int main() {
    int a[20][20], n;
    cin >> n;
    int c = n, temp = 1;
    while (c) {
        if (c == 1)
        {
            a[n / 2][n / 2] = temp;
            break;
        }
        int y = (n - c) / 2, x = (n - c) / 2 + c - 1;
        int end = y + c - 1;
        //处理右面
        for (; y <= end; y++, temp++)
        {
            a[y][x] = temp;
        }
        y = end;
        end = x - c + 1;
        x--;
        //处理下面
        for (; x >= end; x--, temp++)
        {
            a[y][x] = temp;
        }
        x = end;
        end = y - c + 1;
        y--;
        //处理左面
        for (; y >= end; y--, temp++)
        {
            a[y][x] = temp;
        }
        y = end;
        end = x + c - 1;
        x++;
        //处理上面
        for (; x < end; x++, temp++)
        {
            a[y][x] = temp;
        }
        c -= 2;
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cout << a[i][j] << ' ';
        }
        cout << endl;
    }
}
