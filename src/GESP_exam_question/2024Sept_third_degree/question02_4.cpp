//
// Created by Emma on 2025/2/10.
//
#include<iostream>
using namespace std;

bool backstring(string a) {
    bool ans = false;
    for (int i = 0; i < a.size() / 2; i++) {
        if (a[i] == a[a.size() - (i + 1)]) {
            ans = true;
        } else {
            ans = false;
            break;
        }
    }
    return ans;
}

int main() {
    string a;
    int n;
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) {
        cin >> a;
        bool flag = false;
        for (int split = 2; split < a.size() - 1; split ++) {
            // 1. 拆分成a和b两部分
            string part1 = a.substr(0, split);
            string part2 = a.substr(split, a.size() - split);
            // 2. 同时分别判断a和b的回文串
            if (backstring(part1) && backstring(part2)) {
                flag = true;
                printf("Yes\n");
                break;
            }
        }
        if (!flag) {
            printf("No\n");
        }
    }
    return 0;
}
