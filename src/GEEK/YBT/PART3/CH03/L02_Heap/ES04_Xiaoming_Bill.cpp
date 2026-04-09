//
// Created by Geek.Kwok on 2026/4/9.
//
#include <iostream>
#include <queue>
using namespace std;

struct Bill {
    int no, cnt;
};
struct B_LESS_CMP {
    bool operator()(const Bill& a, const Bill& b) const {
        return a.cnt > b.cnt;
    }
};
struct B_MORE_CMP {
    bool operator()(const Bill& a, const Bill& b) const {
        return a.cnt < b.cnt;
    }
};
priority_queue<Bill, vector<Bill>, B_MORE_CMP> maxHeap;
priority_queue<Bill, vector<Bill>, B_LESS_CMP> minHeap;

int no;
bool flag[1500010];

int main() {
    int n, m, bill;
    ios::sync_with_stdio(false);
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> m;
        for (int j = 1; j <= m; j++) {
            cin >> bill;
            no++;
            maxHeap.push({no, bill});
            minHeap.push({no, bill});
        }
        while (flag[minHeap.top().no]) {
            minHeap.pop();
        }
        while (flag[maxHeap.top().no]) {
            maxHeap.pop();
        }
        cout << minHeap.top().cnt << " " << maxHeap.top().cnt << endl;
        flag[minHeap.top().no] = flag[maxHeap.top().no] = true;
        minHeap.pop(); maxHeap.pop();
    }
    return 0;
}