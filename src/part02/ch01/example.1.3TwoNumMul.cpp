//
// Created by Emma on 2025/8/11.
//
#include<iostream>
using namespace std;

char a1[101], b1[101];
int a[101], b[101], c[10001];

int main() {
    cin >> a1 >> b1;
    int lena = (int)strlen(a1), lenb = (int)strlen(b1);
    // 将字符串转换为数组
    for (int i = 0; i < lena; i++) {
        a[lena - i] = a1[i] - 48;
    }
    for (int i = 0; i < lenb; i++) {
        b[lenb - i] = b1[i] - 48;
    }
    int x;
    // 模拟乘法竖式,需要用双重循环
    for (int i = 1; i <= lena; i++) {
        x = 0;
        for (int j = 1; j <= lenb; j++) {
            c[i + j - 1] += a[i] * b[j] + x; // 一位一位做运算,就是把乘积的值加上进位的值
            x = c[i + j - 1] / 10; // 更新进位值
            c[i + j - 1] %= 10; // 保存进位之后的个位数字
        }
        c[i + lenb] = x; // 进位
    }
    int lenc = lena + lenb;
    while (c[lenc] == 0 && lenc > 1) { // 判断当前位数字为零并且非最高位,其实就是删除前导0
        lenc--;
    }
    // 输出,注意:如果我们这么处理就要倒序输出,因为我们转换时倒序存储
    for (int i = lenc; i >= 1; i--) {
        cout << c[i];
    }
    cout << endl;
    return 0;
}