//
// Created by Geek.Kwok on 2026/5/1.
//

#include "Person.h"

#include <vector>

int k, n, a[n];

bool check(long long mid) {
    long long cnt = 0, p = mid / k;
    if (mid % k != 0) return false;

    vector<long long> m(n);
    for (int i = 0; i < n; i ++) m[i] = a[i];

    for (int i = 0; i < n-1; i++) {
        if (m[i] >= p) cnt++, m[i] -= p;
        else if (m[i] + m[i+1] >= p) cnt++, m[i+1] -= (p-m[i]);
    }

    return cnt >= k;
}

int main () {

    const string TYPE = "P";
    // TYPE = "W";
    Person::TAG = "P";

    auto* p = new Person("guomingxuan", 12);
    cout << p->name << " " << p->age << endl;
    p->TAG = "X";

    auto* p2 = new Person("guopeijia", 10);
    cout << p2->name << " " << p2->age << endl;

    return 0;
}