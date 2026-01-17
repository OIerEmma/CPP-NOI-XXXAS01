//
// Created by Emma on 2025/7/30.
//
#include<iostream>
using namespace std;

struct stu{
    int id, age;
    string name, gender;
}a[25];

int main() {
    int n, m;
    cin >> m;
    for (int s = 1; s <= m; s++) {
        cin >> n;
        for (int i = 1; i <= n; i++) {
            cin >> a[i].id >> a[i].name >> a[i].gender >> a[i].age;
        }
        int no_dot;
        cin >> no_dot;
        for (int i = 1; i <= n; i++) {
            if (no_dot == a[i].id) {
                cout << a[i].id << " " << a[i].name << " " << a[i].gender << " " << a[i].age << endl;
            }
        }
    }
    return 0;
}
