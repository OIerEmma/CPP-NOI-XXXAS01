// //
// // Created by Emma on 2025/2/2.
// //
// // question3
// #include<iostream>
// #include<cstring>
// using namespace std;
//
// double a[1000001];
// int b[1000001];
//
// void moveAndJudge(int n) {
//     // 先判断相邻元素是否处于一个特殊交叉情况 若是则不move只切换方向 若否则进行move
//     bool moved = false;
//     for (int i = 1; i < n; i++) {
//         moved = true;
//         // 特殊交叉
//         // x ---a[i]小----a[i+1]大--->
//         // x ---b[i]→ ----b[i+1]← --->
//         // x ---a[i]大----a[i+1]小--->
//         // x ---b[i]← ----b[i+1]→ --->
//         if ((a[i] + 1 == a[i + 1] && b[i] == 1 && b[i + 1] == 0)
//             || (a[i] - 1 == a[i + 1] && b[i] == 0 && b[i + 1] == 1)) {
//             swap(b[i], b[i + 1]);
//             i++;
//             moved = false;
//             } else {
//                 // 第i个元素move
//                 if (b[i] == 0) {
//                     a[i] -= 1;
//                 } else {
//                     a[i] += 1;
//                 }
//             }
//     }
//     if (moved) {
//         // 最后1个元素move
//         if (b[n] == 0) {
//             a[n] -= 1;
//         } else {
//             a[n] += 1;
//         }
//     }
// }
//
// int main() {
//     int t = 0, n, L;
//     memset(a, 0.0, sizeof(a));
//     memset(b, 0, sizeof(b));
//     scanf("%d %d", &n, &L);
//     for(int i = 1; i <= n; i++) {
//         scanf("%lf %d", &a[i], &b[i]);
//     }
//     while (true) {
//         // 1. 所有蚂蚁先移动 1 个单位
//         // 2. 判断相邻蚂蚁的位置是否重叠，若是则切换双方的方向
//         moveAndJudge(n);
//         // 5. t ++
//         t ++;
//         // 6. 判断所有蚂蚁是否都已离开木棍，若是则 break
//         bool hasAnt = false;
//         for (int i = 1; i <= n; i++) {
//             if (a[i] > 0 && a[i] < L) {
//                 hasAnt = true;
//                 break;
//             }
//         }
//         if (!hasAnt) {
//             break;
//         }
//     }
//     printf("%d\n", t);
//     return 0;
// }

#include<iostream>
#include<stdio.h>
#include<algorithm>

using namespace std;

int anti[1000003];

int main() {
    int cas;
    cin >> cas;
    while (cas--) {
        int L, n;
        cin >> L >> n;
        for (int i = 0; i < n; i++) {
            scanf("%d", &anti[i]);
        }
        int t_max = 0;
        for (int i = 0; i < n; i++) {
            t_max = max(t_max, max(anti[i], L - anti[i]));
        }
        cout << t_max << endl;
    }
    return 0;
}
