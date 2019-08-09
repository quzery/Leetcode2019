/*
 * @lc app=leetcode.cn id=107 lang=cpp
 *
 * [107] 二叉树的层次遍历 II
 *
 * https://leetcode-cn.com/problems/binary-tree-level-order-traversal-ii/description/
 *
 * algorithms
 * Easy (61.54%)
 * Likes:    124
 * Dislikes: 0
 * Total Accepted:    21.3K
 * Total Submissions: 34.5K
 * Testcase Example:  '[3,9,20,null,null,15,7]'
 *
 * 给定一个二叉树，返回其节点值自底向上的层次遍历。 （即按从叶子节点所在层到根节点所在的层，逐层从左向右遍历）
 * 
 * 例如：
 * 给定二叉树 [3,9,20,null,null,15,7],
 * 
 * ⁠   3
 * ⁠  / \
 * ⁠ 9  20
 * ⁠   /  \
 * ⁠  15   7
 * 
 * 
 * 返回其自底向上的层次遍历为：
 * 
 * [
 * ⁠ [15,7],
 * ⁠ [9,20],
 * ⁠ [3]
 * ]
 * 
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
    vector<vector<int>> levelOrderBottom(TreeNode* root) {
        if(nullptr == root) return {};
        vector<vector<int>> res;
        int maxdepth = maxDepth(root);
        for(int i=0;i<maxdepth;i++)
            res.push_back({});
        helper(res, root, 0, maxdepth);
        return res;
    }

    void helper(vector<vector<int>> &V, TreeNode *T, int level, int maxdepth){
        if(nullptr == T) return;
        V[maxdepth-1-level].push_back(T->val);
        helper(V, T->left, level+1, maxdepth);
        helper(V, T->right, level+1, maxdepth);
    }
    int maxDepth(TreeNode *T){
        if(nullptr == T) return 0;
        return max(maxDepth(T->left), maxDepth(T->right)) + 1;
    }
    int max(int a, int b){
        return a>b?a:b;
    }
};

