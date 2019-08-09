/*
 * @lc app=leetcode.cn id=38 lang=cpp
 *
 * [38] 报数
 *
 * https://leetcode-cn.com/problems/count-and-say/description/
 *
 * algorithms
 * Easy (51.18%)
 * Likes:    277
 * Dislikes: 0
 * Total Accepted:    41K
 * Total Submissions: 79.4K
 * Testcase Example:  '1'
 *
 * 报数序列是一个整数序列，按照其中的整数的顺序进行报数，得到下一个数。其前五项如下：
 * 
 * 1.     1
 * 2.     11
 * 3.     21
 * 4.     1211
 * 5.     111221
 * 
 * 
 * 1 被读作  "one 1"  ("一个一") , 即 11。
 * 11 被读作 "two 1s" ("两个一"）, 即 21。
 * 21 被读作 "one 2",  "one 1" （"一个二" ,  "一个一") , 即 1211。
 * 
 * 给定一个正整数 n（1 ≤ n ≤ 30），输出报数序列的第 n 项。
 * 
 * 注意：整数顺序将表示为一个字符串。
 * 
 * 
 * 
 * 示例 1:
 * 
 * 输入: 1
 * 输出: "1"
 * 
 * 
 * 示例 2:
 * 
 * 输入: 4
 * 输出: "1211"
 * 
 * 
 */
#include<map>
#include<vector>
#include<string>
class Solution {
public:
    string countAndSay(int n) {
        vector<string> v;
        for(int i=0;i<n;i++){
            string vv = "";
            if(i==0){
                vv.push_back('1');
                v.push_back(vv);
                continue;
            }
            string tmp = v[i-1];
            int j=0;
            while(j<tmp.size()){
                int k = j;
                while(k<tmp.size()){
                    if(k == tmp.size()-1 || tmp[k] != tmp[k+1]){
                        char t = '0' + ((k-j+1));
                        vv.push_back(t);
                        vv.push_back(tmp[j]);
                        break;
                    }
                    else k++;
                }
                j = k +1;
            }
            v.push_back(vv);
        }
        return v[n-1];
    }
};

