/*
 * @lc app=leetcode.cn id=26 lang=cpp
 *
 * [26] 删除排序数组中的重复项
 */
class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        if(nums.size() == 0){
            return 0;
        }
        int i = 0, j = 0;
        while(i<nums.size()-1){
            if(nums[i] == nums[i+1]){
                i++;
            }
            else{
                nums[++j] = nums[++i];
            }
        }
        //size = j + 1;
        return j+1;
    }
};

