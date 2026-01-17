//
// Created by Emma on 2025/8/11.
//
#include<iostream>
#include<cstring>
using namespace std;

int a[101], b[101], c[101];

void init(int a[]) { // 将字符串转换为数组并倒序存储
    string s;
    cin >> s;
    a[0] = (int) s.size(); // 计算字符串长度
    for (int i = 1; i <= a[0]; i++) {
        a[i] = s[a[0] - i] - '0';
    }
}

void print(int a[]) { // 打印输出
    if (a[0] == 0) {
        cout << 0 << endl;
        return;
    }
    for (int i = a[0]; i > 0; i--) {
        cout << a[i];
    }
    cout << endl;
}

int compare(const int a[], const int b[]) { // 比较a与b的大小关系,如果a>b则返回1,如果a<b返回-1,如果a=b返回0
    // 初步判断a的位数是不是比b的位数多
    if (a[0] > b[0]) {
        return 1;
    }
    if (a[0] < b[0]) {
        return -1;
    }
    for (int i = a[0]; i > 0; i--) {
        if (a[i] > b[i]) {
            // a的这一位大于b的这一位则a比b大
            return 1;
        }
        if (a[i] < b[i]) {
            // a的这一位小于b的这一位则a比b小
            return -1;
        }
    }
    return 0; // 各位都一样则两数相等
}

void minusnum(int a[], int b[]) { //计算a-b的结果
    // 判断a与b大小关系
    if (compare(a, b) == 0) {
        a[0] = 0;
    } else if (compare(a, b) == 1) {
        for (int i = 1; i <= a[0]; i++) {
            if (a[i] < b[i]) { // 判断是否需要借位
                // 借位
                a[i + 1]--;
                a[i] += 10;
            }
            a[i] -= b[i]; // 一位一位计算相减
        }
        while (a[0] > 0 && a[a[0]] == 0) { // 修正a的位数
            a[0]--;
        }
    }
}

void numcpy(const int p[], int q[], int det) { // 从q数组det的地方复制p数组到q数组里去
    for (int i = 1; i <= p[0]; i++) {
        q[i + det - 1] = p[i];
    }
    q[0] = p[0] + det - 1;
}

void chugao(int a[], int b[], int c[]) {
    int tmp[101];
    c[0] = a[0] - b[0] + 1;
    for (int i = c[0]; i > 0; i--) {
        memset(tmp, 0, sizeof(tmp));
        numcpy(b, tmp, i);
        while (compare(a, tmp) >= 0) {
            c[i]++;
            minusnum(a, tmp);
        }
    }
    while (c[0] > 0 && c[c[0]] == 0) {
        c[0]--;
    }
}

int main() {
    init(a);
    init(b);
    chugao(a, b, c);
    print(c);
    print(a);
    return 0;
}
