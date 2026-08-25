//
// Created by Geek.Kwok on 2026/6/27.
//
#include<bits/stdc++.h>
using namespace std;

struct TreeNode {
    int value;
    TreeNode *left, *right;
};

int bfsMaxDepth(TreeNode *root) {
    if (!root) return 0;
    queue<TreeNode*> q;
    q.push(root);
    int depth = 0;
    while (!q.empty()) {
        int levelSize = (int)q.size();
        depth++;
        for (int i = 1; i <= levelSize; i++) {
            TreeNode *node = q.front();
            q.pop();
            cout << node->value << " ";
            if (node->left) q.push(node->left);
            if (node->right) q.push(node->right);
        }
    }
    return depth;
}

int main() {
    return 0;
}