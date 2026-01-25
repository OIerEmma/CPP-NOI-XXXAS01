//
// Created by Emme.Kwok on 2026/1/25.
//
#include<iostream>
using namespace std;

const int maxn = 10005;
int a[maxn], b[maxn];
struct team {
    int boss, num;
} t[maxn];

int main() {
    freopen("monkey.in", "r", stdin);
    freopen("monkey.out", "w", stdout);
    int n, m;
    cin >> n >> m;
    for (int i = 1; i <= m; i++) {
        cin >> a[i] >> b[i];
    }
    for (int i = 1; i <= n; i++) {
        t[i].boss = i;
        t[i].num = 1;
    }
    for (int i = 1; i <= m; i++) {
        if (t[a[i]].boss == t[b[i]].boss) {
            continue;
        }
        int nboss, nnum, onum = 0, oboss;
        if (t[a[i]].num > t[b[i]].num) {
            nboss = t[a[i]].boss;
            nnum = t[a[i]].num;
            oboss = t[b[i]].boss;
        } else if (t[a[i]].num < t[b[i]].num) {
            nboss = t[b[i]].boss;
            nnum = t[b[i]].num;
            oboss = t[a[i]].boss;
        } else {
            if (t[a[i]].boss < t[b[i]].boss) {
                nboss = t[a[i]].boss;
                nnum = t[a[i]].num;
                oboss = t[b[i]].boss;
            } else {
                nboss = t[b[i]].boss;
                nnum = t[b[i]].num;
                oboss = t[a[i]].boss;
            }
        }
        for (int j = 1; j <= n; j++) {
            if (t[j].boss == oboss) {
                t[j].boss = nboss;
                onum++;
            }
        }
        for (int j = 1; j <= n; j++) {
            if (t[j].boss == nboss) {
                t[j].num = nnum + onum;
            }
        }
    }
    for (int i = 1; i <= n; i++) {
        cout << t[i].boss << endl;
    }
    return 0;
}