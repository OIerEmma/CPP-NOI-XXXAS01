//
// Created by Emme.Kwok on 2026/9/30.
//
#include<bits/stdc++.h>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode *insertionSortList(ListNode *head) {
        ListNode *now = head->next, *pre = head;
        while (now != nullptr) {
            ListNode *t = head, *tnow = now;
            while (t != now && t->next->val < now->val) t = t->next;
            if (t == head) {
                pre->next = now->next;
                tnow->next = head;
                head = tnow;
            } else if (t != now) {
                pre->next = tnow->next;
                tnow->next = t->next;
                t->next = tnow;
                pre = tnow;
                now = now->next;
            }
        }
        return head;
    }
};
/*
ListNode* insertionSortList(ListNode* head) {
        ListNode* oldHead = head->next;
        head->next = nullptr;
        while (oldHead != nullptr) {
            // 待插入节点
            ListNode* insertNode = oldHead;
            oldHead = oldHead->next;
            // 插入到 head 链表的合适位置
            // (1)先找到要插入位置的前一个位置 prevNode
            ListNode* findNode = head, *prevNode = nullptr;
            while (findNode != nullptr && findNode->val <= insertNode->val)
                prevNode = findNode, findNode = findNode->next;
            // (2)进行插入
            insertNode->next = findNode;
            if (prevNode != nullptr) prevNode->next = insertNode;
            else head = insertNode;
        }
        return head;
    }
*/