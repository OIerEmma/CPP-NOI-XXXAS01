//
// Created by Emme.Kwok on 2026/5/30.
//
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

struct node{
    int w, h;
};

bool cmp2(node x, node y) {
    return x.w == y.w ? x.h < y.h : x.w < y.w;
}

bool cmp(node x, node y) {
    return x.w < y.w && x.h < y.h;
}

int main() {
    int n;
    cin >> n;
    vector<node> envelope(n);
    for (int i = 0; i < n; i++) cin >> envelope[i].w;
    for (int i = 0; i < n; i++) cin >> envelope[i].h;
    sort(envelope.begin(), envelope.end(), cmp2);
    vector<node> tails;
    for (int i = 0; i < n; i++) {
        auto x = lower_bound(tails.begin(), tails.end(), envelope[i], cmp);
        cout << "(" << envelope[i].w << "," << envelope[i].h << ")" << endl;
        if (x == tails.end()) {
            cout << "--(" << envelope[i].w << "," << envelope[i].h << ")" << endl;
            tails.push_back(envelope[i]);
        }
        else *x = envelope[i];
    }
    cout << tails.size() << endl;
    return 0;
}