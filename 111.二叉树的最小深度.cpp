/*
 * @lc app=leetcode.cn id=111 lang=cpp
 *
 * [111] 二叉树的最小深度
 *
 * https://leetcode-cn.com/problems/minimum-depth-of-binary-tree/description/
 *
 * algorithms
 * Easy (39.34%)
 * Likes:    147
 * Dislikes: 0
 * Total Accepted:    25.4K
 * Total Submissions: 64K
 * Testcase Example:  '[3,9,20,null,null,15,7]'
 *
 * 给定一个二叉树，找出其最小深度。
 * 
 * 最小深度是从根节点到最近叶子节点的最短路径上的节点数量。
 * 
 * 说明: 叶子节点是指没有子节点的节点。
 * 
 * 示例:
 * 
 * 给定二叉树 [3,9,20,null,null,15,7],
 * 
 * ⁠   3
 * ⁠  / \
 * ⁠ 9  20
 * ⁠   /  \
 * ⁠  15   7
 * 
 * 返回它的最小深度  2.
 * 
 */
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    int minDepth(TreeNode* root) {
        return helper(root);
    }
    int helper(TreeNode* root){
        if(nullptr == root) return 0;
        if(root->left == nullptr && root->right == nullptr) return 1;
        if(root->left==nullptr && root->right!=nullptr) return helper(root->right) + 1;
        if(root->left!=nullptr && root->right==nullptr) return helper(root->left) + 1;
        return min(helper(root->left), helper(root->right)) + 1;
    }
    int min(int a, int b){
        return a<b?a:b;
    }
};

