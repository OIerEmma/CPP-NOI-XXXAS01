//
// Created by Emma on 2025/8/18.
//
#include <iostream>
using namespace std;

// 高精度数组，每个元素存储一位十进制数字
const int MAX_DIGITS = 10001;
int decimal[MAX_DIGITS], decLen; // 存储十进制中间结果

// 高精度除法：result = result / n，返回余数
int divide(int result[], int &len, int n) {
    int remainder = 0;
    for (int i = len-1; i >= 0; i--) {
        int current = remainder * 10 + result[i];
        result[i] = current / n;
        remainder = current % n;
    }

    // 移除前导零
    while (len > 1 && result[len-1] == 0) {
        len--;
    }

    return remainder;
}

// 将字符转换为数字
int charToDigit(char c) {
    if (c >= '0' && c <= '9') {
        return c - '0';
    }
    if (c >= 'A' && c <= 'Z') {
        return c - 'A' + 10;
    }
    if (c >= 'a' && c <= 'z') {
        return c - 'a' + 10;
    }
    return 0;
}

int main() {
    int n;
    string s;
    while (cin >> n >> s) {
        // 将字符串转换为十进制数组
        decLen = s.length();
        for(int i = s.length()-1; i >= 0; i--) {
            decimal[decLen-1-i] = charToDigit(s[i]);
        }
        // 高精度除法
        cout << divide(decimal, decLen, n) << endl;
    }
    return 0;
}