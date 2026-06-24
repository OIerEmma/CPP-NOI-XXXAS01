//
// Created by Emme.Kwok on 2026/6/24.
//
#include<bits/stdc++.h>
using namespace std;

const int N = 25;
vector<int> anc1(N), anc2(N), f(N);

void findLCAdis(int x, vector<int> &anc) {
    int cnt = 0;
    anc[0] = x;
    for (int i = 2; i * i <= x; i++)
        while (x % i == 0) f[cnt++] = i, x /= i;
    f[cnt++] = x;
    for (int i = 0; i < cnt; i++)
        anc[i + 1] = anc[i] / f[i];
}

int main() {
    int q;
    cin >> q;
    while (q--) {
        int x, y;
        cin >> x >> y;
        findLCAdis(x, anc1);
        findLCAdis(y, anc2);
        int px = 0, py = 0;
        while (anc1[px] != anc2[py]) {
            if (anc1[px] > anc2[py]) px++;
            else                     py++;
        }
        cout << px + py << endl;
    }
    return 0;
}