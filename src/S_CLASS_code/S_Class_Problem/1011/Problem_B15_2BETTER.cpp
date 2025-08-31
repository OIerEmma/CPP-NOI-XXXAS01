//
// Created by Emma on 2025/8/15.
//
#include<iostream>
#include<cmath>
#include<cstring>
using namespace std;

int a[201], b[201];

int main() {
    int n;
    string s1, s2;
    cin >> n;
    while (n--) {
        cin >> s1 >> s2;
        int idx1 = (int) s1.find('.'), idx2 = (int) s2.find('.'), diff = abs(idx1 - idx2);
        int number_point = idx2;
        // 使s1小s2大
        if (idx1 > idx2) {
            string tmp = s1;
            s1 = s2;
            s2 = tmp;
            number_point = idx1;
        }
        memset(a, 0, sizeof(a));
        memset(b, 0, sizeof(b));

        // 把数对齐小数点放入数组中 这里j从1开始 第0位考虑进位
        for (int i = 0, j = 1; i < s1.length(); i++, j++) {
            if (s1[i] == '.') {
                continue;
            }
            a[j + diff] = s1[i] - '0';
        }
        for (int i = 0, j = 1; i < s2.length(); i++) {
            if (s2[i] == '.') {
                continue;
            }
            b[j++] = s2[i] - '0';
        }
        // 这里减一是考虑去掉了小数点符号
        int maxlen = max(int(s1.length() + diff), int(s2.length())) - 1;
        for (int i = maxlen; i >= 1; i--) {
            // 从后往前加并进位
            b[i] += a[i];
            if (b[i] >= 10) {
                b[i] -= 10;
                b[i - 1]++;
            }
        }
        // 检查并省略小数部分尾部的零
        while (b[maxlen] == 0 && maxlen > number_point) {
            maxlen--;
        }

        // 输出结果
        // 看是否有进位 有进位则输出b[0]
        if (b[0] != 0) {
            cout << b[0];
        }
        for (int i = 1; i <= maxlen; i++) {
            // 这里输出小数点符号
            if (i == number_point + 1) {
                cout << '.';
            }
            cout << b[i];
        }
        cout << endl;
    }
    return 0;
}
