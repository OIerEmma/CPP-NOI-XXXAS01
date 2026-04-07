//
// Created by Geek.Kwok on 2026/4/5.
//
#include <unordered_map>
#include <vector>
#include "../../../CH05_BINARYTREE/L02_IMPL/TreeNode.cpp"
using namespace std;

class Solution {
public:
    // 记录所有子树以及出现的次数
    unordered_map<string, int> subTrees;
    // 记录重复的子树根节点
    vector<TreeNode*> res;

    vector<TreeNode*> findDuplicateSubtrees(TreeNode* root) {
        serialize(root);n
        return res;
    }

    string serialize(TreeNode* root) {
        if (root == nullptr) return "#";

        // 先计算左右子树的序列化结果
        string left = serialize(root->left);
        string right = serialize(root->right);
        string myself = left + "," + right + "," + to_string(root->val);

        int freq = subTrees[myself];
        // 多次重复也只会被加入结果集一次
        if (freq == 1) {
            res.push_back(root);
        }
        // 给子树对应的出现次数加一
        subTrees[myself] = freq + 1;
        return myself;
    }
};