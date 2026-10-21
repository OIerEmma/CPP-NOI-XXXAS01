//
// Created by Geek.Kwok on 2026/10/21.
//
#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    list<pair<int, int>> l;
    for (int i = 1, e; i <= n; i++) scanf("%d", &e), l.push_back({e, i});
    while (!l.empty()) {
        // 找到所有的块头并输出
        bool isFirstElement = true;
        int prevE = -1;
        for (auto it = l.begin(); it != l.end(); ) {
            if (isFirstElement || prevE != (*it).first) {
                if (isFirstElement) isFirstElement = false;
                printf("%d ", (*it).second);
                prevE = (*it).first;
                l.erase(it++);
            } else ++it;
        }
        printf("\n");
    }
    return 0;
}