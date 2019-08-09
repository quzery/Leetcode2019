/*
 * @lc app=leetcode.cn id=101 lang=cpp
 *
 * [101] 对称二叉树
 *
 * https://leetcode-cn.com/problems/symmetric-tree/description/
 *
 * algorithms
 * Easy (47.39%)
 * Likes:    402
 * Dislikes: 0
 * Total Accepted:    46K
 * Total Submissions: 96.1K
 * Testcase Example:  '[1,2,2,3,4,4,3]'
 *
 * 给定一个二叉树，检查它是否是镜像对称的。
 * 
 * 例如，二叉树 [1,2,2,3,4,4,3] 是对称的。
 * 
 * ⁠   1
 * ⁠  / \
 * ⁠ 2   2
 * ⁠/ \ / \
 * 3  4 4  3
 * 
 * 
 * 但是下面这个 [1,2,2,null,3,null,3] 则不是镜像对称的:
 * 
 * ⁠   1
 * ⁠  / \
 * ⁠ 2   2
 * ⁠  \   \
 * ⁠  3    3
 * 
 * 
 * 说明:
 * 
 * 如果你可以运用递归和迭代两种方法解决这个问题，会很加分。
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
    bool isSymmetric(TreeNode* root) {
        if(nullptr == root) return true;
        return isMirro(root->left, root->right);

        // if(nullptr == root) return true;
        // if(nullptr == root->left && nullptr == root->right) return true;
        // if(nullptr == root->left || nullptr == root->right) return false;
        // if(root->left->val != root->right->val) return false;
        // //return isSymmetric(root->left) && isSymmetric(root->right);
        // return isSame(root->left->left, root->right->right) && 
        //     isSame(root->left->right, root->right->left);
    }
    bool isMirro(TreeNode* p, TreeNode* q){
        if(nullptr == p && nullptr == q) return true;
        if(nullptr == p || nullptr == q) return false;
        if(p->val != q->val) return false;
        return isMirro(p->left, q->right) && isMirro(p->right, q->left);
    }
};

