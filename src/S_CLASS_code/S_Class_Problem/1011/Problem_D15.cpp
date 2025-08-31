//
// Created by Emma on 2025/8/18.
//
#include <iostream>
#include <cstring>
using namespace std;

const int MAX_DIGITS = 100001; // 高精度数组，每个元素存储一位十进制数字
int decimal[MAX_DIGITS], decLen; // 存储十进制中间结果
char digits[MAX_DIGITS]; // 存储M进制中间结果

void multiply(int result[], int &len, int m) { // 高精度乘法：result = result * m
    int carry = 0;
    for (int i = 0; i < len; i++) {
        int product = result[i] * m + carry;
        result[i] = product % 10;
        carry = product / 10;
    }
    while (carry > 0) {
        result[len] = carry % 10;
        carry /= 10;
        len++;
    }
}

void add(int result[], int &len, int digit) { // 高精度加法：result = result + digit
    int carry = digit;
    for (int i = 0; i < len && carry > 0; i++) {
        int sum = result[i] + carry;
        result[i] = sum % 10;
        carry = sum / 10;
    }
    while (carry > 0) {
        result[len] = carry % 10;
        carry /= 10;
        len++;
    }
}

int divide(int result[], int &len, int n) { // 高精度除法：result = result / n，返回余数
    int remainder = 0;
    for (int i = len-1; i >= 0; i--) {
        int current = remainder * 10 + result[i];
        result[i] = current / n;
        remainder = current % n;
    }
    while (len > 1 && result[len-1] == 0) { // 移除前导零
        len--;
    }
    return remainder;
}

int charToDigit(char c) { // 将字符转换为数字
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

char digitToChar(int digit) { // 将数字转换为字符
    if (digit >= 0 && digit <= 9) {
        return '0' + digit;
    }
    if (digit >= 10 && digit <= 35) {
        return 'a' + (digit - 10);
    }
    return '0';
}

void nToDecimal(string nNumber, int n) { // N进制转十进制的高精度算法
    memset(decimal, 0, sizeof(decimal)); // 初始化十进制数组
    decimal[0] = 0;
    int len = 1;
    for (int i = 0; i < nNumber.length(); i++) { // 从高位到低位处理每一位
        multiply(decimal, len, n); // 将当前结果乘以进制数n
        int digit = charToDigit(nNumber[i]); // 加上当前位的值
        add(decimal, len, digit);
    }
    decLen = len; // 数组长度存放在decLen
}

bool isZero(int arr[], int len) { // 检查数字是否为零
    return len == 1 && arr[0] == 0;
}

string decimalToM(int decimal[], int &len, int m) { // 十进制转M进制的高精度算法
    int dlen = 0;
    memset(digits, 0, sizeof(digits));
    while (!isZero(decimal, len)) { // 不断除以m，记录余数
        int remainder = divide(decimal, len, m);
        digits[dlen++] = digitToChar(remainder);
    }
    string result = "";
    for (int i = dlen-1; i >= 0; i--) { // 反转得到正确顺序
        result += digits[i];
    }
    return result;
}

void printDecimal(int decimal[]) {
    for (int i = decLen-1; i >= 0; i--) {
        cout << decimal[i];
    }
    cout << endl;
}

string nToM(string s, int n, int m) {
    nToDecimal(s, n);// 第一步：N进制转十进制
    return decimalToM(decimal, decLen, m);// 第二步：十进制转M进制
}

int main() {
    int n, m;
    while(cin >> n >> m) {
        string s;
        cin >> s;
        cout << nToM(s, n, m) << endl;
    }
    return 0;
}