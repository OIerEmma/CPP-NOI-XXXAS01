//
// Created by Emma on 2025/7/6.
//
#include<iostream>
using namespace std;

string to_lower(string s) {
    for (int i = 0; i < s.size(); i++) {
        if (s[i] >= 'A' && s[i] <= 'Z') {
            s[i] += 32;
        }
    }
    return s;
}

int main() {
    string k, s;
    int cnt = 0, num = 0, index = 0;
    cin >> k;
    getchar();
    bool flag = false;
    while (getline(cin, s, ' ')) {
        if (to_lower(s) == to_lower(k)) {
            cnt ++;
            if (!flag) {
                flag = true;
                index = num;
            }
        }
        num += s.length() + 1;
    }
    if (flag) {
        cout << cnt << " " << index << endl;
    } else {
        cout << -1 << endl;
    }
    return 0;
}

/*
// 大写转小写函数
string to_lower(string s) {
    for (int i = 0; i < s.size(); i++) {
        if (s[i] >= 'A' && s[i] <= 'Z') {
            s[i] += 32;
        }
    }
    return s;
}

int main() {
    string s, k;
    // 输入
    cin >> k;
    getchar();
    getline(cin, s);
    s += " ";
    // 变成小写字母
    k = to_lower(k);
    s = to_lower(s);
    // 拆分单词并判断是不是目标单词
    string str;
    int last = 0, ans = 0, idx = -1, num = 0;
    for (int i = 0; i < s.size(); i++) {
        if (s[i] == ' ') {
            num++;
            str = s.substr(last, i - last);
            if (str == k) {
                if (ans == 0) {
                    idx = num - 1;
                }
                ans++;
            }
            last = i + 1;
        }
    }
    // 判断有没有单词被找到
    if (idx != -1) {
        cout << ans << " " << idx << endl;
    } else {
        cout << idx << endl;
    }
    return 0;
}
*/