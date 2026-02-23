//
// Created by Emme.Kwok on 2026/2/4.
//
#include<iostream>
using namespace std;

const int N = 10005;
int h[N], n;

void up(int k) {
    while (k > 1) {
        int i = k / 2;
        if (h[k] < h[i]) {
            swap(h[k], h[i]);
            k = i;
        } else {
            break;
        }
    }
}

void down(int k) {
    while(k + k <= n) {
        int i = k + k;
        if (i + 1 <= n && h[i + 1] < h[i]) {
            i++;
        }
        if (h[i] < h[k]) {
            swap(h[i], h[k]);
            k = i;
        } else {
            break;
        }
    }
}

void add(int x) {
    n++;
    h[n] = x;
    up(n);
}

void del(int pos) {
    swap(h[pos], h[n]);
    n--;
    up(pos);
    down(pos);
}

int main() {
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> h[i];
    }
    return 0;
}