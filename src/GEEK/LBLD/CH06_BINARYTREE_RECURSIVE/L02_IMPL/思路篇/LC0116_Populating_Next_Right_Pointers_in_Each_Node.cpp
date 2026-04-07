//
// Created by Geek.Kwok on 2026/4/4.
//
#include <iostream>
#include "../../../CH05_BINARYTREE/L02_IMPL/TreeNode.cpp"
using namespace std;

struct Node {
    int val;
    Node *left;
    Node *right;
    Node *next;
};

class Solution {
public:
    // 经典：把一棵二叉树重新抽象成一棵三叉树，三叉树上的每个节点就是原先二叉树的两个相邻节点
    // 主函数
    Node* connect(Node* root) {
        if (root == nullptr) return nullptr;
        // 遍历三叉树，连接相邻节点
        traverse(root->left, root->right);
        return root;
    }

    void traverse(Node* node1, Node* node2) {
        if (node1 == nullptr || node2 == nullptr) return;
        // 前序位置
        // 将传入的两个节点穿起来
        node1->next = node2;

        // 连接相同父节点的两个子节点
        traverse(node1->left, node1->right);
        traverse(node2->left, node2->right);
        // 连接跨越父节点的两个子节点
        traverse(node1->right, node2->left);
    }
};

int main() {

    return 0;
}