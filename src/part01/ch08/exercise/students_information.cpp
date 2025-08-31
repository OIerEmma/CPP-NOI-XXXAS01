//
// Created by Emma on 2025/8/5.
//
#include<iostream>
using namespace std;

struct node {
    string id, name, sex, address;
    int age, score;
    node *next, *prev;
};

int main() {
    string iid, iname, isex, iaddress;
    int iage, iscore;
    node *head = new node, *p, *r = head; // r为尾指针
    // 构建双链表
    while (cin >> iid && iid != "end") {
        cin >> iname >> isex >> iage >> iscore >> iaddress;
        p = new node;
        p->id = iid;
        p->name = iname;
        p->sex = isex;
        p->age = iage;
        p->score = iscore;
        p->address = iaddress;
        p->next = nullptr;
        r->next = p;
        p->prev = r;
        r = p;
    }
    // 反向输出
    while (r != head) {
        cout << r->id << " " << r->name << " " << r->sex << " " << r->age << " " << r->score << " " << r->address << endl;
        r = r->prev;
    }
    return 0;
}
/*
00630018 zhouyan m 20 10 28#4600
0063001 zhouyn f 21 100 28#460000
0063008 zhoyan f 20 1000 28#460000
0063018 zhouan m 21 10000 28#4600000
00613018 zhuyan m 20 100 28#4600
00160018 zouyan f 21 10 28#4600
end
*/