//
// Created by Geek.Kwok on 2026/3/18.
//
#include <bits/stdc++.h>
using namespace std;

#define N 6
int book[N], c;
bool flag[N], like[N][N] = {
    {0, 0, 0, 0, 0, 0}, {0, 0, 0, 1, 1, 0}, {0, 1, 1, 0, 0, 1},
    {0, 0, 1, 1, 0, 0}, {0, 0, 0, 0, 1, 0}, {0, 0, 1, 0, 0, 1}};

void print() {
    c++;
    cout << "answer " << c << ":\n";
    for(int i = 1; i <= 5; i++) {
        cout << i << ": " << char(64 + book[i]) << endl;
    }
}

void dfs(int student) {
    if (student == 5 + 1) {
        print();
        return;
    }
    for (int b = 1; b <= 5; b++) {
        if (!flag[b] || !like[student][b]) continue;
        flag[b] = false;
        book[student] = b;
        dfs(student + 1);
        flag[b] = true;
        book[student] = 0;
    }
}

int main() {
    for (int i = 1; i <= 5; i++) {
        flag[i] = true;
    }
    dfs(1);
}