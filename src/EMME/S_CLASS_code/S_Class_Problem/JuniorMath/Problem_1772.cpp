//
// Created by Emme.Kwok on 2025/9/21.
//
#include<iostream>
using namespace std;

/**
* 3
---
a,b :
------
a=null, b:{};{1},{2},{3};{1,2},{2,3},{1,3};{1,2,3} = C30 * (C30 + C31 + C32 + C33) = 1 * ^32 = 8

a,b :
------
0,0~3 : C30 * (C30 + C31 + C32 + C33) = 1 * 2^3 = 8
1,0~2 : C31 * (C20 + C21 + C22) = 3 * 2^2 = 12
2,0~1 : C32 * (C10 + C11) = 3 * 2^1 = 6
3,0 : C33 * (C00) = 1 * 2^0 = 1

 */

// 计算组合数：C(b/a) : a >= b
int comb(int a, int b) {
    if (b == 0) {
        return 1;
    }
    int res = 1;
    for (int i = 0; i < b; i++) {
        res *= a - i;
    }
    for (int i = b; i > 0; i--) {
        res /= i;
    }
    return res;
}

int main() {
    int n;
    int ans = 0;
    cin >> n;
    for (int i = 0; i <= n; i++) {
        ans += comb(n, i) * (int)pow(2, n - i);
    }
    cout << ans << endl;
    return 0;
}