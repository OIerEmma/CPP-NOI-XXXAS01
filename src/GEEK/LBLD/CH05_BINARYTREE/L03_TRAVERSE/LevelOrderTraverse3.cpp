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

class NaryState {
public:
    NaryTreeNode* node;
    int depth;

    NaryState(NaryTreeNode* node, int depth) : node(node), depth(depth) {}
};

// 二叉树的层序遍历（L03_BFS）写法三：适配不同权重边的写法
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

// 多叉树的层序遍历（L03_BFS）写法三：适配不同权重边的写法
void naryLevelOrderTraverse3(NaryTreeNode* root) {
    if (root == nullptr) return;
    queue<NaryState> q;
    // 记录当前遍历到的层数（根节点视为第1层）
    q.push(NaryState(root, 1));

    while (!q.empty()) {
        const NaryState state = q.front();
        q.pop();
        NaryTreeNode* cur = state.node;
        int depth = state.depth;
        // 访问 cur 节点同时知道它所在的层数
        cout << "depth = " << depth << ", val = " << cur->val << endl;
        // 把 cur 的所有子节点加入队列
        for (NaryTreeNode* child: cur->children) {
            q.push(NaryState(child, depth + 1));
        }
    }
}

int main() {

    return 0;
}