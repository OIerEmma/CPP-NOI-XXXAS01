//
// Created by Emma on 2025/7/27.
//
#include<iostream>
using namespace std;

struct stu{
    string id, name, gender;
    int age;
}a[1010];

int main() {
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> a[i].id >> a[i].name >> a[i].gender >> a[i].age;
    }
    int m, idx = -1;
    string input;
    cin >> m;
    for (int i = 1; i <= m; i++) {
        cin >> input;
        idx = -1;
        for (int j = 1; j <= n; j++) {
            if (a[j].id == input) {
                idx = j;
            }
        }
        if (idx == -1) {
            cout << "No Answer!" << endl;
        } else {
            cout << a[idx].id << " " << a[idx].name << " " << a[idx].gender << " " << a[idx].age << endl;
        }
    }
    return 0;
}