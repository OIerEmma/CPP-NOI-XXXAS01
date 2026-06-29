//
// Created by Geek.Kwok on 2026/6/27.
//
#include<bits/stdc++.h>
using namespace std;

struct TreeNode {
    int value;
    TreeNode *left, *right;
};

TreeNode* bfsSearch(TreeNode *root, int target) {
    if (!root) return nullptr;
    queue<TreeNode*> q;
    q.push(root);
    while (!q.empty()) {
        TreeNode* node = q.front();
        q.pop();
        if (node->value == target) return node;
        if (node->left) q.push(node->left);
        if (node->right) q.push(node->right);
    }
    return nullptr;
}

int main() {
    return 0;
}