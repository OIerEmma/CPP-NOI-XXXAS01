#include<iostream>
using namespace std;

char r[60][60];

int main() {
    int n;
    cin >> n;
    int center = (2 * n - 1) / 2;
    r[center][center] = 'A'; // n圈数
    for (int i = 1; i < n; i++) {
        for (int j = center - i; j <= center + i; j++) {
            // 东面
            r[j][center + i] = char('A' + i);
            // 南面
            r[center + i][j] = char('A' + i);
            // 西面
            r[j][center - i] = char('A' + i);
            // 北面
            r[center - i][j] = char('A' + i);
        }
    }
    for (int i = 0; i < 2 * n - 1; i++) {
        for (int j = 0; j < 2 * n - 1; j++) {
            cout << r[i][j];
        }
        cout << endl;
    }
    return 0;
}
