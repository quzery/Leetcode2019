/*
 * @lc app=leetcode.cn id=67 lang=cpp
 *
 * [67] 二进制求和
 *
 * https://leetcode-cn.com/problems/add-binary/description/
 *
 * algorithms
 * Easy (49.41%)
 * Likes:    227
 * Dislikes: 0
 * Total Accepted:    33.6K
 * Total Submissions: 67.4K
 * Testcase Example:  '"11"\n"1"'
 *
 * 给定两个二进制字符串，返回他们的和（用二进制表示）。
 * 
 * 输入为非空字符串且只包含数字 1 和 0。
 * 
 * 示例 1:
 * 
 * 输入: a = "11", b = "1"
 * 输出: "100"
 * 
 * 示例 2:
 * 
 * 输入: a = "1010", b = "1011"
 * 输出: "10101"
 * 
 */
class Solution {
public:
    string addBinary(string a, string b) {
        map<char, int> atoi = {{'0',0},{'1',1}};
        map<int, char> itoa = {{0,'0'},{1,'1'}};
        int size_a = a.size();
        int size_b = b.size();
        while(size_a < size_b){
            a = '0' + a;
            size_a++;
        }
        while(size_a > size_b){
            b = '0' + b;
            size_b++;
        }
        for(int i=b.size()-1;i>0;i--){
            a[i] = a[i] - '0' + b[i];
            if(a[i]>='2') {
                a[i] -= 2;
                a[i-1]++;
            }
        }
        a[0] = a[0] - '0' + b[0];
        if(a[0]>='2'){
            a[0] -= 2;
            a = '1' + a;
        }
        return a;
    }
};

