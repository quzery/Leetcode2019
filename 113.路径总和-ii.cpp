/*
 * @lc app=leetcode.cn id=113 lang=cpp
 *
 * [113] 路径总和 II
 *
 * https://leetcode-cn.com/problems/path-sum-ii/description/
 *
 * algorithms
 * Medium (56.53%)
 * Likes:    115
 * Dislikes: 0
 * Total Accepted:    13.4K
 * Total Submissions: 23.7K
 * Testcase Example:  '[5,4,8,11,null,13,4,7,2,null,null,5,1]\n22'
 *
 * 给定一个二叉树和一个目标和，找到所有从根节点到叶子节点路径总和等于给定目标和的路径。
 * 
 * 说明: 叶子节点是指没有子节点的节点。
 * 
 * 示例:
 * 给定如下二叉树，以及目标和 sum = 22，
 * 
 * ⁠             5
 * ⁠            / \
 * ⁠           4   8
 * ⁠          /   / \
 * ⁠         11  13  4
 * ⁠        /  \    / \
 * ⁠       7    2  5   1
 * 
 * 
 * 返回:
 * 
 * [
 * ⁠  [5,4,11,2],
 * ⁠  [5,8,4,5]
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
    vector<vector<int>> pathSum(TreeNode* root, int sum) {
        vector<vector<int>> res;
        vector<int> vv;
        helper(res, vv, root, sum);
        return res;
    }
    void helper(vector<vector<int>>& res, vector<int>& vv, TreeNode* root, int sum){
        if(root == nullptr) return ;
        vv.push_back(root->val);
        sum -= root->val;
        if(root->left==nullptr && root->right==nullptr) {
            if(sum==0) res.push_back(vv);
            vv.pop_back();
            return;
        }
        helper(res, vv, root->left, sum);
        helper(res, vv, root->right, sum);
        vv.pop_back();
        return;
    }
};

