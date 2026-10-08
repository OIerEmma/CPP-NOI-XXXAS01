//
// Created by Geek.Kwok on 2026/9/30.
//
#include <bits/stdc++.h>
using namespace std;

/**
 * Definition for singly-linked list.
*/
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    /**
     * head = [4,2,1,3]
     *
     * newhead = []
     *
     * 从 head 里的头，拿出节点，插入到 newhead 中的合适的位置
     */
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
};