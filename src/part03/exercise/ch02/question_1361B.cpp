//
// Created by Geek.Kwok on 2025/9/8.
//
#include <iostream>
#include <string>
#include <set>
using namespace std;

int cnt = 1, front, rear, k;
string n;
string q[20001], rule[16][2];
set<string> s;

void bfs() {
    // 初始化Q
    q[rear++] = n;
    s.insert(n);
    // bfs
    while (front < rear) {
        string source = q[front++], target;
        // execute rules
        for (int i = 1; i <= k; i++) {
            int idx = 0, tmp;
            // find string index
            do {
                tmp = (int) source.find(rule[i][0], idx);
                if (tmp != -1) {
                    target = source.substr(0, tmp) + rule[i][1] + source.substr(tmp + rule[i][0].length());
                    // 新元素
                    if (s.find(target) == s.end()) {
                        cnt++; // 元素++
                        s.insert(target); // 存到集合做重复判断
                        q[rear++] = target; // 入队
                    }
                }
                if (tmp == -1 || tmp >= source.length()-1) {
                    break;
                }
                idx = tmp + 1;
            } while (true);
        }
    }
}

int main() {
    // input
    cin >> n >> k;
    for (int i = 1; i <= k; i++) {
        cin >> rule[i][0] >> rule[i][1];
    }
    // bfs
    bfs();
    // output
    cout << s.size() << endl;
    return 0;
}
