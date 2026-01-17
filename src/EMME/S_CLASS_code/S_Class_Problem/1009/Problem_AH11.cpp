//
// Created by Emma on 2025/8/1.
//

// wrong code(the most simple method)
// #include<iostream>
// using namespace std;
//
// int a[100010];
//
// int main() {
//     int n, sum = 0;
//     cin >> n;
//     for (int i = 0; i < n; i++) {
//         cin >> a[i];
//         sum += a[i];
//     }
//     int e1, e2, m;
//     cin >> m;
//     for (int i = 1; i <= m; i++) {
//         int ans1 = 0;
//         cin >> e1 >> e2;
//         for (int j = e1 - 1; j % n != e2 - 1; j++) {
//             ans1 += a[j % n];
//         }
//         cout << min(ans1, sum - ans1) << endl;
//     }
//     return 0;
// }

// right code
#include<iostream>
#include<cmath>
using namespace std;

int a[100010], preSum[100010];

int main() {
    int n, sum = 0;
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        sum += a[i];
        preSum[i] = preSum[i - 1] + a[i];
    }
    int e1, e2, m;
    cin >> m;
    for (int i = 1; i <= m; i++) {
        cin >> e1 >> e2;
        int ans1 = abs(preSum[e2 - 1] - preSum[e1 - 1]);
        cout << min(ans1, sum - ans1) << endl;
    }
    return 0;
}
