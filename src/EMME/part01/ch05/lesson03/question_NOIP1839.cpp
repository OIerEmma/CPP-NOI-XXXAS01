//
// Created by Emma on 2025/2/15.
//
#include<iostream>
using namespace std;

int main() {
    int person, x, y, z, max = 0, s = 0;
    char n, m;
    cin >> person;
    string name[person];
    int money[person];
    memset(money, 0, sizeof(money));
    for (int i = 0; i < person; i++) {
        cin >> name[i] >> x >> y >> n >> m >> z;
        if (x > 80 && z >= 1) {
            money[i] += 8000;
        }
        if (x > 85 && y > 80) {
            money[i] += 4000;
        }
        if (x > 90) {
            money[i] += 2000;
        }
        if (x > 85 && m == 'Y') {
            money[i] += 1000;
        }
        if (y > 80 && n == 'Y') {
            money[i] += 850;
        }
        if (money[i] > max) {
            max = money[i];
        }
        s += money[i];
    }
    for (int i = 0; i < person; i++) {
        if (max == money[i]) {
            cout << name[i] << endl;
            printf("%d\n%d\n", max, s);
            break;
        }
    }
    return 0;
}
