//
// Created by Geek.Kwok on 2026/6/27.
//
#include<bits/stdc++.h>
using namespace std;

struct TreeNode {
    int value;
    TreeNode *left, *right;
};

void bfsByLevel(TreeNode *root) {
    if (!root) return;
    queue<TreeNode*> q;
    q.push(root);
    int level = 0;
    while (!q.empty()) {
        int levelSize = (int)q.size();
        level++;
        for (int i = 1; i <= levelSize; i++) {
            TreeNode *node = q.front();
            q.pop();
            cout << node->value << " ";
            if (node->left) q.push(node->left);
            if (node->right) q.push(node->right);
        }
    }
}

int main() {
    return 0;
}