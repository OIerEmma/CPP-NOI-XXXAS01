//
// Created by Emme.Kwok on 2026/3/31.
//
#include<iostream>
#include<vector>
using namespace std;

template<typename E>

class ListNode{
public:
    E val;
    ListNode* next, prev;
    ListNode(E x) : val(x), next(nullptr) {}
    ListNode(ListNode* prev, E element, ListNode* next) {
        this->val = element;
        this->prev = prev;
        this->next = next;
    }

    // 输入一个数组，转换为一条单链表
    ListNode* createLinkedList(vector<int> arr) {
        if (arr.empty()) {
            return nullptr;
        }
        ListNode* head = new ListNode(arr[0]);
        ListNode* cur = head;
        for (int i = 0; i < arr.size(); i++) {
            cur->next = new ListNode(arr[i]);
            cur = cur->next;
        }
        return head;
    }
};

int main() {

    return 0;
}