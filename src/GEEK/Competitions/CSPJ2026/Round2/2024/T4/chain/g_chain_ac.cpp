//
// Created by Geek.Kwok on 2026/10/22.
//
#include <bits/stdc++.h>
using namespace std;

const int MAXN = 100005, MAXV = 200005, MAXR = 100;
const int NONE = -1, MANY = -2;

int a[MAXV], st[MAXN], en[MAXN];          // 所有序列拍扁：人 p 是 a[st[p] .. en[p]]
int prv[MAXV], cur[MAXV], oldPrv[MAXV];   // 第2步：上一轮 / 这一轮 / 上上轮以 c 结尾的人
bool ok[MAXR + 1][MAXV];                  // 第2步：ok[r][c] 恰好 r 轮、以 c 结尾是否可能
int qryR[MAXN], qryC[MAXN];
int curTouched[MAXV], nCur;
int prvTouched[MAXV], nPrv;
int oldTouched[MAXV], nOld;

bool sameWho(int *A, int *ka, int na, int *B, int *kb, int nb) {  // 两个「是谁」表是否完全相同
    if (na != nb) return false;
    for (int i = 0; i < na; i++) if (A[ka[i]] != B[ka[i]]) return false;
    for (int i = 0; i < nb; i++) if (B[kb[i]] != A[kb[i]]) return false;
    return true;
}

int main() {
    // freopen("chain.in", "r", stdin); freopen("chain.out", "w", stdout);
    memset(prv, 0xff, sizeof(prv));        // 第5步：0xff 把 int 填成 -1，也就是 NONE
    memset(cur, 0xff, sizeof(cur));
    memset(oldPrv, 0xff, sizeof(oldPrv));
    int T;
    scanf("%d", &T);
    while (T--) {
        int n, k, q;
        scanf("%d %d %d", &n, &k, &q);
        int tot = 0;
        for (int p = 1; p <= n; p++) {
            int l;
            scanf("%d", &l);
            st[p] = tot;
            for (int j = 0; j < l; j++) scanf("%d", &a[tot++]);
            en[p] = tot;
        }
        int maxR = 0;
        for (int i = 0; i < q; i++) {
            scanf("%d %d", &qryR[i], &qryC[i]);
            if (qryR[i] > maxR) maxR = qryR[i];
        }
        nPrv = nOld = 0;
        for (int r = 1; r <= maxR; r++) {          // 第1、6步：只算到询问里最大的 r
            nCur = 0;
            for (int p = 1; p <= n; p++) {
                int lastStart = -1;                // p 的序列里，最近一个能当开头的下标
                int *s = a + st[p];
                int len = en[p] - st[p];
                for (int j = 0; j < len; j++) {
                    int x = s[j];
                    // 第3、4步：先判断结尾，开头要在 [j-k+1, j-1] 里
                    if (lastStart != -1 && j - lastStart <= k - 1) {
                        if (cur[x] == NONE) { cur[x] = p; curTouched[nCur++] = x; }
                        else if (cur[x] != p) cur[x] = MANY;
                    }
                    // 第3、4步：再判断开头。MANY 是 -2，不等于 p，不必单独写
                    if (r == 1) {
                        if (x == 1) lastStart = j;
                    } else if (prv[x] != NONE && prv[x] != p) {
                        lastStart = j;
                    }
                }
            }
            for (int i = 0; i < nCur; i++) ok[r][curTouched[i]] = true;
            if (nCur == 0) break;                 // 这一轮没人能结尾，后面更不可能
            bool period1 = sameWho(cur, curTouched, nCur, prv, prvTouched, nPrv);
            bool period2 = r >= 2 && sameWho(cur, curTouched, nCur, oldPrv, oldTouched, nOld);
            if (period1 || period2) {             // 表稳定，或两轮一循环
                for (int rr = r + 1; rr <= maxR; rr++) {
                    int *keys = (period1 || (rr - r) % 2 == 0) ? curTouched : prvTouched;
                    int nk = (period1 || (rr - r) % 2 == 0) ? nCur : nPrv;
                    for (int i = 0; i < nk; i++) ok[rr][keys[i]] = true;
                }
                break;
            }
            for (int i = 0; i < nOld; i++) oldPrv[oldTouched[i]] = NONE;
            for (int i = 0; i < nPrv; i++) {
                oldPrv[prvTouched[i]] = prv[prvTouched[i]];
                oldTouched[i] = prvTouched[i];
            }
            nOld = nPrv;
            for (int i = 0; i < nPrv; i++) prv[prvTouched[i]] = NONE;
            for (int i = 0; i < nCur; i++) {      // 第 r 轮变成“上一轮”
                prv[curTouched[i]] = cur[curTouched[i]];
                cur[curTouched[i]] = NONE;
                prvTouched[i] = curTouched[i];
            }
            nPrv = nCur;
        }
        for (int i = 0; i < q; i++) printf("%d\n", ok[qryR[i]][qryC[i]] ? 1 : 0);  // 第7步
        for (int i = 0; i < nCur; i++) cur[curTouched[i]] = NONE;   // 为下一组数据清空
        for (int i = 0; i < nPrv; i++) prv[prvTouched[i]] = NONE;
        for (int i = 0; i < nOld; i++) oldPrv[oldTouched[i]] = NONE;
        memset(ok, 0, sizeof(ok));
    }
    return 0;
}