//
// Created by Geek.Kwok on 2026/10/30.
//
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

// STL 数组 a[1..n] 已升序
void stlBinary(const int a[], int n, int x) {
  int p1 = lower_bound(a + 1, a + n + 1, x) - a; // 第一个大于等于x的下标；都小于x时为n+1
  int p2 = upper_bound(a + 1, a + n + 1, x) - a; // 第一个大于x的下标
  int cntX = p2 - p1; // x出现的次数
  bool found = (p1 <= n && a[p1] == x); // 是否存在x
  (void)cntX; (void)found; // 抑制编译告警
}

// 模板一：找第一个满足 check 的位置（check 前面全 false，后面全 true）
// 要求答案在 [lo, hi] 中（hi一定满足）
bool check(int x); // 按题目自己写
int firstTrue(int lo, int hi) {
  int l = lo, r = hi;
  while (l < r) {
    int mid = l + (r - l) / 2; // 向下取整
    if (check(mid)) r = mid;   // mid满足，答案在左半边（含mid）
    else l = mid + 1;
  }
  return l;
}

// 模板二：找最后一个满足 check 的位置（check 前面全 true，后面全 false）
// 要求答案在 [lo, hi] 中（lo一定满足）
bool check2(int x) { return x * x < 1000; } // 示例：lastTrue(0, 1000) 得到 31
int lastTrue(int lo, int hi) {
  int l = lo, r = hi;
  while (l < r) {
    int mid = l + (r - l + 1) / 2; // 向上取整！否则 l = mid 时会死循环
    if (check2(mid)) l = mid; // mid满足，答案在右半边（含mid）
    else r = mid - 1;
  }
  return l;
}

int main() {
  return 0;
}