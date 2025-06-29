//
// Created by Emma on 2025/4/13.
//
#include<iostream>
using namespace std;

int year[100], old[100], not_old[100];
string old_id[100], not_old_id[100], id[100];

int main() {
    int n, cnt = 0, cnt2 = 0;
    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
        cin >> id[i] >> year[i];
        if (year[i] >= 60) {
            old[cnt] = year[i];
            old_id[cnt++] = id[i];
        } else {
            not_old[cnt2] = year[i];
            not_old_id[cnt2++] = id[i];
        }
    }

    for (int i = 0; i < cnt; i++) {
        for (int j = 0; j < cnt - i; j++) {
            if (old[j] < old[j + 1]) {
                swap(old[j], old[j + 1]);
                swap(old_id[j], old_id[j + 1]);
            }
        }
    }

    for (int i = 0; i < cnt; i++) {
        cout << old_id[i] << endl;
    }
    for (int i = 0; i < cnt2; i++) {
        cout << not_old_id[i] << endl;
    }
    return 0;
}