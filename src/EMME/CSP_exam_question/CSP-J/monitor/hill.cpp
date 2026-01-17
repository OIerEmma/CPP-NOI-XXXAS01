//
// Created by Emma on 2025/8/8.
//
#include<iostream>
#include<algorithm>
using namespace std;

string name[1010];
int a[1010], r[1010];

int main() {
    int n;
    cin >> n;
    getchar();
    for (int i = 1, j; i <= n; i++) {
        string line;
        getline(cin, line);
        for (j = 0; j < line.size(); j++) {
            if (line[j] >= 'A' && line[j] <= 'Z' || line[j] >= 'a' && line[j] <= 'z' || line[j] == ' ') {
                name[i] += line[j];
            } else {
                break;
            }
        }
        for (; j < line.size(); j++) {
            a[i] = a[i] * 10 + (line[j] - '0');
        }
        r[i] = a[i];
    }
    sort(a + 1, a + n + 1, greater<int>());
    for (int i = 1; i <= n; i++) {
        if (a[2] == r[i]) {
            cout << name[i] << endl;
            break;
        }
    }
    return 0;
}
