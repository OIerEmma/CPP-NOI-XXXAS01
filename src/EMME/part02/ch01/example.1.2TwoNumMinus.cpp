//
// Created by Emma on 2025/8/6.
//
#include<iostream>
using namespace std;

int a[200], b[200], c[200], i;
char n[200], n1[200], n2[200];

int main() {
    cin >> n1 >> n2;
    if (strlen(n1) < strlen(n2) || strlen(n1) == strlen(n2)
        && strcmp(n1, n2) < 0) { // 判断结果是否是一个负数
        // strcmp()函数是比较两个字符串(字符数组)的关系,n1 == n2返回0;
        // n1 < n2返回负整数,n1 > n2返回正整数
        strcpy(n, n1);
        strcpy(n1, n2);
        strcpy(n2, n);
        // strcpy()函数是把一个字符串(字符数组)赋值整体给另一个字符串(字符数组)
        // strcpy就是string copy的缩写
        cout << "-"; // 如果是一个负数就先输出负号
    }
    size_t lena = strlen(n1), lenb = strlen(n2), lenc;
    // 将字符串转换为数组
    for (i = 0; i < lena; i++) {
        a[lena - i] = int(n1[i] - '0');
    }
    for (i = 0; i < lenb; i++) {
        b[lenb - i] = int(n2[i] - '0');
    }
    i = 1;
    while (i <= lena || i <= lenb) {
        if (a[i] < b[i]) { // 判断是否需要借位
            // 借位
            a[i] += 10;
            a[i + 1]--;
        }
        c[i] = a[i] - b[i]; // 一位一位做运算
        i++;
    }
    // 这个判断是前面借位运算后可能i所在数位已经为零了所以在后面要从第1个非零的数开始输出
    // 那么这个while循环lenc--就是为了找到第一个非零的数位然后输出
    lenc = i;
    while (c[lenc] == 0 && lenc > 1) { // 判断当前位数字为零并且非最高位,其实就是删除前导0
        lenc--;
    }
    // 输出,注意:如果我们这么处理就要倒序输出,因为我们转换时倒序存储
    for (i = int(lenc); i >= 1; i--) {
        cout << c[i];
    }
    cout << endl;
    return 0;
}
