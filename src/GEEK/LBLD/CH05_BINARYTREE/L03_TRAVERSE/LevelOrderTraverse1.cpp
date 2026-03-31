//
// Created by Geek.Kwok on 2026/3/31.
//
#include <iostream>
#include <queue>

#include "../L02_IMPL/TreeNode.cpp"
using namespace std;

void levelOrderTraverse1(TreeNode* root) {
    if (root == nullptr) return;
    queue<TreeNode*> q;
    q.push(root);
    while (!q.empty()) {
        TreeNode* cur = q.front();
        q.pop();
        // 访问 cur 节点
        cout << cur->val << endl;
        // 把 cur 的左右子节点加入队列
        if (cur->left != nullptr) q.push(cur->left);
        if (cur->right != nullptr) q.push(cur->right);
    }
}

int main() {

    return 0;
}