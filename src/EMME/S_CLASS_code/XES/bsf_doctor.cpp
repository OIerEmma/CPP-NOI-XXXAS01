//
// Created by Emme.Kwok on 2025/11/24.
//
// #include<bits/stdc++.h>
#include <iostream>
#include <queue>
using namespace std;

struct node {
    int id, doctor, l;
};

queue<node> qa, qb, qc;

node find_max(queue<node> &q) {
    int s = q.size();
    node maxx = {0, 0, 0};
    for (int i = 1; i <= s; i++) {
        node x = q.front();
        q.pop();
        if (x.l > maxx.l) {
            if (!(maxx.id == 0 && maxx.doctor == 0 && maxx.l == 0)) {
                q.push(maxx);
            }
            maxx = x;
        } else {
            q.push(x);
        }
    }
    return maxx;
}

int main() {
    int t, no = 0;
    string s;
    int doctor, level, doctor2;
    cin >> t;
    while (t--) {
        cin >> s;
        if (s == "IN") {
            cin >> doctor >> level;
            no++;
            if (doctor == 1) {
                qa.push({no, doctor, level});
            } else if (doctor == 2) {
                qb.push({no, doctor, level});
            } else {
                qc.push({no, doctor, level});
            }
        } else {
            cin >> doctor2;
            if (doctor2 == 1) {
                if (!qa.empty()) {
                    cout << find_max(qa).id << endl;
                } else {
                    cout << "EMPTY" << endl;
                }
            } else if (doctor2 == 2) {
                if (!qb.empty()) {
                    cout << find_max(qb).id << endl;
                } else {
                    cout << "EMPTY" << endl;
                }
            } else {
                if (!qc.empty()) {
                    cout << find_max(qc).id << endl;
                } else {
                    cout << "EMPTY" << endl;
                }
            }
        }
    }
    return 0;
}