/*
 * @lc app=leetcode.cn id=118 lang=cpp
 *
 * [118] 杨辉三角
 *
 * https://leetcode-cn.com/problems/pascals-triangle/description/
 *
 * algorithms
 * Easy (63.13%)
 * Likes:    174
 * Dislikes: 0
 * Total Accepted:    32K
 * Total Submissions: 50.5K
 * Testcase Example:  '5'
 *
 * 给定一个非负整数 numRows，生成杨辉三角的前 numRows 行。
 * 
 * 
 * 
 * 在杨辉三角中，每个数是它左上方和右上方的数的和。
 * 
 * 示例:
 * 
 * 输入: 5
 * 输出:
 * [
 * ⁠    [1],
 * ⁠   [1,1],
 * ⁠  [1,2,1],
 * ⁠ [1,3,3,1],
 * ⁠[1,4,6,4,1]
 * ]
 * 
 */
class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        if(numRows == 0) return {};
        vector<vector<int>> res;
        for(int i=0;i<numRows;i++){
            if(i==0) {res.push_back({1});continue;}
            vector<int> vv;
            for(int j=0;j<res[i-1].size()+1;j++){
                if(j==0 || j==res[i-1].size()) {vv.push_back(1);continue;}
                vv.push_back(res[i-1][j-1]+res[i-1][j]);
            }
            res.push_back(vv);
        }
        return res;
    }
};

