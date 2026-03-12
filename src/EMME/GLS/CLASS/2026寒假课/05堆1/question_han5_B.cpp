//
// Created by Emme.Kwok on 2026/2/4.
//
#include<iostream>
#include<cstdio>
using namespace std;

const int N = 1000005;
int h[N], n, len;
bool flag[N];

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
    while(k + k <= len) {
        int i = k + k;
        if (i + 1 <= len && h[i + 1] < h[i]){
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
    len++;
    h[len] = x;
    up(len);
}

void del(int pos) {
    swap(h[pos], h[len]);
    len--;
    up(pos);
    down(pos);
}

int main() {
    char op;
    int x;
    cin >> n;
    getchar();
    for (int i = 1; i <= n; i++) {
        scanf("%c", &op);
        if (op == 'a') {
            scanf("%d", &x);
            add(x);
        } else {
            printf("%d\n", h[1]);
            del(1);
        }
        getchar();
    }
    return 0;
}