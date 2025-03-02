//
// Created by Emma on 2025/2/22.
//
#include <iostream>
#include <string>
using namespace std;

int main() {
    double s;
    bool flag;
    int n, cnt = 0;
    string name;
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) {
        cin >> name >> s >> flag;
        if (s >= 37.5 && flag) {
            cout << name << endl;
            cnt++;
        }
    }
    printf("%d", cnt);
    return 0;
}
