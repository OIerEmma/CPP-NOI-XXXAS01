//
// Created by Geek.Kwok on 3/25/26.
//
#include <bits/stdc++.h>
#include <vector>
using namespace std;

class DoublyListNode {
public:
  int val;
  DoublyListNode *next, *prev;
  DoublyListNode(int x) : val(x), next(NULL), prev(NULL) {}
};

DoublyListNode* createDoublyLinkedList(const vector<int>& arr) {
  if (arr.empty()) return nullptr;
  DoublyListNode* head = new DoublyListNode(arr[0]);
  DoublyListNode* cur = head;
  // for 循环迭代创建双链表
  for (int i = 1; i < arr.size(); i++) {
    DoublyListNode* newNode = new DoublyListNode(arr[i]);
    cur->next = newNode;
    newNode->prev = cur;
    cur = cur->next;
  }
  return head;
}