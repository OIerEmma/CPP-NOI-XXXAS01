//
// Created by Emma on 2025/8/11.
//
#include<iostream>
using namespace std;

char a1[101];
int a[101], c[101];

int main() {
    long long b;
    cin >> a1 >> b;
    int lena = (int)strlen(a1);
    // 将字符串转换为数组
    for (int i = 0; i < lena; i++) {
        a[i + 1] = a1[i] - 48;
    }
    int x = 0;
    for (int i = 1; i <= lena; i++) { // 按位相除
        // 一位一位做运算,这里(x * 10 + a[i])就是把被除数现在这意味的值加上次的余数的值
        c[i] = (x * 10 + a[i]) / (int)b; // 上次余数要乘10,因为上次的1在除后一位就变成10了
        x = (x * 10 + a[i]) % (int)b; // 保存余数
    }
    int lenc = 1;
    while (c[lenc] == 0 && lenc < lena) { // 判断当前位数字为零并且非最高位,其实就是删除前导0
        lenc++;
    }
    // 输出,注意:如果我们这么处理就不能再倒序输出,因为我们转换时并没有倒序存储
    for (int i = lenc; i <= lena; i++) {
        cout << c[i];
    }
    cout << endl;
    return 0;
}