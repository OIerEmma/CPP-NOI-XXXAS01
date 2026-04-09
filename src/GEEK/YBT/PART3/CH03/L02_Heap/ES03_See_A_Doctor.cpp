//
// Created by Geek.Kwok on 2026/4/9.
//
#include<iostream>
#include <queue>
using namespace std;

struct Patient {
    string name;
    int priority;
};
struct PCMP {
    bool operator()(const Patient& a, const Patient& b) const {
        return a.priority < b.priority;
    }
};
priority_queue<Patient, vector<Patient>, PCMP> heap;

int main() {
    int n;
    string method;
    ios::sync_with_stdio(false);
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> method;
        if (method == "pop") {
            if (heap.empty()) cout << "none" << endl;
            else {
                cout << heap.top().name << " " << heap.top().priority << endl;
                heap.pop();
            }
        } else {
            string name;
            int priority;
            cin >> name >> priority;
            heap.push({name, priority});
            heap.pop();
        }
    }
    return 0;
}