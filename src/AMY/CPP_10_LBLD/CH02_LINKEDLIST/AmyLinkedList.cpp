//
// Created by Amy on 2026/3/31.
//
#include<iostream>
#include<vector>
using namespace std;

template<typename E>

class ListNode {
public:
    E val;
    ListNode* next;
    ListNode* prev;
    explicit ListNode(E x) : val(x), next(nullptr), prev(nullptr) {}
    explicit ListNode(E element, ListNode* prev, ListNode* next) {
        this->val = element;
        this->next = next;
        this->prev = prev;
    }

    //输入一个数组，转换为一条单链表
    ListNode* createLinkedList(vector<int> arr) {
        if(arr.empty()) {
            return nullptr;
        }
        ListNode* head = new ListNode(arr[0]);
        ListNode* cur = head;
        for(int i = 1; i < arr.size(); i++) {
            cur->next = new ListNode(arr[i]);
            cur = cur->next;
        }
        return head;
    }
};
