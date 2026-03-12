//
// Created by Emme.Kwok on 2026/2/26.
//
#include<iostream>
using namespace std;

int a[100005], p[100005], ex[100005][25];
int n, cur = 0;

// 质数判断
bool isprime(int n) {
    if (n < 2) {
        return false;
    }
    for (int i = 2; i * i <= n; i++) {
        if (n % i == 0) {
            return false;
        }
    }
    return true;
}

// 质因数分解
void fj(int x) {
    for (int i = 2; i * i <= x; i++) {
        if (x % i == 0) {
            int cnt = 0;
            while (x % i == 0) {
                x /= i;
                cnt++;
            }
            ex[i][cnt]++;
        }
    }
    if (x != 1) {
        ex[x][1]++;
    }
}

int main() {
    // 输入
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        fj(a[i]);
    }
    // 判断质数预处理
    for (int i = 2; i <= 1e5; i++) {
        if (isprime(i)) {
            p[++cur] = i;
        }
    }
    // 找出答案
    long long ans = 0;
    for (int i = 1; i <= cur; i++) {
        // 枚举质因数
        int sum = 0;
        for (int j = 1; j <= 20; j++) {
            sum += ex[p[i]][j];
        }
        if (sum == 0) {
            continue;
        }
        ex[p[i]][0] = n - sum;
        // 计算序列中位数
        int mid = 0;
        sum = 0;
        for (int j = 0; j <= 20; j++) {
            sum += ex[p[i]][j];
            if (sum * 2 >= n) {
                mid = j;
                break;
            }
        }
        for (int j = 0; j <= 20; j++) {
            ans += 1ll * ex[p[i]][j] * abs(j - mid);
        }
    }
    // 输出
    cout << ans << endl;
    return 0;
}