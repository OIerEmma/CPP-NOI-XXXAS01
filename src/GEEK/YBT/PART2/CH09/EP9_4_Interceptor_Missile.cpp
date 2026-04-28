//
// Created by Geek.Kwok on 2026/4/27.
//
#include <iostream>
using namespace std;

int a[1005], b[1005], h[1005], m, n;

int main() {
    // freopen("in.txt", "r", stdin);
    // freopen("out.txt", "w", stdout);

    int i = 1;
    while (cin >> a[i]) {
        int maxx = 0;
        for (int j = 1; j <= i - 1; j++) if (a[j] >= a[i] && b[j] > maxx) maxx = b[j];
        b[i] = maxx + 1;
        if (b[i] > m) m = b[i];

        int x = 0;
        for (int k = 1; k <= n; k++)
            if (h[k] >= a[i]) {
                if (x == 0) x = k;
                else if (h[k] < h[x]) x = k;
            }

        if (x == 0) n++, x = n;
        h[x] = a[i++];
    }

    cout << m << endl << n << endl;
}