//
// Created by Geek.Kwok on 2026/3/31.
//
#include <iostream>
#include <queue>

#include "../L02_IMPL/TreeNode.cpp"
using namespace std;

void levelOrderTraverse2(TreeNode* root) {
    if (root == nullptr) return;
    queue<TreeNode*> q;
    q.push(root);
    // 记录当前遍历到的层数（根节点视为第1层）
    int depth = 1;
    while (!q.empty()) {
        const int sz = q.size();
        for (int i = 0; i < sz; i++) {
            const TreeNode* cur = q.front();
            q.pop();
            // 访问 cur 节点同时知道它所在的层数
            cout << "depth = " << depth << ", val = " << cur->val << endl;
            // 把 cur 的左右子节点加入队列
            if (cur->left != nullptr) q.push(cur->left);
            if (cur->right != nullptr) q.push(cur->right);
        }
        depth++;
    }
}

int main() {

    return 0;
}