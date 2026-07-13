//
// Created by Emme.Kwok on 2026/7/11.
//
#include<bits/stdc++.h>
using namespace std;
typedef unsigned long long ull;

// ---（一）素数的判断 ---
// 朴素方法，时间复杂度：O(√n)
bool isprime(int n) {
    if (n <= 1) return false;
    for (int i = 0; i < n; i++)
        if (n % i == 0) return false;
    return true;
}
/*
当有些时候数据特别大，导致O(√n)的时间复杂度会超时，就要用以下方法：Miller-Rabin素数判定
两个基本定理：
1.费马小定理：当p为素数，且a,p互质，有a^(p - 1) ≡ 1 mod p（反过来不一定成立）
2.二次探测：如果p是一个素数，0 < x < p，则方程 x ^ 2 ≡ 1 mod p的解为x = 1 或 p - 1
*/
inline long long pow_mod(long long a, long long b, long long p) {
    long long ans = 1;
    while (b) {
        if (b & 1) ans = ans * a % p;
        a = a * a % p;
        b >>= 1;
    }
    return ans;
}

ull mul_mod(ull a, ull b, ull mod) {
    return (ull)((__int128)a * b % mod);
}

const int test_time = 10;
// 迭代算法
bool millerRabin(long long n) {
    if (n <= 1 || n % 2 == 0) return false;
    long long a = n - 1, b = 0;
    while (a % 2 == 0) a /= 2, b++;
    for (int i = 1, j; i <= test_time; i++) {
        long long x = rand() % (n - 2) + 2, v = pow_mod(x, a, n);
        if (v == 1) continue;
        for (j = 0; j < b; j++) {
            if (v == n - 1) break;
            v = v * v % n;
        }
        if (j >= b) return false;
    }
    return true;
}

// Miller-Rabin 单次检验
bool isPrime(ull n, ull a) {
    if (n < 2 || n % 2 == 0) return n == 2;

    ull d = n - 1, r = 0;
    while (d % 2 == 0) { // 分解 n-1 = d * 2^r
        d >>= 1;
        r++;
    }

    ull x = pow_mod(a, d, n);
    if (x == 1 || x == n - 1) return true;

    for (ull i = 0; i < r - 1; i++) {
        x = mul_mod(x, x, n);
        if (x == n - 1) return true;
        // 如果 x == 1 且之前没出现 n-1，说明存在非平凡平方根，必为合数
        if (x == 1) return false;
    }
    return false; // 最终 x 不为 1，合数
}

// 确定性判断 64 位整数
bool millerRabin(ull n) {
    if (n < 2) return false;
    // 小质数特判，加速
    for (ull p : {2, 3, 5, 7, 11, 13, 17, 19, 23, 29}) {
        if (n % p == 0) return n == p;
    }

    // 针对 64 位确定性的基底（也可用前 12 个质数 2~37）
    ull bases[] = {2, 3, 5, 7, 11, 13, 17};
    for (ull a : bases) {
        if (a >= n) continue; // 基底不能大于等于 n
        if (!isPrime(n, a)) return false;
    }
    return true;
}

// ---（二）素数的筛选 ---
// 埃氏（埃拉托斯特）筛法/Eratosthenes
const int N = 1e5 + 5;
bool vis[N]; // 是否为素数，这里设置的是false为素数

void primesAi(int n) {
    vis[1] = true; // 1不是素数，标记一下
    for (int i = 2; i <= n; i++) {
        if (vis[i]) continue; // i不是素数
        cout << i << endl;
        for (int j = i; j <= n / i; j++)
            vis[i * j] = true; // i的倍数都看做为合数，上限数为n，j最大n / i，因为i * n / i = n
    }
}

// 线性筛法（欧拉筛）
int v[N], prime[N]; // v保存最小素因子，prime保存所有素数
void primesOula(int n) {
    int m = 0;
    for (int i = 2; i <= n; i++) {
        if (!v[i]) { // i为素数
            v[i] = i; // 素数i的最小素因子是其本身
            prime[m++] = i;
        }
        for (int j = 1; j <= m; j++) { // 给当前的i乘一个素因子
            if (prime[j] > v[i] || prime[j] > n / i) break; // i 比 prime[i] 有更小素因子或者超出n的范围
            v[i * prime[j]] = prime[j]; // prime[j]是合数i * prime[j]的最小素因子
        }
    }
    for (int i = 1; i <= m; i++) cout << prime[i] << endl;
}

// ---（四）质因数分解 ---
void primeFactorSpliting(int n) {
    int i = 2;
    cout << n << "=";
    do {
        while (n % i == 0) {
            cout << i;
            n = n / i;
            if (n != 1) cout << '*';
        }
        i++;
    } while (n != 1); // n直到除尽才结束
}

// ---（五）约数的判定 ---
int f[N];
void judgeFactor(int n) {
    int m = 0;
    for (int i = 1; i * i <= n; i++) {
        if (n % i == 0) {
            f[++m] = i;
            if (i != n / i) // i 不与另一个预想的因数 n / i 重复
                f[++m] = n / i; // 因为 i 为 n 的因数，n / i 也一定是n的因数
        }
    }
    sort(f + 1, f + m + 1);
    for (int i = 1; i <= m; i++) cout << f[i] << " ";
}

// --- （六）最大公约数与最小公倍数
// 递归实现：更相损减法
int gcd1(int a, int b) {
    if (a == b) return a;
    if (a < b) swap(a, b);
    return gcd1(b, a - b);
}

// 迭代实现：更相损减法
int gcd2(int a, int b) {
    while (a != b) {
        if (a > b) a -= b;
        else b -= a;
    }
    return a;
}

// 递归实现：辗转相除法
int gcd3(int a, int b) {
    if (b == 0) return a;
    return gcd3(b, a % b);
}

int main() {
    return 0;
}