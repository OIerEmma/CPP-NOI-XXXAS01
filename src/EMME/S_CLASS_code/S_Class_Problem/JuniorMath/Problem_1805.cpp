//
// Created by Emme.Kwok on 2025/9/20.
//
//
// Created by Emme.Kwok on 2025/9/20.
//
#include<iostream>
using namespace std;

struct stu {
    string n;
    int s;
} a[55];

int main() {
    for (int i = 1; i <= 50; i++) {
        cin >> a[i].n >> a[i].s;
    }
    for (int i = 1; i <= 50; i++) {
        if (a[i].s >= 80) {
            cout << a[i].n << " " << a[i].s << endl;
        }
    }
    return 0;
}
