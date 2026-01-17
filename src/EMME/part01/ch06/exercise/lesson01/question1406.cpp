//
// Created by Emma on 2025/2/23.
//
#include<string>
#include<cstdio>
using namespace std;
int n;
char e, a[150], b[150], s[300][300];

void work(char *w) {
    string ww = w, vv = a;
    if (ww == vv) {
        printf("%s ", b);
    } else {
        printf("%s ", w);
    }
}

int main() {
    while (scanf("%s%c", s[++n], &e)) {
        if (e != ' ') {
            break;
        }
    }
    scanf("%s%s", a, b);
    for (int i = 1; i <= n; ++i) {
        work(s[i]);
    }
    return 0;
}
