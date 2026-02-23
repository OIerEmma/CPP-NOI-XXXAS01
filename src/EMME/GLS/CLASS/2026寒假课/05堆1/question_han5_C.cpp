//
// Created by Emme.Kwok on 2026/2/4.
//
#include<iostream>
#include<cstdio>
using namespace std;

const int maxn = 1000005;
struct node {
    int xn, yv;
} h[maxn];
int n, len;
bool flag[maxn];

void up(int k) {
    while (k > 1) {
        int i = k / 2;
        if (h[k].xn < h[i].xn) {
            swap(h[i].xn, h[k].xn);
            swap(h[i].yv, h[k].yv);
            k = i;
        } else {
            break;
        }
    }
}

void down(int k) {
    while (k + k <= len) {
        int i = k + k;
        if (i + 1 <= len && h[i + 1].xn < h[i].xn){
            i++;
        }
        if (h[i].xn < h[k].xn) {
            swap(h[i].xn, h[k].xn);
            swap(h[i].yv, h[k].yv);
            k = i;
        } else {
            break;
        }
    }
}

void add(int x) {
    len++;
    h[len].xn = x;
    up(len);
}

void del(int pos) {
    swap(h[pos].xn, h[len].xn);
    swap(h[pos].yv, h[len].yv);
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
            printf("%d %d\n", h[1].xn, h[1].yv);
            del(1);
        }
        getchar();
    }
    return 0;
}