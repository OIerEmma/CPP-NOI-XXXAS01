//
// Created by Emma on 2025/8/18.
//
#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;

// 高精度数组，每个元素存储一位十进制数字
const int MAX_DIGITS = 100001;
int decimal[MAX_DIGITS], decLen; // 存储十进制中间结果
char digits[MAX_DIGITS]; // 存储M进制中间结果

// 高精度乘法：result = result * m
void multiply(int result[], int &len, int m) {
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

// 高精度加法：result = result + digit
void add(int result[], int &len, int digit) {
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
    } else if (c >= 'A' && c <= 'Z') {
        return c - 'A' + 10;
    } else if (c >= 'a' && c <= 'z') {
        return c - 'a' + 10;
    }
    return 0;
}

// 将数字转换为字符
char digitToChar(int digit) {
    if (digit >= 0 && digit <= 9) {
        return '0' + digit;
    } else if (digit >= 10 && digit <= 35) {
        return 'a' + (digit - 10);
    }
    return '0';
}

// N进制转十进制的高精度算法
void nToDecimal(string nNumber, int n) {
    // 初始化十进制数组
    memset(decimal, 0, sizeof(decimal));
    decimal[0] = 0;
    int len = 1;

    // 从高位到低位处理每一位
    for (int i = 0; i < nNumber.length(); i++) {
        // 将当前结果乘以进制数n
        multiply(decimal, len, n);
        // 加上当前位的值
        int digit = charToDigit(nNumber[i]);
        add(decimal, len, digit);
    }
    // 数组长度存放在decLen
    decLen = len;
}

// 检查数字是否为零
bool isZero(int arr[], int len) {
    return len == 1 && arr[0] == 0;
}

// 十进制转M进制的高精度算法
string decimalToM(int decimal[], int &len, int m) {
    int dlen = 0;
    memset(digits, 0, sizeof(digits));

    // 不断除以m，记录余数
    while (!isZero(decimal, len)) {
        int remainder = divide(decimal, len, m);
        digits[dlen++] = digitToChar(remainder);
    }

    // 反转得到正确顺序
    string result = "";
    for (int i = dlen-1; i >= 0; i--) {
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
    // 第一步：N进制转十进制
    nToDecimal(s, n);
    // 输出
    // printDecimal(decimal);
    // 第二步：十进制转M进制
    return decimalToM(decimal, decLen, m);
}

int main() {
    int n, m;
    string s;
    while(cin >> s) {
        // 将字符串转换为十进制数组
        decLen = s.length();
        for(int i = s.length()-1; i >= 0; i--) {
          decimal[decLen-1-i] = charToDigit(s[i]);
        }
        // printDecimal(decimal);
        // 十进制转换为二进制
        string result = decimalToM(decimal, decLen, 2);
        // cout << "result: " << result << endl;
        // 反转
        reverse(result.begin(), result.end());
        // cout << "reverse result: " << result << endl;
        // 二进制转十进制
        nToDecimal(result, 2);
        // 输出
        printDecimal(decimal);
    }
    return 0;
}