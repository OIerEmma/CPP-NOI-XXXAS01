//
// Created by Geek.Kwok on 2026/10/27.
//
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

// 中缀表达式用双栈（数栈 + 符号栈），新符号来时先把栈顶优先级 大于等于 它的符号算掉
// `(` 优先级最低；后缀表达式只用一个栈；需要统计额外信息时数栈里放结构体

// 中缀表达式求值：支持非负整数、+、-、*、/、括号（不含负号开头的情况）
stack<ll> numSt;
stack<char> oprSt;
// 优先级判断
int priority(char op) {
  if (op == '+' || op == '-') return 1;
  if (op == '*' || op == '/') return 2;
  return 0; // `(` 最低，不会被弹出计算
}
// 弹出一个符号和两个数，算完压回；注意先弹出的是右操作数
void calcTop() {
  ll b = numSt.top(); numSt.pop();
  ll a = numSt.top(); numSt.pop();
  char op = oprSt.top(); oprSt.pop();
  ll r = 0;
  if (op == '+') r = a + b;
  else if (op == '-') r = a - b;
  else if (op == '*') r = a * b;
  else r = a / b;
  numSt.push(r);
}
// 计算中缀表达式
ll evalInfix(const string& s) {
  for (size_t i = 0; i < s.size(); i++) {
    char c = s[i];
    if (isdigit(c)) {
      ll x = 0;
      while (i < s.size() && isdigit(s[i])) x = x * 10 + (s[i++] - '0');
      i--; // 多读了一位故需回退
      numSt.push(x);
    } else if (c == '(') {
      oprSt.push(c);
    } else if (c == ')') {
      while (oprSt.top() != '(') calcTop();
      oprSt.pop(); // 弹出 '('
    } else if (c == '+' || c == '-' || c == '*' || c == '/') {
      while (!oprSt.empty() && priority(oprSt.top()) >= priority(c)) calcTop(); // 大于等于保证左结合
      oprSt.push(c);
    } else {
      // 其他字符（如空格）忽略
    }
  }
  while (!oprSt.empty()) calcTop();
  return numSt.top();
}
// 计算后缀表达式：tokens 如 {"3", "4", "+", "2", "*"} 表示 (3+4)*2
ll evalPostfix(const vector<string>& tokens) {
  stack<ll> st;
  for (const string& t : tokens) {
    if (isdigit(t[0])) { st.push(stoll(t)); continue; }
    ll b = st.top(); st.pop();
    ll a = st.top(); st.pop();
    if (t == "+") st.push(a + b);
    else if (t == "-") st.push(a - b);
    else if (t == "*") st.push(a * b);
    else st.push(a / b);
  }
  return st.top();
}
// J22T3 逻辑表达式：只含 0、1、&、|、括号，& 优先于 |。
// 求值并统计 & 和 | 各发生了几次“短路”。数栈里需放结构体
struct Val {int v, andCut, orCut; };
stack<Val> valSt;
stack<char> optSt;
int priority2(char op) { return op == '&' ? 2 : (op == '|' ? 1 : 0); }
void calc2() {
  Val b = valSt.top(); valSt.pop();
  Val a = valSt.top(); valSt.pop();
  char c = optSt.top(); optSt.pop();
  if (c == '&') {
    if (a.v == 0) valSt.push({0, a.andCut + 1, a.orCut}); // 0 & _ 短路，右边不再计算
    else valSt.push({b.v, a.andCut + b.andCut, a.orCut + b.orCut});
  } else {
    if (a.v == 1) valSt.push({1, a.andCut, a.orCut + 1}); // 1 | _ 短路
    else valSt.push({b.v, a.andCut + b.andCut, a.orCut + b.orCut});
  }
}
Val evalLogic(const string& s) {
  for (char c : s) {
    if (c == '0' || c == '1') valSt.push({c - '0',0, 0});
    else if (c == '(') optSt.push(c);
    else if (c == ')') { while (optSt.top() != '(') calc2(); optSt.pop(); }
    else { while (!optSt.empty() && priority2(optSt.top()) >= priority2(c)) calc2(); optSt.pop(); }
  }
  while (!optSt.empty()) calc2();
  return valSt.top();
}

int main() {
  // freopen("input.txt", "r", stdin); freopen("output.txt", "w", stdout);
  ios::sync_with_stdio(false); cin.tie(nullptr), cout.tie(nullptr);

  return 0;
}