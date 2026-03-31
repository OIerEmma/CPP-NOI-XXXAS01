//
// Created by Geek.Kwok on 2026/3/31.
//
#include <iostream>
#include <queue>

#include "../L02_IMPL/TreeNode.cpp"
using namespace std;

class State {
public:
    TreeNode* node;
    int depth;

    State(TreeNode* node, int depth) : node(node), depth(depth) {}
};

void levelOrderTraverse3(TreeNode* root) {
    if (root == nullptr) return;
    queue<State> q;
    // 根节点的路径权重和是1
    q.push(State(root, 1));

    while (!q.empty()) {
        const State cur = q.front();
        q.pop();
        // 访问 cur 节点同时知道它所在的层数
        cout << "depth = " << cur.depth << ", val = " << cur.node->val << endl;
        // 把 cur 的左右子节点加入队列
        if (cur.node->left != nullptr) q.push(State(cur.node->left, cur.depth + 1));
        if (cur.node->right != nullptr) q.push(State(cur.node->right, cur.depth + 1));
    }
}

int main() {

    return 0;
}